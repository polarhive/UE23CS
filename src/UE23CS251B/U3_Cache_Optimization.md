# Caching

>  The principle of locality, presented in the first chapter, says that most programs do not access all code or data uniformly. Locality occurs in time (temporal locality) and in space (spatial locality).

> [!Quote]
>
> >  A total peak demand bandwidth of 409.6 GiB/s! This incredible bandwidth is achieved by multiporting and pipelining the caches; by using three levels of caches, with two private levels per core and a shared L3; and by using a separate instruction and data cache at the first level. In contrast, the peak band- width for DRAM main memory, using two memory channels, is only 8% of the demand bandwidth (34.1 GiB/s). Upcoming versions are expected to have an L4 DRAM cache using embedded or stacked DRAM

## Fetch Cycle

- When a word is not found in the cache, the word must be fetched from a lower level in the hierarchy (which may be another cache or the main memory) and placed in the cache before continuing.
- Multiple words, called a block (or line), are moved for efficiency reasons, and because they are likely to be needed soon due to spatial locality.
- Each cache block includes a tag to indicate which memory address it corresponds to. A key design decision is where blocks (or lines) can be placed in a cache.
- The most popular scheme is set **associative**, where a set is a group of blocks in the cache. A block is first mapped onto a set, and then the block can be placed anywhere within that set. Finding a block consists of first mapping the block address to the set and then searching the set—usually in parallel—to find the block. The set is chosen by the address of the data:
- **Block address $\%$ Number of sets in cache**

## Direct Mapping

A direct-mapped cache has just **one block per set** (so a block is always placed in the same location), and a fully associative cache has just one set (so a block can be placed anywhere). Caching data that is only read is easy because the copy in the cache and memory will be identical. Caching writes is more difficult; for example, how can the copy in the cache and memory be kept **consistent**? There are two main strategies.:

- A write-through cache updates the item in the cache and writes through to update main memory.
- A write-back cache only updates the copy in the cache. When the block is about to be replaced, it is copied back to memory.

Both write strategies can use a write buffer to allow the cache to proceed as soon as the data are placed in the buffer rather than wait for full latency to write the data into memory

### Cache Miss

> Miss rate is simply the fraction of cache accesses that result in a miss—that is, the number of accesses that miss divided by the number of accesses

Therefore some designers prefer measuring misses per instruction rather than misses per memory reference (miss rate). These two are related:

![[Pasted image 20250305105504.png]]

### Cache Hit

## The 3 C's

- **Compulsory**: The very first access to a block cannot be in the cache, so the block must be brought into the cache. Compulsory misses are those that occur even if you were to have an infinite-sized cache.
- **Capacity**: If the cache cannot contain all the blocks needed during execution of a program, capacity misses (in addition to compulsory misses) will occur because of blocks being discarded and later retrieved.
- **Conflict**: If the block placement strategy is not fully associative, conflict misses (in addition to compulsory and capacity misses) will occur because a block may be discarded and later retrieved if multiple blocks map to its set and accesses to the different blocks are intermingled.

## Associative Mapping

- No tags
- No words

> [!Question] Map Cache
> Of size: 16KB
> Block Size: 256B
> Main Memory: 128KB
> Find the number of bits in the tag?
>
> Address size = $17$
> Word size = $8$
> Tag size = $9$

> [!Question] Fully Associative Map Cache
> Of size: 512KB
> Block Size: 1KB
> Tag size = 19 bits
> Find the size of main memory?
>
>= 128 MB

> [!Question] Fully Associative Map Cache
> Block Size: 4KB
> Main Memory: 16GB
> Find the number of bits in the tag?
>
> = 9

> [!Question] Two Way set-associative cache
> Size: 16KB
> Block Size: 256B
> Main Memory: 128KB
> Find the number of bits in the tag?
>
> $No of lines in the Cache=\frac{Cache size}{Block Size}$
> $= \frac{2^{14}}{2^8} = 64\ lines, = 2^6$
> $No of sets = \frac{2^6}{2}=2^5$

> [!Question] Consider an 8 way set-associative cache
> Size: 512KB
> Block Size: 1KB
> Tag: 7 bits
> Find size of Main Memory?
>
> 8 KB

> [!Question] Consider a 4 way set-associative cache
> Block Size: 4KB
> Main Memory: 16GB
> Tag: 10 bits
> Find size of Cache memory?
>
> 64KB

> [!Question] Consider an 8 way set-associative cache
> Tag: 10
> Cache: 512KB
>
> Find the size of main memory?
>
> Cache Memory size = No of sets on the cache x No of lines per set x Line size
>
> | Tag | Set | Word |
> | --- | --- | ---- |
> | 10  | x   | y    |
>
> Cache = 512KB = $2^{19}$ = $2^{x} \times 2^3 \times 2^y$
> $x+3+y = 19$
> $x+y = 16$
> $10+x+y=10+16=26$
> MM = $2^{26} \times 2^6 \times 2^{20}$

