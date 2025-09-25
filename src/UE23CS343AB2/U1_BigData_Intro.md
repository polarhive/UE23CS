# Unit 1 - Introduction to Big Data

## Introduction and Definition

Big Data refers to data whose **scale, diversity, and complexity require new forms of processing**. This processing utilizes **new architectures, techniques, algorithms, and analytics** to manage the data and enhance decision-making. The ultimate goal is to **extract value and hidden knowledge or insights** from this data.

It is important to note that **there is no one standard single definition** for Big Data.

### Characteristics of Big Data (The V's)

Big Data is generally characterized by several dimensions, including Volume, Variety, Velocity, and Veracity:

|Characteristic|Description|Traditional Data Contrast|
|:--|:--|:--|
|**Volume**|Refers to the massive scale of data generated. The total amount of data in the world grew from 4.4 zettabytes in 2013 to a projected **44 zettabytes by 2020**.|Data collection often relied on **manual entry**, while Big Data collection is **automated**.|
|**Variety**|The complexity of Big Data arises from the **various formats, types, and structures** it encompasses, such as text, numerical data, images, audio, video, time series, and social media data.|Traditional data is typically characterized by a **fixed format and schema**.|
|**Velocity**|Pertains to the speed at which data is generated, collected, and processed.|Traditional approaches use elaborate **ETL (Extract, Transform, Load) procedures** run in batches, often daily, and **are not real-time**.|
|**Veracity**|This refers to the **messiness or trustworthiness** of the data. Accuracy is hard to control due to factors common in unstructured data, such as **hashtags, typos, and abbreviations**.|Traditional data is usually **clean and consistent** because it is often manually entered into fixed fields, leading to much lower error chances and higher reliability.|

## Challenges and Opportunities with Big Data

### Challenges (Pitfalls)

One major challenge involves **Gaps in the data**.

- **Selection Bias:** This occurs when the data used for a study is **not a representative sample** of the larger population. This can lead to skewed or incorrect conclusions.
    - _Example:_ A Rutgers University study examining emergency decision-making during Hurricane Sandy using tweets exhibited significant selection bias because most tweets came from a single location: **Manhattan**. Using this data to assess the hurricane's overall impact would lead to the incorrect conclusion that Manhattan was the most affected area.
- **Missing Data/Negative Results:** In fields like medicine, missing data is a constant challenge, and it is known that **"negative results" are more likely to go missing**. This results in a biased sample that may **overestimate the benefits of treatments**.

### Opportunities

Big Data necessitates new architectures, techniques, algorithms, and analytics to **extract value and hidden knowledge or insights** and to **manage and enhance decision making**.

- **Error Estimation:** Big Data utilizes a purely **empirical** approach for error estimation, based on observation and data rather than theoretical analysis. Data is divided into a **training set** (for algorithm development) and a **testing set** (to measure accuracy/error on unseen data). This is the standard way to compare different analytics algorithms.

## Data Intensive Scientific Discovery and the Role of Big Data

While the sources do not specify a "scientific discovery" section, the underlying principles are evident in how large-scale data processing is applied.

- **Big Data Pipeline:** The general process involves identifying data, **data ingestion/acquisition**, **data storage**, **data processing**, and finally, **data consumption** through analytics.
- **Modeling Language Translation:** The Big Data approach contrasts with traditional linguistic models. Instead of building complex rule-based models, the Big Data approach makes **no attempt to understand language** but rather gathers millions of sentences and their translations (a **parallel corpus**) to **build a statistical model**.

## History

The foundation of Big Data is a **fusion of established statistics and the newer field of computer science**.

A significant moment, known as **The Data Deluge**, occurred in the 21st century when the volume and speed of data generation exploded. This massive, unmanageable volume of data necessitated the transformation of traditional data analysis methods into what is now known as "Big Data".

## Google File System (GFS)

The Google File System (GFS) is a core component that enabled Google's large-scale data processing.

### Architecture and Key Concepts

