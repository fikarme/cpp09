Aight, bet. Let's do a full walkthrough of the Ford-Johnson algorithm with your input `3 5 9 7 4`. We'll focus on how the Jacobsthal numbers come into play to make the sorting efficient. It's a complex vibe, but we'll break it down.

### The Setup

The initial call is `sortVec` with `nums = [3, 5, 9, 7, 4]`.

---

### Step 1: The Straggler

The algorithm works on pairs, so any odd element out gets benched for now.
*   The list size is 5 (odd).
*   The last element, `4`, is set aside as the `straggler`.
*   The list we'll work with is now `nums = [3, 5, 9, 7]`.

---

### Step 2: Pairing and Pair-wise Sort

We group the list into pairs and sort within each pair. The larger number goes into `mainChain`, and the smaller goes into `pend`.

*   **Pair 1:** `(3, 5)`. Since `5 > 3`:
    *   `mainChain` gets `5`.
    *   `pend` gets `3`.
*   **Pair 2:** `(9, 7)`. Since `9 > 7`:
    *   `mainChain` gets `9`.
    *   `pend` gets `7`.

After this step:
*   `mainChain = [5, 9]`
*   `pend = [3, 7]`

---

### Step 3: Recursive Sort of `mainChain`

Now we recursively sort `mainChain`.
*   `sortVec([5, 9])` is called.
*   It pairs `(5, 9)`, sorts them, and recursively calls `sortVec` on `[9]`.
*   The base case is hit (`size < 2`), and it quickly determines the sorted `mainChain` is `[5, 9]`.
*   The recursion unwinds, and `_vecSorted` is now `[5, 9]`.

Back in our main call, we set `sortedChain = _vecSorted`, so `sortedChain = [5, 9]`.

---

### Step 4: The First Insertion

The algorithm gives us a freebie. We know the first element of `pend` (`3`) is smaller than its partner (`5`), which is the first element of the sorted `mainChain`. So, we can insert `3` at the very beginning without a search.

*   `sortedChain.insert(sortedChain.begin(), pend[0])`
*   `sortedChain` is now `[3, 5, 9]`.
*   The remaining elements in `pend` to be inserted are `[7]`.

---

### Step 5: Jacobsthal Insertion Order

This is the 200 IQ play. We need to insert the rest of `pend` (`[7]`) into `sortedChain` (`[3, 5, 9]`). Instead of just going in order, we use Jacobsthal numbers to generate an optimal insertion sequence.

The goal is to create `jacobIndices`, a list of indices into `pend` that tells us the best order to insert them.

1.  **Initialize:** `k = 2`, `lastJacob = 1`. `pend.size()` is 2, but we've already inserted `pend[0]`, so we're only concerned with the remaining elements. The indices we care about are from the original `pend`.
2.  **Loop 1 (`k=2`):**
    *   `jacobsthal(2)` returns `1`.
    *   `jacob` is `1`.
    *   The inner loop `for (i = 1; i > 1; --i)` doesn't run.
    *   `lastJacob` is still `1`. `k` becomes `3`.
3.  **Loop 2 (`k=3`):**
    *   `jacobsthal(3)` returns `3`.
    *   `pend.size()` is `2`. The `if (jacob > pend.size())` check caps `jacob` at `2`.
    *   The inner loop `for (i = 2; i > 1; --i)` runs once for `i = 2`.
    *   `jacobIndices.push_back(i - 1)` pushes `1`.
    *   `jacobIndices` is now `[1]`.
    *   The `if (jacob == pend.size())` condition is true, so we `break`.

The final insertion order is `jacobIndices = [1]`. This tells us to insert `pend[1]` next.

---

### Step 6: Binary Search & Insertion

We now loop through `jacobIndices`.

*   **`i = 0`:** The index from `jacobIndices` is `1`.
    *   The value to insert is `val = pend[1]`, which is `7`.
    *   We use `lower_bound` to find the right spot for `7` in `sortedChain` (`[3, 5, 9]`). `lower_bound` does a binary search and finds that `7` should go between `5` and `9`.
    *   `sortedChain.insert(it, 7)`.
    *   `sortedChain` is now `[3, 5, 7, 9]`.

---

### Step 7: The Straggler Returns

Finally, we insert the `straggler` (`4`) that we benched at the start.

*   We use `lower_bound` to find the spot for `4` in `[3, 5, 7, 9]`. It finds the spot between `3` and `5`.
*   `sortedChain.insert(it, 4)`.
*   `sortedChain` is now `[3, 4, 5, 7, 9]`.

---

### Final Result

The final sorted list is `[3, 4, 5, 7, 9]`. The algorithm sets `_vecSorted` to this result, and the process is complete. No cap.