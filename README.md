# rustqueue

## CMSI 3510 — Homework 5 (Path A)

`rustqueue` is a Linux kernel module written in Rust that implements a bounded FIFO message queue using a character device interface.

The module registers the device:

```text
/dev/rustqueue
```

Messages written to the device are enqueued into a shared kernel queue. Reads dequeue messages in FIFO order and return them to userspace.

---

## Features

- Linux kernel module written in Rust
- Character device using `MiscDevice`
- FIFO queue behavior
- Shared kernel-level message queue
- Mutex synchronization for safe concurrent access
- Per-open file descriptor state using `pending`
- Supports:
  - `write_iter()` for enqueue
  - `read_iter()` for dequeue

---

## Repository Files
- `.gitignore` — ignores generated build artifacts
- `LICENSE` — GPL-2.0 license file
- `Makefile` — kernel build configuration
- `README.md` — project documentation
- `rustqueue.rs` — Rust kernel module source

---

## Build Instructions

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

## Testing

Write messages into the queue:

```bash
echo "first message" | sudo tee /dev/rustqueue > /dev/null
echo "second message" | sudo tee /dev/rustqueue > /dev/null
echo "third message" | sudo tee /dev/rustqueue > /dev/null
```

Read messages from the queue:

```bash
sudo cat /dev/rustqueue
sudo cat /dev/rustqueue
sudo cat /dev/rustqueue
sudo cat /dev/rustqueue
```

Expected output:

```text
first message
second message
third message
```

The fourth read should return EOF / blank output because the queue is empty.

---

## Design Overview

The implementation uses two levels of state.

### Global Queue

A globally shared queue stores all pending messages:

```rust
static QUEUE: Mutex<KVec<KVec<u8>>>
```

This queue is protected with a mutex to ensure safe concurrent access.

---

### Per-open State

Each open file descriptor maintains:

```rust
pending: Option<KVec<u8>>
```

This allows repeated reads on the same descriptor without dequeuing multiple messages.

---

## Important Functions

### `write_iter()`

- Copies userspace data into kernel memory
- Validates message size
- Enqueues the message into the shared queue
- Rejects writes if the queue is full

---

### `read_iter()`

- Dequeues one message on the first read
- Stores the message in `pending`
- Streams data to userspace until EOF

---

## Author

Tessa Smigla