- **Centralized Architecture:** A GFS cluster has a simple, centralized design consisting of a **single Master node** and multiple **Chunk Servers**.
- **Master Node:** Stores all file system metadata, including the namespace, access control information, and the mapping of files to chunks.
- **Chunk Servers:** Store the actual data chunks on local disks.
- **Chunk Size:** GFS uses a large, fixed chunk size of **64 MB**. This design choice minimizes client-master interaction during sequential reads/writes and reduces the amount of metadata the master must manage.
- **Replication:** Data is replicated across multiple chunk servers (default of three) to provide fault tolerance and increase read throughput.

### Operations and Fault Tolerance

- **Read/Write Operations:** Clients query the master for chunk locations, then communicate **directly with the chunk servers**.
- **Atomic Record Appends:** Designed to handle concurrent writes, allowing multiple clients to append to the same file simultaneously.
- **Fault Detection:** The Master sends regular **heartbeat messages** to Chunk Servers.
- **Data Integrity:** Each Chunk Server uses **checksums** to detect data corruption before returning data. If a mismatch occurs, the Master arranges to clone a replica.
- **Scalability:** The system minimizes the load on the Master and is easily scalable by adding more Chunk Servers.

## Map Reduce – Storage (HDFS)

**HDFS (Hadoop Distributed File System)** is the open-source implementation based on GFS.

### HDFS Introduction

- HDFS is designed to store **very large files efficiently**.
- It operates on clusters of **commodity hardware**.
- It is optimized for **high throughput data processing** on big data.
- Its design targets **write-once, read-many-times** access patterns.

### HDFS Architecture (Master-Slave)

HDFS separates metadata management from data storage.

- **NameNode (Master Daemon):**
    - Maintains and manages DataNodes.
    - Stores file system metadata (block locations, permissions) on local disk in two files:
        - **Fsimage:** Contains the complete namespace of the Hadoop file system since its creation.
        - **Edit log:** Contains all recent changes performed to the file system namespace.
    - Receives **heartbeat and block reports** from all DataNodes.
- **DataNodes (Slaves/Workhorses):**
    - These are inexpensive commodity hardware.
    - They store blocks of a file and are responsible for serving client read/write requests.
    - They perform block creation, replication, and deletion based on instructions from the NameNode.
    - Send heartbeats (health reports) and block reports (list of blocks contained) to the NameNode.
- **Secondary NameNode (Helper Node):**
    - Performs housekeeping backup (it is **not a hot standby**).
    - Helps the NameNode by downloading and merging the Fsimage file and edit logs, updating the Fsimage, and sending the updated image back to the NameNode, enabling the NameNode to start faster.

### HDFS Blocks

- HDFS blocks are much larger than typical disk blocks (512 bytes).
- The HDFS block size is typically **128MB** (in v2).
- Files are broken into block-sized chunks and stored as independent units. A file smaller than a block does not occupy a full block's worth of storage.

### HDFS High Availability (HA)

Since HDFS 2.x, the goal is to make the NameNode resilient to failure and recover quickly.

- **Configuration:** Active-Standby configuration is used.
- **Edit Logs:** Stored on **shared storage** so the Standby NameNode can take over immediately.
- **Failover Controller:** Handles the transition from active to standby. It uses **ZooKeeper** for failure detection and to ensure that only one NameNode is active.

### HDFS Limitations

HDFS does not score well for several types of applications:

- **Low Latency Data Access:** HDFS's high throughput may come at the cost of latency. It is not suitable for applications requiring low-latency access (in the tens of milliseconds range).
- **Lots of Small Files:** The NameNode holds all file system metadata in memory. Too many small files limits the capacity of the file system based on the NameNode's memory.
- **Arbitrary Modifications:** Files in HDFS may only be written to by a **single writer**, and writes are always made at the end of the file. There is **no support for multiple writers** or modifications at arbitrary offsets in the file.
- **POSIX Compliance:** It is not POSIX compliant, meaning a separate client is needed, and you cannot mount it and use standard file system commands.

## Computation Model (Map Reduce)

### What is MapReduce?

