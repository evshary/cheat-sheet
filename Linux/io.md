# I/O models

For the I/O models, we can classify as the following

* Blocking / Non-Blocking:
  * The application needs to wait for the result.
  * The application can do other things first.
* Synchronous / Asynchronous (The definition of the graph):
  * sync asks kernel to process I/O one by one.
  * async can ask kernel to process all the I/O at one time.
* Synchronous / Asynchronous (another definition):
  * sync: Do the thing by ourselves.
  * async: Someone does this for us. We just need to wait for the result.
* Reactor / Proactor:
  * Reactor: I/O multiplexing, like select / poll
  * Proactor:
    * `aio`: However, it's simulated while OS creates another thread to serve.
    * `io_uring`: Supported by the Linux from 2019. Applications provide a buffer. Then OS can put the data into the buffer and notify applications. This can reduce the copy and system calls by providing a consistent API in Linux.

![image](https://user-images.githubusercontent.com/456210/151485061-16345aef-69d2-4545-a2f6-1d846aa32174.png)

* Sync+Blocking:

![image](https://user-images.githubusercontent.com/456210/151485173-22c79333-31e5-4219-be30-214628513f9d.png)

* Sync+NonBlocking

![image](https://user-images.githubusercontent.com/456210/151485242-f46352a3-ede1-4773-854d-7551d43a9f4e.png)

* Async+Blocking:
  * Not everyone has the same opinion here.
  * Async: We still need to read the data by ourselves.
  * Blocking: In fact, we use non-blocking read here.

![image](https://user-images.githubusercontent.com/456210/151485287-f2d09284-003d-43f8-8e06-5ad40f6b2c61.png)

* Async+NonBlocking:

![image](https://user-images.githubusercontent.com/456210/151485301-431964c9-72b5-4eb8-aefc-d3c00e4ff776.png)

## Referenc

* [Study Notes - I/O Models](https://rickhw.github.io/2019/02/27/ComputerScience/IO-Models/)
* [深入理解 Linux 的 epoll 機制](https://www.readfog.com/a/1641834490361909248): The article tells us why epoll is better than select & poll.
* io_uring:
  * [Why you should use io_uring for network I/O](https://developers.redhat.com/articles/2023/04/12/why-you-should-use-iouring-network-io)
  * [Building a io_uring based network scanner in Rust](https://www.synacktiv.com/en/publications/building-a-iouring-based-network-scanner-in-rust)
  * [compio](https://compio.rs/docs/preface): Rust async utilizing io_uring
