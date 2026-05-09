# rustqueue — a bounded FIFO message queue as a Linux kernel module

CMSI 3510 — Homework 5 (Path A)

`rustqueue` is a Linux kernel module written in Rust that implements a bounded FIFO message queue through a character device interface. Messages written to `/dev/rustqueue` are stored in a shared kernel queue and returned in FIFO order when read.

This project demonstrates Rust-for-Linux development, kernel synchronization with mutexes, userspace ↔ kernelspace data transfer, and character device registration using `MiscDevice`.

---

# Demo

```bash
$ sudo insmod rustqueue.ko

$ echo "first message"  | sudo tee /dev/rustqueue > /dev/null
$ echo "second message" | sudo tee /dev/rustqueue > /dev/null
$ echo "third message"  | sudo tee /dev/rustqueue > /dev/null

$ sudo cat /dev/rustqueue
first message

$ sudo cat /dev/rustqueue
second message

$ sudo cat /dev/rustqueue
third message

$ sudo cat /dev/rustqueue
# EOF / empty output
```

---

# Repository Files

- `rustqueue.rs` — Rust kernel module source
- `Makefile` — kernel build configuration
- `README.md` — project documentation
- `.gitignore` — ignores generated build artifacts
- `LICENSE` — GPL-2.0 license file

---

# Build & Run

This project requires a Linux kernel with Rust support enabled.

Compile the module:

```bash
make clean
make
```

Load the module:

```bash
sudo insmod rustqueue.ko
```

Verify device creation:

```bash
ls -la /dev/rustqueue
```

Expected output:

```text
crw------- 1 root root ... /dev/rustqueue
```

Unload the module:

```bash
sudo rmmod rustqueue
```

---

# Testing

Write messages into the queue:

```bash
echo "first message"  | sudo tee /dev/rustqueue > /dev/null
echo "second message" | sudo tee /dev/rustqueue > /dev/null
echo "third message"  | sudo tee /dev/rustqueue > /dev/null
```

Read messages from the queue:

```bash
sudo cat /dev/rustqueue
sudo cat /dev/rustqueue
sudo cat /dev/rustqueue
sudo cat /dev/rustqueue
```

The fourth read should return EOF because the queue is empty.

---

# Code Tour

If you want to understand the implementation, start with these sections:

- `init()`  
  Registers the kernel module and creates the `MiscDevice`.

- `open()`  
  Creates a per-open `RustQueueDevice` instance with its own `pending` state.

- `write_iter()`  
  Handles writes from userspace. This function:
  - locks the global queue
  - validates message size
  - copies userspace data into kernel memory
  - enqueues the message

- `read_iter()`  
  Handles reads from userspace. On the first read, it dequeues one message from the global queue and stores it in `pending`. Additional reads continue streaming the same message until EOF.

---

# Design Notes

## Global Queue

The queue is implemented as:

```rust
Mutex<KVec<KVec<u8>>>
```

A mutex was chosen because the queue is shared mutable state accessed concurrently by multiple readers and writers inside the kernel.

---

## FIFO Behavior

Messages are dequeued using:

```rust
q.remove(0)
```

This preserves FIFO ordering.

---

## Per-open State

Each file descriptor maintains:

```rust
pending: Option<KVec<u8>>
```

This prevents repeated reads on the same descriptor from accidentally dequeuing multiple messages.

---

## Why `MiscDevice`

`MiscDevice` simplifies character device registration by automatically handling dynamic minor allocation and `/dev` integration.

---

# Future Work

Potential improvements include:

- Improve debugging logs and error reporting
- Add configurable queue capacity through module parameters
- Support polling/select APIs
- Add multi-message reads

---

# License

This project is licensed under the GPL-2.0 license to match Linux kernel licensing requirements.

---

# Author

Tessa Smigla
