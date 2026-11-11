# Codeforces Contest Strategy & C++ Playbook

A practical checklist and pattern guide tailored to this repository's past rounds (`r943`–`r1133`).

---

## 1. Pre-Submission Sanity Checklist (30 Seconds)

Before submitting any file, check these five common traps:

1. **Loop Bounds & Inclusive vs. Exclusive Indices**
   - Name interval endpoints `l` and `r` (always **inclusive**) rather than reusing `i` for both left endpoints and `r + 1`.
   - *Repo example* ([`codeforces/r1133/a.cc`](../codeforces/r1133/a.cc)): Using `i` as `r + 1` in `for (int i = middle + 1; i < n - 1; i++)` skipped the valid subarray `r = n - 2` (`i = n - 1`).
2. **Symmetric Cases Copy-Paste Bugs**
   - When handling `if (A > B)` vs `else`, double-check every subscript in the `else` branch.
   - *Repo example* ([`codeforces/r1028/b.cc`](../codeforces/r1028/b.cc)): In the `max_p > max_q` branch, `q[j - max_q.second]` was written instead of `q[j - max_p.second]`.
   - Better yet: if the two cases are symmetric, `std::swap(p, q)` or `std::reverse(a.begin(), a.end())` and run the **same** code once.
3. **Hidden $O(N^2)$ Inside an $O(N)$ Loop**
   - Sum of $N$ over test cases is typically $\sum N \le 2 \cdot 10^5$. Anything $O(N)$ inside the `for (int j = 0; j < n; j++)` loop will TLE.
   - *Repo example* ([`codeforces/r1028/b.cc`](../codeforces/r1028/b.cc)): Computing $2^k \bmod 998244353$ with a `for` loop inside each step made the solution $O(N^2)$. Precompute powers of 2 once or use $O(\log k)$ binary exponentiation.
4. **64-Bit Integer Overflow (`int64_t` / `1LL`)**
   - Use `int64_t` whenever summing arrays, multiplying indices, or shifting bits (`1LL << i`, as in [`codeforces/r1030/c.cc`](../codeforces/r1030/c.cc)).
   - Watch out for `std::accumulate(a.begin(), a.end(), 0LL)` — passing `0` instead of `0LL` overflows 32-bit `int`!
5. **Run with Sanitizers Before Submitting (`make da`)**
   - `make da` enables `-fsanitize=address,undefined -D_GLIBCXX_DEBUG`, which immediately catches out-of-bounds vector indexing (`a[-1]`, `a[n]`) and signed integer overflow even when `make a` appears to print the right answer.

---

## 2. Implementation Patterns to Keep Code Short

### Use Full-Array `pref` / `suff` Instead of Relative-Offset Slices
Instead of slicing arrays around a pivot and indexing with `middle - i - 1` or `n - i - 1` (compare [`r1133/a.cc`](../codeforces/r1133/a.cc) vs. [`r1133/a_simplified.cc`](../codeforces/r1133/a_simplified.cc)):
```cpp
vector<int> pref(n, 0), suff(n, 0);
for (int i = 1; i < n; i++) pref[i] = max(pref[i - 1], abs(a[i - 1] - a[i]));
for (int i = n - 2; i >= 0; i--) suff[i] = max(suff[i + 1], abs(a[i] - a[i + 1]));
```
- Every index into `pref` and `suff` matches the exact index in `a`.
- Guard boundary accesses inline with ternaries so you don't have to duplicate formulas outside your loop:
  ```cpp
  int left_outer = (l > 0) ? pref[l - 1] : 0;
  ```

### Exploit Symmetry with `std::reverse` or `std::swap`
If a problem requires checking subarrays to the left of `middle` and subarrays to the right of `middle`:
```cpp
auto solve_one_side = [&](const vector<int>& arr) -> int {
  // Only implement the left-of-middle case
};
int ans = solve_one_side(a);
reverse(a.begin(), a.end());
ans = min(ans, solve_one_side(a));
```

