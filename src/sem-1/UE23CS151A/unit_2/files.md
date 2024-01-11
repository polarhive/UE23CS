# python file handling

1. Text-files
2. Binary-files
3. CSV-files

> x to create a new file

## Read only mode

> r

file should exist before existing

## Write only mode

> w

It will overwrite any previous data

## Append mode

> a

Add content at the end of the file

### keyword: with

```python
with open('filename.txt', 'mode') as fileobject:
    ## context manager will take care of closing the file
```

## Methods

```python
fileob=open("filename.txt", 'r')
close(fileob)

fileob.read()
fileob.readline()
fileob.readlines()

fileob.write("hello")
fileob.writeline("one line of data")
fileob.writeline(list)

fileob.tell()
Return the current stream position.

fileob.seek(offset,whence)

  0: start of the stream (the default); offset should be zero or positive
  1: current stream position; offset may be negative
  2: end of the stream; offset is usually negative



```