# Memory

* RSS (Resident Set Size): The usage of physical memory.
* VSZ (Virtual Set Size): The usage of virtual memory.
* mmap (Memory Mapped File): The memory that maps the files to the virtual memory.
* Arena: The memory pool that can be used for allocation.
* SWAP space: The system will move some data to the disk if the memory is not enough.
* Slab: There are different-size cache inside kernel having multiple slabs, that can be reused.
  * We can check with `/proc/slabinfo`.

[The image source](https://hammertux.github.io/slab-allocator)