### Fast Modular Exponentiation (`modpow`)
Whenever you see `998244353` or `1000000007`, drop this 9-line helper above `main()`:
```cpp
constexpr int64_t MOD = 998244353;

int64_t modpow(int64_t base, int64_t exp) {
  int64_t res = 1;
  base %= MOD;
  while (exp > 0) {
    if (exp & 1) res = (res * base) % MOD;
    base = (base * base) % MOD;
    exp >>= 1;
  }
  return res;
}
```

---

## 3. High-Frequency Problem Archetypes

### A. "Pin the Bottleneck" (1 Operation to Improve Global Min/Max)
*Seen in: [`codeforces/r1133/a.cc`](../codeforces/r1133/a.cc)*
- **Pattern**: You are allowed **one** operation (reverse a subarray, change one element, remove one interval) to minimize the maximum violation or fix an array.
- **Strategy**:
  1. Find the worst violation (`middle`) in the unmodified input.
  2. Any operation that strictly improves the answer **must** touch or split `middle`.
  3. That pins one endpoint of your operation, dropping $O(N^2)$ possibilities to $O(N)$.
  4. **Sanity check**: Ask *"What if multiple positions tie for the worst violation?"*

### B. Bitwise Greedy by Bit Position ($0 \dots 59$)
*Seen in: [`codeforces/r1030/c.cc`](../codeforces/r1030/c.cc), [`codeforces/r949/a.cc`](../codeforces/r949/a.cc)*
- **Pattern**: Maximize/minimize popcount, XOR, AND, or OR with a budget $k$.
- **Strategy**:
  - When bits don't interact (or higher bits strictly dominate lower bits, since $2^b > \sum_{i=0}^{b-1} 2^i$), iterate bit-by-bit (`for (int b = 0; b < 60; b++)` or `59` down to `0`).
  - Use `<bit>` functions from C++20 (`std::popcount(x)`, `std::bit_width(x)`, `std::countr_zero(x)`), where `x` is cast to `uint64_t`.

### C. Prefix Running Optima & Greedy Pairing
*Seen in: [`codeforces/r1028/b.cc`](../codeforces/r1028/b.cc)*
- **Pattern**: For each prefix $0 \dots j$, compute the best combination $f(p_k, q_{j-k})$ for $0 \le k \le j$.
- **Strategy**:
  - When $2^x$ dominates all smaller powers of 2, you don't need to check all $k \le j$: only the index `max_p_idx` maximizing $p_k$ and the index `max_q_idx` maximizing $q_{j-k}$ can win.

### D. Constructive / Pattern Problems
*Seen in: [`codeforces/r1030/b.cc`](../codeforces/r1030/b.cc), [`codeforces/r1030/e.cc`](../codeforces/r1030/e.cc)*
- **Strategy**:
  - Solve $N = 3$ and $N = 4$ by hand on paper before writing code.
  - Look for a uniform 2-step per row/element construction rather than branching on parity unless forced.
  - Write a quick 5-line checker function in your local file to verify your constructed output satisfies the problem constraints before submitting.

---

## 4. Live Contest Pacing (2-Hour Round)

1. **Minutes 0–25 (Problems A & B)**:
   - Read carefully, check constraints ($N = 1$? $K = 0$? all elements equal?), run `make da`, and submit cleanly. Avoid wrong-answer penalties on A/B—each WA costs 50+ points and momentum.
2. **When Stuck for 15 Minutes on C/D**:
   - **Check the standings dashboard**: If problem D has 2x more solves than C, switch immediately—scoring distributions on Codeforces aren't always monotonic in actual difficulty.
   - **Write a 15-line brute force**: If you have a candidate $O(N)$ greedy idea (like in `r1133/a.cc`), test it on small $N \le 8$ inputs against a brute-force loop before submitting or after a WA.
3. **Final 15 Minutes**:
   - Stop starting brand-new problems; either finish debugging the problem in progress or check your accepted solutions for `int` overflow (`int64_t`) and worst-case $N = 2 \cdot 10^5$ TLE traps.
