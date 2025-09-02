# UE23CS343AB2 - Hands-on-1 Submission

> Course Name: Big Data
> Submission Date: 2025-09-01

> **Name: Nathan Matthew Paul**
> **SRN: PES2UG23CS368**
> Section: F

1. Hadoop installation **(run hadoop version)** and All daemons running **(run jps)**

![[Pasted image 20250901231506.png]]

2. Uploading the text file from local to HDFS **(hdfs dfs -mkdir .... & hdfs dfs -put ....)**

![[Pasted image 20250901232117.png]]

3. Running MapReduce JAR commands **(hadoop jar $HADOOP_HOME ...)**

![[Pasted image 20250901232349.png]]

![[Screenshot 2025-09-01 at 23.23.55.png]]

4. MapReduce code output **(hdfs dfs -cat /example/output/part-r-00000)** 

![[Screenshot 2025-09-01 at 23.24.32.png]]

5. Simulating MapReduce in Local System **(cat input.txt | ./mapper.py | sort | ./reducer.py)**

## Example 1

![[Screenshot 2025-09-01 at 23.28.00.png]]

Output

![[Screenshot 2025-09-01 at 23.26.41.png]]

## Example 2

![[Pasted image 20250901233022.png]]

Output

![[Pasted image 20250901233121.png]]

---