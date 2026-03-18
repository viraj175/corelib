# corelib

A small C library I built from scratch to get better at memory management and data structures. No `malloc` or `free` from the standard library — everything is built on top of a custom allocator that talks directly to the OS using `sbrk`.

I made this while learning C deeply before moving into CUDA/GPU programming. The goal was to actually understand what happens under the hood when you allocate memory, instead of just calling `malloc` and hoping for the best.

---

## What's inside

- **my_malloc** — custom memory allocator using `sbrk`. tracks free blocks with a linked list and reuses them instead of always asking the OS for new memory. has double-free and invalid-free detection using a magic number.
- **my_string** — a dynamic string type with bounds-checked access, safe append that grows the buffer when needed, and proper cleanup.
- **stack** — linked list based stack that stores `String *` values. push, pop, peek, print, free.
- **queue** — linked list based queue. enqueue adds to rear, dequeue removes from front. both in O(1).

everything is built on top of `my_malloc` — no `malloc` anywhere in the codebase.

---

## Building

```bash
make        # builds the binary
make run    # builds and runs
make clean  # removes object files and binary
make re     # clean rebuild
```

requires `gcc` and standard C headers. tested on Linux (NixOS).

---

## Project structure

```
corelib/
├── my_malloc.h / my_malloc.c   — allocator
├── my_string.h / my_string.c   — string type
├── stack.h     / stack.c       — stack
├── queue.h     / queue.c       — queue
├── main.c                      — tests
└── makefile
```

---

## How the allocator works

instead of calling `malloc`, I use `sbrk` to carve raw memory from the OS. before every allocation I store a small header (called a block) that tracks the size, whether it's free, and a pointer to the next block. when you call `my_free`, it just marks the block as available — the memory stays claimed but gets reused next time. the OS only takes memory back when the program exits.

```
heap layout:

[header: size=64, free=0] [64 bytes] [header: size=128, free=1] [128 bytes] ...
                           ↑                                      ↑
                     user gets this ptr                     available for reuse
```

---

## Example

```c
// string
String *s = string_new("hello");
string_append(s, " world");
string_print(s);  // hello world
string_free(&s);

// stack
Stack *st = stack_new();
push(st, string_new("first"));
push(st, string_new("second"));
printf("%s\n", pop(st)->str);  // second
stack_free(&st);

// queue
Queue *q = queue_new();
enqueue(q, string_new("first"));
enqueue(q, string_new("second"));
printf("%s\n", dequeue(q)->str);  // first
queue_free(&q);
```
