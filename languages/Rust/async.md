# async

## Pin & Unpin

* [Rust 自引用结构、Pin 与 Unpin](https://zhuanlan.zhihu.com/p/600784379)
  * For self-referenced object, we need to ensure objects can't be moved.
  * Pin trait will stop moving struct if it's not Unpin. (!Unpin)
  * Only `Future` and `PhantomPinned` are !Unpin.
  * Include `PhantomPinned` if you don't want your struct to be moved.
  * We can use `Pin::new_unchecked` or `unpin!` to pin the struct to the stack.
* [Rust Pin、projections 与 pin-project](https://zhuanlan.zhihu.com/p/601775911)

## Reference

* Basic introduction:
  * [Rust Async 1- 異步編程的概念](https://www.readfog.com/a/1666736268025892864)
  * [Rust Async 2- 同步、多線程、異步的例子](https://www.readfog.com/a/1666818509749981184)
  * [Rust Async 3- 繼續理解 Async](https://www.readfog.com/a/1667010704884994048)
  * [Rust Async 4- 理解 Future](https://www.readfog.com/a/1667010728788332544)
  * [Rust Async 5. 最后一个例子](https://mp.weixin.qq.com/s?__biz=MzIxODY5Mzc4Mg==&mid=2247485328&idx=1&sn=87e20836cdb8de10d2de8e5db0fde598&chksm=97e7ee69a090677f262035e3ab1882c9d8bf4c7259d7f5fcc56fcb3fc8b7f6069d631c71f14a&scene=178&cur_album_id=2364704891711045633#rd)
  * [Hello Rust async/await](http://liubin.org/blog/2021/03/25/hello-rust-async/)
* async
  * [Asynchronous Programming in Rust](https://rust-lang.github.io/async-book/)
  * [Rust 中的异步编程](https://huangjj27.github.io/async-book/)
  * [Rust语言圣经 - Rust 异步编程](https://course.rs/async-rust/intro.html)
* tokio
  * [Tokio - Async in depth](https://tokio.rs/tokio/tutorial/async)
  * [Rust入门秘籍 - tokio简介](https://rust-book.junmajinlong.com/ch100/00.html)
  * [Tokio 內部機制：從頭理解 Rust 非同步 I/O 框架](https://gist.github.com/weihanglo/4661db374f82fe91e931bab0f50d7a10)
* FSM logic:
  * [async/await 如何工作 | Rust学习笔记](https://segmentfault.com/a/1190000024540040)
* Pin/Unpin:
  * [Pin and suffering](https://fasterthanli.me/articles/pin-and-suffering)
  * [Rust 中的 Pin UnPin Async Await 实现机制](https://blog.csdn.net/xuejianxinokok/article/details/133739148)
  * [Rust原理与工程实践｜Rust Pin 进阶](https://juejin.cn/post/7064473476173660190)