> [!Question] Consider a 4 way set associative cache
> Main memory: 64MB
> Tag: 10 bits
> Find the size of cache memory?
>
> | Tag | Set | Word |
> | --- | --- | ---- |
> | 10  | x   | y    |
> >
> > spans 26
>
> $x+y=26-10=16$
> Cache Memory size = No of sets on the cache $\times$ No of lines per set $\times$ Line size
> Cache = 512KB = $2^{19}$ = $2^{x} \times 2^2 \times 2^y$
> $2^{2+x+y}=2^{18}\times = 2{8} \times 2{10}$

> [!Question] A cache memory unit of $n$ words and blocksize $b$ words

> If it is a direct mapped cache?
> Tag: 10 bits
>
>> If the cache is now designed as a $16$ bay set-associative cache, what is the new length of the tag field?

# Replacement Algorithms

## LRU: Least Recently Used

> [!Question] Consider 8 cache blocks
> If the order is 3, 5, 2, 8, 0, 6, 3, 9, 16, 20, 17, 25, 18, 30, 24, 2, 63, 5, 82, 17, 24

### Cache Table

| 3 mod 8 -> | 3   |
| ---------- | --- |
| 5 mod 8 -> | 5   |
| 2 mod 8 -> | 2   |
| 0 mod 8 -> | 0   |
| 6 mod 8 -> | 6   |

> [!Question] Fully Associative cache with 8 cache blocks
> The memory block requests
>
> 4, 3, 25, 8, 19, 6, 25, 8, 16, 35, 45, 22, 8, 3, 16, 25, 7
> If LRU is used: which line contains memory block 7?

> [!Question] Set associative 4-way mapping with:
> 16 Cache blocks
> If LRU is used, which block will not be present in cache? Calculate the HIT/MISS ratio

> [!Question] Set associative cache 2-way
> Total 4 blocks
> LRU replacement policy
> Find the number of cache misses for the following sequence?
> 8, 12, 0, 12, 8?

| 8 mod 2  | 0   |
| -------- | --- |
| 12 mod 2 | 0   |
| 0 mod 2  | 8/0 |
| 12 mod 2 | 12  |
| 8 mod 2  | 8/0 |

> [!Question] Consider a cache which has:
> 4 blocks
> Seq: 5, 12, 13, 17, 4, 12, 13, 17, 2, 13, 19, 13, 43, 61, 19
> What is the HIT ratio? for the following cache replacement algorithms?
> 1. FIFO
> 2. LRU
> 3. Direct Mapping
> 4.  Two way set associative cache with LRU

| Step | Address | Cache State      | Hit/Miss         |
| ---- | ------- | ---------------- | ---------------- |
| 1    | 5       | [5]              | Miss             |
| 2    | 12      | [5, 12]          | Miss             |
| 3    | 13      | [5, 12, 13]      | Miss             |
| 4    | 17      | [5, 12, 13, 17]  | Miss             |
| 5    | 4       | [12, 13, 17, 4]  | Miss (evicts 5)  |
| 6    | 12      | [12, 13, 17, 4]  | **Hit**          |
| 7    | 13      | [12, 13, 17, 4]  | **Hit**          |
| 8    | 17      | [12, 13, 17, 4]  | **Hit**          |
| 9    | 2       | [13, 17, 4, 2]   | Miss (evicts 12) |
| 10   | 13      | [13, 17, 4, 2]   | **Hit**          |
| 11   | 19      | [17, 4, 2, 19]   | Miss (evicts 13) |
| 12   | 13      | [4, 2, 19, 13]   | Miss (evicts 17) |
| 13   | 43      | [2, 19, 13, 43]  | Miss (evicts 4)  |
| 14   | 61      | [19, 13, 43, 61] | Miss (evicts 2)  |
| 15   | 19      | [19, 13, 43, 61] | **Hit**          |

- Total **Hits: 6**
- Total **Accesses: 15**

**Corrected Hit Ratio (FIFO) = 6/15 = 40.0%**

---

> [!Question] Consider a 2-way SA mapped cache with 8 cache blocks (0-7)
> LRU replacement policy. If the memory block requests are in the order 4, 3, 25, 8, 19, 6, 25, 8, 16, 35, 45, 22, 8, 3, 16, 25, 7

---

# Write Stratergies

## Cache Read

- Data in Cache:
- Not in Cache
	- Loadthrough (Early Restart) Forwards the word as the cache is being filled
	- Fill Cache (Forward the word)

## Cache Write

- Data in Cache
	- Writethrough update: main memory as well as cache
	- Write Back: cache only until the block is flushed
- Not in Cache
	- Write Allocate: Brings to cache and updates it
	- Write No Allocate: Update only

Tag is not matching.

---

> [!Important]
>
> $CPU\ execution\ time = Base\ CPI + CPI\ Stall + Memory\ stalls$

> [!Question] Assume that 33% of the instruction in a program are data accesses. The cache hit ratio is 97 and the hit time is one cycleb but the miss penalty is 20 cycles.
> Memory stall cycles =