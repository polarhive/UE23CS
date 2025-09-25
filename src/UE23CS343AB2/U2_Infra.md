# Unit 2 - Big Data Infrastructures (Compute/Storage)

## Matrix Multiplication (Matrix-Vector Multiplication)

Matrix-vector multiplication is a critical operation in Big Data, often involving large, sparse matrices.

**1. Sparse Matrix Representation:**
Since large matrices (e.g., $n$ of order $10^{10}$) cannot fit in main memory (DRAM), they are stored in distributed file systems like HDFS. These matrices are often **sparse** (having a significant number of zero entries). To optimize storage and computation, only the non-zero values are stored.

* **HDFS Format:** Non-zero elements are stored as a separate record in CSV format.
* **Record Structure:** Each element is stored as: `<row_number, column_number, value>`.

**2. MapReduce Implementation (Assuming Vector $v$ fits in memory):**
The goal is to compute the resultant vector $x$ from the multiplication of matrix $MA$ (stored in HDFS) and vector $v$. Vector $v$ is typically shared by all mappers.

| Phase | Functionality | Key/Value Output |
| :--- | :--- | :--- |
| **Map** | Computes the partial product $ma_{ij} \cdot v_j$. | **Output:** $(i, ma_{ij} v_j)$, where $i$ is the index into the target vector where this value will contribute. |
| **Reduce** | Summating all the partial products associated with the same key $i$. | **Output:** $(i, \text{final value})$ (the entry $x_i$ in the resultant vector). |

## PageRank