MapReduce originated at Google and is the **central processing component of the Hadoop framework**. It is a programming model for processing vast amounts of data in a distributed environment.

### MapReduce Principles

1. **Parallel Processing:** Enables the parallel execution of data processing across multiple commodity servers in a distributed environment, boosting performance.
2. **Divide and Conquer:** Partitions a large problem into smaller subproblems. Workers process these sub-problems in parallel and produce intermediate results which are then combined for the final result.
3. **Data Locality:** A fundamental principle where the processing logic is moved to where the data is already stored, significantly reducing expensive network traffic.
4. **Abstraction:** The programmer writes code as if for a single machine, while the framework handles the distributed execution and hides system-level details like fault tolerance, I/O scheduling, locking, and race conditions.

### MapReduce Functions

- **Map:**
    - Accepts an input key/value pair.
    - Processes the pair to generate **intermediate key/value pairs**.
    - Sorts all key/value pairs before sending them to the reducer.
- **Reduce:**
    - Accepts intermediate key/value pairs.
    - Merges all intermediate values associated with the same key.
    - Runs only after **all Map tasks are finished**.
- **Partitioning Function:** Ensures that **all similar keys are aggregated at the same reducer**. By default, this is typically `hash(key) mod R` (where R is the number of reducers).

## Map Reduce Architecture (Flow)

1. **Job Submission:** The user submits the job, including the input data, MapReduce program, and configuration.
2. **Input Splitting:** The input data is divided into smaller chunks called **input splits** (logical partitions of data). The **optimal split size is the size of the HDFS block (128MB)**.
3. **Map Tasks:** One Map task is executed per split, running in parallel. Map tasks attempt to run on the node where the input data resides (**data locality**).
4. **Map Output:** The output of the Map task is written to the **local disk** of the node where the mapper runs, not HDFS, because it is temporary and discarded after the reduce stage.
    - **Combiner (Optional):** A combiner function can be run on the mapper before the reduce stage to **combine multiple map outputs**, reducing network transfer during shuffling.
5. **Shuffling and Transfer:** Since Reduce tasks do not benefit from data locality (their input comes from all mappers), the sorted map outputs must be transferred across the network to the node running the Reduce task. The partitioning function ensures keys are correctly routed.
6. **Reduce Tasks:** The reducer merges data from different mappers and applies the user-defined reduce function.
7. **Reduce Output:** The final output of the reduce stage is normally stored in **HDFS** for reliability.

## Overview of Hadoop Ecosystem

The Hadoop ecosystem is a toolkit of interdependent components for Big Data.

|Tool|Purpose|
|:--|:--|
|**Pig**|A high-level scripting language (Pig Latin) used to **simplify analysis** and process data without complex code, providing an abstraction over MapReduce.|
|**Hive**|Data warehousing infrastructure that enables **SQL-like queries (HiveQL)** to analyze structured data in Hadoop.|
|**Sqoop**|Used to **move data** efficiently between structured databases (like RDBMS) and Hadoop (HDFS, Hive, HBase).|
|**Flume**|Used to **ingest logs** and collect large streams of event data into Hadoop.|
|**Oozie**|A workflow director designed to **automate jobs** and schedule/manage complex, interdependent workflows defined as Directed Acyclic Graphs (DAGs).|
|**HBase**|A **NoSQL database** providing real-time access for fast read/write operations on massive datasets.|

## Apache Flume as a Data Ingestion and Log Aggregator Tool

Flume is a service/tool for **effectively collecting, aggregating, and moving large amounts of streaming data** into a centralized store like HDFS or HBase. It is necessary because data sources continuously generate data (like web server logs and events), and simply using Hadoop `put` commands for transfer would lead to delays and reliability challenges.

### Flume Components

Flume operates using agents, which are independent daemon processes (JVM).

- **Source:** Receives data from the generator and transfers it to one or more channels in the form of **Flume Events**.
- **Flume Event:** The basic unit of data transport, containing a payload of a byte array.
- **Channel:** A **transient store** that acts as a bridge between sources and sinks. It receives events from the source and buffers them until consumed by sinks (e.g., JDBC channel, File system channel).
- **Sink:** Receives data from the channels and stores it in centralized destinations like HDFS or HBase.

