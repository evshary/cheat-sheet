# ulimit

ulimit is used to limit the resource that can be used by a process.

Two limits:

* soft limit: Users can adjust it arbitrarily, but it should be lower than hard limit.
* hard limit: Only root can adjust it.

The process inherits the value from its parents.
Those values come from `/etc/security/limits.conf`.

Note that ulimit is just a CLI to maintain the resource limits number.
Linux uses the system calls `setrlimit` and `getrlimit` to do the resource management.

## Usage

* `ulimit -a`: Show all the limitation values
* `ulimit -n <value>`: Set the number of maximum file descriptor
* `ulimit -l <value>`: Set the number of locked-in memory

## Container

Note that the container in Linux by default use 8192 KiB for the locked-in memory.
If you want to run the shared memory process (using pre-committed memory) inside a container, you need to increase the number.