PageRank is an algorithm used by search engines (like Google's initial implementation) to **compute the importance (page rank) of each Web page**.

**1. Motivation and Context:**
Early search engines faced **Term Spam**, where unethical users added terms multiple times to artificially mark a page as important. PageRank solves this by treating the web as a **directed graph** and analyzing the fraction of "random surfers" who end up at a particular page, indicating its importance.

**2. The Random Surfer Model:**
* **Transition Probability:** If a page (node) has $n$ out-links, the probability of a random surfer taking any single link is $1/n$.
* **Transition Matrix (M):** An $n \times n$ matrix where each entry represents the probability of transitioning from a source page (column) to a destination page (row).
* **Initialization:** The relative importance of each node is represented as an importance vector $v$. The initial guess, $v_0$, assumes equal chance for all pages, e.g., $1/4$ for a 4-node graph.

**3. PageRank as an Iterative Eigenvector Problem:**
PageRank can be modeled as finding the eigenvector $v$ of the transition matrix $M$ that satisfies the equation $v = M v$. This is solved using an iterative algorithm (Fixed Point Iteration).

* **Iteration:** The iterative step involves repeated matrix-vector multiplication:

$$
v_{i+1} = M v_i
$$

* **Convergence:** The loop continues until the difference between $v_i$ and $v_{i+1}$ (the error term) is small.
* **Result:** The final, converged vector $v$ contains the page ranks of the web graph nodes.

**4. MapReduce Implementation:**
Each iteration of the PageRank algorithm typically requires **one MapReduce step**.

* The intermediate estimate of $v$ from the MapReduce step is stored in HDFS.
* This file is then used as the input for the next MapReduce step (iteration).

## Issues with Hadoop

Hadoop 1.0 faced several limitations, prompting the development of YARN (MapReduce v2). Even with subsequent versions, certain limitations persist:

| Issue Category | Description |
| :--- | :--- |
| **Architecture & Scalability** | The Job Tracker in Hadoop 1.0 ran on a single machine, managing cluster resources, scheduling, and monitoring, limiting scalability and serving as a **single point of availability/failure**. |
| **Small File Problem** | Hadoop's design does not suit small data files (significantly smaller than the default 128MB HDFS block size). Too many small files cause problems for the **NameNode**, which holds filesystem metadata in memory. |
| **Processing Speed** | The framework generally supports **batch processing only**; it does not process streamed data, resulting in overall slower performance. MapReduce also requires scanning the entire input. |
| **Programming Model** | MapReduce is often too low-level for data analysis, requiring programs to be translated into a series of multiple Map and Reduce stages even for simple operations. This involves high complexity and lacks control, structure, and data types. |
| **Iteration and Efficiency** | There is **no native support for iteration**. Hadoop is inefficient for iterative processing (e.g., PageRank, Machine Learning) because **each iteration reads/writes data from/to persistent storage (disk/HDFS)**, resulting in significant overhead and higher communication cost. |

## Complexity of Big Data Algorithms – Communication Cost Complexity Model

When choosing an algorithm for Big Data, two main factors must be considered: **Communication Complexity** and **Wall Clock Time**.

### Communication Complexity (Cost Model)

Communication cost refers to the **volume of data** that is input to the different phases of the algorithm (e.g., input from disk, network reads).

*   **Why Communication?** Algorithms tend to be linear in data size, but **Network speed $\ll$ CPU speed** and **Disk speed $\ll$ CPU speed**. Therefore, the major time component in Big Data processing is often communication time.
*   **Total Complexity:** Roughly estimated as $O(r+s)$, where $r$ and $s$ are the sizes of the inputs read from disk or network.

### Wall Clock Time (Parallelism)

Wall clock time is the **total elapsed time** for the entire job to finish. It depends directly on the **parallelism** achievable by the algorithm.

*   Higher parallelism generally reduces wall clock time.

### The Trade-off

There is frequently a **trade-off** between communication complexity and wall clock time.

* **High Communication Cost, High Parallelism:** Sending one pair of data to each reducer leads to high communication cost but high parallelism, which may reduce wall clock time.
* **Low Communication Cost, Low Parallelism:** Doing everything on a single node results in no communication cost but very low parallelism, leading to high wall clock time.

The optimal Big Data algorithm often involves finding a solution in between these extremes. For instance, increasing the group size in a group-based algorithm increases communication complexity but reduces wall clock time by increasing parallelism.

## Case Study: HBase

**HBase** is a **column-family database** (NoSQL) built on the Bigtable data model. It leverages HDFS for persistent storage.

### Advantages and Use Cases (Addressing HDFS/Hive Limitations)

HBase is designed to overcome limitations of HDFS and Hive.

* **Fast Record Lookup:** Good for low-latency retrieval of individual records.
* **Arbitrary Writes/Updates:** Supports **record level insertion** and **updates** (by creating new versions of data).
* **Data Flexibility:** Supports unstructured/semi-structured data.

### Data Model

HBase schema consists of Tables, which are horizontally partitioned into **Regions**.

* **Table:** A collection of rows sorted on a **RowID** (Row Key).
* **Row Key:** A byte array serving as the primary key for the table, indexed for **fast lookup**.
* **Column Family (CF):** A collection of variable number of columns. CFs are part of the schema.
* **Dynamic Columns:** Unlike traditional databases, column names are **not part of the schema**; they are encoded inside the cells, allowing different cells to have different columns.
* **Cell:** The unit of storage, a combination of {row key, column, timestamp/version} tuple as a byte array.

### Architecture (Master-Slave)

HBase operates on a Master-Slave architecture.

* **MasterServer:** Assigns regions to RegionServers, detects failures (using ZooKeeper), monitors slaves, load balances regions, and supports administrative functions (schema changes, table creation).
* **RegionServers (Slaves):** Store and manage data within assigned Regions. They serve data for reads and writes and decide on region splitting. They are similar to DataNodes in HDFS.
* **Regions:** Split parts of tables (horizontal range partitioning) spread across RegionServers. The **META Table** keeps track of which regions are located on which RegionServer.
* **Persistence:** HBase stores data in **HFiles** (sorted KeyValues on disk) and uses a **Write Ahead Log** (WAL) on disk for recovery.

## Case Study: Cassandra

**Cassandra** is an open-source, **columnar NoSQL database** designed for handling extremely large, non-relational datasets. It was built by Facebook and inspired by Amazon’s Dynamo DB and Google’s Bigtable.

### Architecture (Peer-to-Peer)

Cassandra utilizes a **peer-to-peer distributed system** where **all nodes play the same role**.

* **No Master Node:** Unlike HBase, Cassandra does not rely on a single Master.
* **Ring Topology:** Cassandra nodes are organized as a **Ring**. Data distribution and failure detection are handled by the nodes themselves.
* **Scalability:** It supports **elastic scalability**, allowing increases in node count with linear performance scaling.
* **Data Persistence:** It uses its **local persistence (storage) engine** and does **not rely on HDFS**.

### Advantages and Characteristics

* **Fast Writes:** Described as fast and easily scalable with write operations spread across the cluster.
* **High Availability:** Prevention of data loss is supported by replication across multiple nodes.
* **Data Flexibility:** Accommodates structured, semi-structured, and unstructured data, and can dynamically accommodate changes to data structures.

### Data Model

The data model is similar to Bigtable/HBase but organized differently.

* **Partitioning:** Data is organized into **partitions**, each identified by a **partition key**.
* **Columns:** The basic unit of storage, consisting of a name-value pair.
* **Timestamp:** Each column is stored with a timestamp used for resolving write conflicts and data expiration.
* **Column Families (CFs):** A collection of similar rows. Rows within a CF do not need to have the same columns, and columns can be added dynamically.
* **Super Columns (Deprecated in later versions):** A special column type where the value is a map of subcolumns (regular columns), allowing a single level of nesting.
* **Query Language:** Uses a specific query language called **CQL** (Cassandra Shell), which is richer in functions than the HBase Query language.

### Limitations

* **ACID Transactions:** Cassandra is not the best solution for systems requiring **ACID transactions** for writes and reads.
* **Aggregation:** The database does not aggregate data using queries (e.g., SUM or AVG); this must be done on the **client side** using retrieved data.
* **Schema Flexibility Risk:** Because column family design is closely tied to anticipated query patterns, Cassandra is not ideal for early prototypes where query patterns may change frequently.
