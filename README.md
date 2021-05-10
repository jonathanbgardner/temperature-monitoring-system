# Environment Monitoring System
CS 4287 Cloud Computing Final Project

An environment monitoring system consisting of embedded systems and cloud-based components. 

This repository contains a .csv file, DB.csv, which contains some of the initial temperature data from our environment monitoring system. mapreduce.py runs a MapReduce operation on this data. You can run it with:
```python3 mapreduce.py```

Run 
```python3 consumer.py```
on a Virtual Machine or cluster to start up a consumer that will monitor the Kafka streaming service on port 9092 to accept any incoming data and consume it. Don't forget to replace the static IP with your own in order to use the file. 

Embedded system files will be added in an upcoming push.