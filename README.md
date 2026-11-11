# topcoder

Solutions and practice for competitive programming contests (TopCoder, Codeforces, Google Code Jam).

## Codeforces Workflow

### Start a New Round
From the `codeforces/` directory, generate a new round folder from [`codeforces/template/`](codeforces/template/):
```bash
cd codeforces && make r1134
```
This creates `codeforces/r1134/` with starter files (`a.cc`–`e.cc`), empty sample input files (`a.in`–`e.in`), and a `Makefile`.

### Compile & Run
Inside a round directory (e.g., `codeforces/r1134/`):
- **`make a`** (or `b`, `c`, `d`, `e`, `f`): Compile `a.cc` with `-O2` and run `./a.out < a.in`.
- **`make da`** (or `db`, `dc`, `dd`, `de`, `df`): Compile and run with debug flags, AddressSanitizer, UndefinedBehaviorSanitizer, and bounds-checked STL (`-D_GLIBCXX_DEBUG`).
- **`make vim`**: Open all `.cc` and `.in` files in Vim tabs (`vim -p`).
- **`make clean`**: Remove compiled `*.out` binaries.

## Authorship & Attribution Conventions

To clearly distinguish solo contest/practice solutions from post-contest reference material:

### File Naming
- **`a.cc`, `b.cc`, ...**: Written solo by Kevin Townsend during a contest or practice.
- **`a_upsolve.cc`**: Written by Kevin Townsend after consulting hints or the editorial.
- **`a_ai.cc` / `a_simplified.cc`**: AI-generated or AI-refactored post-contest reference code.
- **`a_editorial.cc`**: Adapted from an official editorial or another contestant's submission.

### Header Comments
- **Solo code** (default in [`codeforces/template/template.cc`](codeforces/template/template.cc)):
  ```cpp
  /**
   * author: Kevin Townsend
  **/
  ```
- **AI-assisted / post-contest reference**:
  ```cpp
  /**
   * author: Kevin Townsend (AI-assisted reference)
   * note: Post-contest review / upsolve
  **/
  ```
- **Editorial / third-party adaptation**:
  ```cpp
  /**
   * source: Codeforces Editorial (adapted by Kevin Townsend)
  **/
  ```

