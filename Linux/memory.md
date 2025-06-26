# Memory

* RSS (Resident Set Size): The usage of physical memory.
* VSZ (Virtual Set Size): The usage of virtual memory.
* mmap (Memory Mapped File): The memory that maps the files to the virtual memory.
* Arena: The memory pool that can be used for allocation.
* SWAP space: The system will move some data to the disk if the memory is not enough.
* Slab: There are different-size cache inside kernel having multiple slabs, that can be reused.
  * We can check with `/proc/slabinfo`.

![image](https://github.com/user-attachments/assets/f7e4f87b-26e5-4c95-8047-415b698e4bbf)

[The image source](https://hammertux.github.io/slab-allocator)
