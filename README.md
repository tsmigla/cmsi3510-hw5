# rustqueue

## CMSI 3510 - Homework 5 (Path A)

`rustqueue` is a Linux kernel module written in Rust that implements a bounded FIFO message queue using a character device interface.
The module registers the device:
/dev/rustqueue
Messages written to the device are enqueued into a shared kernel queue. Reads dequeue messages in FIFO and return them to userspace.

---

## Features
- Linux kernel module written in Rust
- Character device using `MiscDevic`
- FIFO queue behavior
- Shared kernel-level message queue
- Mutex synchronization for safe concurrent access
- Per-open file descriptor state using 'pending'
- Supports: 
	- `write_iter()` for enqueue
	- `read_iter()` for dequeue

---

# Build Instructions
Compile the module:
```bash
make clean
make
