# topcoder

Solutions and practice for competitive programming contests (TopCoder, Codeforces, Google Code Jam).

## Codeforces Workflow

### Start a New Round
From the `codeforces/` directory, generate a new round folder from [`codeforces/template/`](codeforces/template/):
```bash
cd codeforces && make r1134
```
This creates `codeforces/r1134/` with starter files (`a.cc`–`f.cc`), empty sample input files (`a.in`–`f.in`), and a `Makefile`.

### Compile & Run
Inside a round directory (e.g., `codeforces/r1134/`):
- **`make <name>`** (e.g., `make a`, `make f`, `make f_upsolve`): Compile `<name>.cc` with `-O2` and run `./<name>.out` on `<name>.in` (falling back to `<prefix>.in`, e.g. `f.in` for `f_upsolve`).
- **`make d<name>`** (e.g., `make da`, `make df_upsolve`): Compile and run with debug flags, AddressSanitizer, UndefinedBehaviorSanitizer, and bounds-checked STL (`-D_GLIBCXX_DEBUG`).
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

