// Aight, bet. Your current implementation is a good start
// but it's taking some major Ls on performance and isn't the full-fat Ford-Johnson algorithm
// The way you're creating an extra pairs vector is a resource L
// and the linear insertion of the pend elements is not the optimal vibe the subject demands.

// Let's give these functions a serious glow-up
// I've refactored them to be more efficient and to use the Jacobsthal insertion sequence
// which is the secret sauce of this algorithm.

// The Glow-Up
// This improved version of sortVec now uses the Jacobsthal sequence to minimize comparisons
// which is the whole point of the Ford-Johnson algorithm
// The processVecPairs logic is also rolled directly into sortVec to avoid creating an unnecessary intermediate vector
// saving memory and time.

// I'm keeping your function signatures and the use of the _vecSorted member variable as you asked
// but know this: passing the vector by value (vector<int> nums) on every recursive call is a huge performance bottleneck
// For a true 42-pilled solution
// you'd want to sort in-place by passing a reference (vector<int>& nums).


1.  `shuf -i 1-42 -n 31`
	*   `shuf`: The shuffle command. It randomizes lines of input.
	*   `-i 1-42`: This is the `--input-range` flag. It tells `shuf` to generate its own input: the numbers from 1 to 42.
	*   `-n 31`: This is the `--head-count` flag. It makes `shuf` output only the first 31 numbers from its randomized list.

2.  `| tr "\n" " "`
	*   `|`: The pipe. It sends the output from `shuf` (31 numbers, each on a new line) directly as input to the `tr` command.
	*   `tr "\n" " "`: The translate command. It finds every newline character (`\n`) and swaps it for a space (` `).

-------------------

The algorithm doesn't just look at `5` and `3` and swap. It follows a strict, multi-step process designed to minimize comparisons, which is the whole point of this algorithm.

1.  **Pairing:** The algorithm groups the numbers into pairs. With `[5, 3]`, you get one pair: `(5, 3)`.

2.  **Pair-wise Sort:** It sorts within each pair, putting the larger number first. The pair `(5, 3)` is compared, and since `5 > 3`, it's already in the `(larger, smaller)` format.

3.  **Create Main Chain & Pend Chain:**
	*   It creates a "main chain" (`S`) with all the larger numbers. Here, `S = [5]`.
	*   It creates a "pend chain" (`pend`) with all the smaller numbers. Here, `pend = [3]`.

4.  **Recursive Sort:** The algorithm recursively sorts the main chain `S`. Since `S` only has one element (`[5]`), it's already sorted. This is the base case for the recursion.

5.  **Insertion:** Now, it inserts tkhe elements from the `pend` chain into the sorted main chain `S`.
	*   It takes the first (and only) element from `pend`, which is `3`.
	*   It uses a binary search to find the correct spot for `3` in `S`. Where does `3` fit in `[5]`? Before the `5`.
	*   The insertion happens, and `S` becomes `[3, 5]`.

The final sorted sequence is `[3, 5]`.

-------------------



The first function uses `pow(-1, k)` to get the alternating `+1` and `-1`. This is mad extra.

*   **Function 1:** `pow(-1, k)`
	*   This calls a floating-point math function to do something super simple. It's like using a flamethrower to light a candle. It works, but it's overkill and can be slower.

*   **Function 2:** `(k % 2 == 0 ? 1 : -1)`
	*   This is the big brain move. It uses basic integer math to check if `k` is even or odd and gives you `1` or `-1`. It's faster, avoids any floating-point weirdness, and is just cleaner code.

*   **It's safer:** Handles negative inputs gracefully.
*   **It's faster:** Uses integer math instead of the heavy `pow` function for the sign flip.
*   **It's cleaner:** The logic is more direct and easier to read.
