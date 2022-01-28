# I/O models

For the I/O models, we can classify as the following

* Synchronous/Asynchronous: sync asks kernel to process I/O one by one, while async can ask kernel to process all the I/O at one time.
* Blocking/Non-Blocking: application needs to wait for the result / can do other things first.

![image](https://user-images.githubusercontent.com/456210/151485061-16345aef-69d2-4545-a2f6-1d846aa32174.png)

* Sync+Blocking:
![image](https://user-images.githubusercontent.com/456210/151485173-22c79333-31e5-4219-be30-214628513f9d.png)

* Sync+NonBlocking
![image](https://user-images.githubusercontent.com/456210/151485242-f46352a3-ede1-4773-854d-7551d43a9f4e.png)

* Async+Blocking:
![image](https://user-images.githubusercontent.com/456210/151485287-f2d09284-003d-43f8-8e06-5ad40f6b2c61.png)

* Async+NonBlocking:
![image](https://user-images.githubusercontent.com/456210/151485301-431964c9-72b5-4eb8-aefc-d3c00e4ff776.png)


# Reference
* [Study Notes - I/O Models](https://rickhw.github.io/2019/02/27/ComputerScience/IO-Models/)
