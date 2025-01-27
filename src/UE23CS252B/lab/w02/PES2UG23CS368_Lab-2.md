# Understanding Persistent and Non-persistent HTTP Connections

**UE23CS252B: Lab_2**

> Name: Nathan Matthew Paul
> SRN: PES2UG23CS368
> Section: 4F

> [!Question]
> Create a web page with 10 embedded images. Each image should be of minimum 2 MB size. Configure your browser (Firefox) with following settings (each setting requires repeat of experiment).
> - Non persistent connection
> - 2 persistent connections
> - 4 persistent connections

---

# Images (client)

![[images.png]]

 <div style="page-break-after: always;"></div>

# No Persist

![[p0.png]]

# Persist

## max limit: 2

![[p2.png]]

## max limit: 4

![[p4.png]]

---

# Observation

| Trial No        | Start Time  | End Time    | Diff        |
| --------------- | ----------- | ----------- | ----------- |
| P0 (no persist) | 0.001090967 | 0.250237750 | 0.249146783 |
| P2              | 0.016769327 | 0.240196479 | 0.223427152 |
| P4              | 0.020381928 | 0.110621473 | 0.090239545 |

## Conclusion

> As the limit of maximum persistent connections increases, the time taken to load the images on the client **reduces**. For 10 images, the best configuration is **4 persistent connections**, as it achieves the fastest load time while utilizing efficient HTTP connection management.