## YARN Introduction

**YARN (Yet Another Resource Negotiator)** was introduced in MapReduce v2 (2010). It was developed to address limitations in Hadoop 1.0, where the single **Job Tracker** managed cluster resources, scheduling, and monitoring, leading to scalability and availability issues.

YARN splits the Job Tracker's responsibilities into specialized components:

- **Resource Manager (RM):** The master component responsible for **managing cluster-wide resources**. It arbitrates resources among all applications in the system.
- **Application Master (AM):** Manages the **lifecycle of a single application**. It negotiates appropriate resource containers from the scheduler and tracks/monitors the progress of the containers.
- **Node Manager (NM):** The slave component running on each machine. It is responsible for launching application containers and monitoring resource usage.
- **Container:** The unit of allocation, incorporating resources such as memory, CPU, and disk.

YARN manages resources for individual Hadoop jobs and provides the infrastructure for complex orchestrators like Oozie to connect and control jobs on the cluster.

## Case Study: HIVE

Hive is the open-source **data warehouse infrastructure system** designed to process **structured data** in Hadoop. It sits on top of MapReduce and Hadoop.

### Key Features

- **HiveQL (HQL):** Users query and manage large datasets using HiveQL, a language that is very similar to standard SQL.
- **MapReduce Translation:** Hive translates a HiveQL query into **one or more MapReduce jobs** (or Spark jobs) for execution on the Hadoop cluster. This removes the need for expertise in Java or low-level MapReduce programming.
- **Metastore:** A central repository storing the **schema (metadata)** for the data in HDFS, allowing Hive to interpret HDFS files as structured tables. The Metastore also stores information about columns, types, and the serializers/deserializers (SerDe) used to read and write data.

### Hive Data Model

Hive data, typically stored as HDFS files, is categorized into three levels:

1. **Table:** Similar to a table in a relational database, mapped to an HDFS directory.
2. **Partition:** Tables are organized into partitions based on a column or key, implemented as an **HDFS subdirectory**.
3. **Bucket:** A subdivision of a partition, divided based on a hash function of a specified column to **enhance query performance**.

### Limitations

- Hive is **not capable of handling real-time data**.
- It is **not a full database**; it does not provide functionality for updating, altering, or deleting records.
- It is **not designed for Online Transaction Processing (OLTP)**.
- Hive queries generally have **high latency**.

## Google Big Query

Google BigQuery is a powerful, serverless, enterprise-scale data warehouse solution leveraging Google's massive infrastructure.

### Architecture and Scale

- BigQuery's unique architecture **decouples storage and compute** for petabyte-scale analysis.
- It relies on core Google infrastructure technologies, including **Borg, Colossus, Jupiter, and Dremel**.
- It provides managed disaster recovery by relying on **cross-region dataset replication**.

### AI and Data Governance

- **BigQuery ML:** Users can **create and run ML models using familiar SQL** directly within BigQuery. It supports pre-trained models, Vertex AI-trained models, and custom models.
- **Generative AI:** It supports advanced capabilities like multimodal data analysis (image annotation, audio transcription) and generative AI tasks (text summarization).
- **AI Agents (Gemini in BigQuery):** Provides AI-powered experiences and automation, allowing users to find, join, and query datasets using **natural language prompts** in the data canvas.
- **Contextual Governance:** Governance is powered by **Dataplex Universal Catalog**, integrating capabilities such as automatic metadata harvesting, data profiling, data quality, and lineage.

### Open Source Integration

BigQuery allows users to run **serverless Spark alongside SQL workloads** with unified security and metadata. It also supports managed Apache Iceberg tables powered by BigLake for advanced analytics and streaming use cases.

---

[[HDFS]]

> From the map and reduce primitives present in lisp

![[mapreduce-osdi04.pdf#page=1&selection=74,10,82,12|mapreduce-osdi04, page 1]]