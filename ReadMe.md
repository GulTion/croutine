# Croutine

Stackful coroutines for C, written in x86-64 FASM.

Each coroutine gets its own 4 KB stack. Up to 10 can run concurrently. Cooperative scheduling — you yield explicitly.

## Requirements

- Linux x86-64
- [FASM](https://flatassembler.net/) (flat assembler)
- GCC

## Build & Run

```sh
make        # assembles, compiles, and runs
make clean  # removes build artifacts
```

## API

```c
#include "croutine.h"

cro_init();              // call once at the start of main
cro(fn, arg1, arg2, …); // spawn a coroutine (up to 5 args)
cro_yield();             // yield to the next coroutine
cro_join();              // wait for all coroutines to finish
```

## Example

```c
#include <stdio.h>
#include "croutine.h"

void counter(int N, char label[]) {
    for (int i = 0; i < N; i++) {
        printf("%s: %d\n", label, i);
        cro_yield();
    }
}

int main() {
    cro_init();
    cro(counter, 5, "Croutine A");
    cro(counter, 10, "Croutine B");
    cro_join();
}
```

Output (interleaved):
```
Croutine A: 0
Croutine B: 0
Croutine A: 1
Croutine B: 1
...
```

## Limitations

- x86-64 Linux only
- Max 10 concurrent coroutines
- Max 5 arguments per coroutine function
- 4 KB stack per coroutine (no guard page)
- Not thread-safe
