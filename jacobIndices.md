### Explanation: jacobIndices in Ford-Johnson (PmergeMe) Sort

jacobIndices is literally the playlist for inserting elements from pend into the main sorted chain, but with a twist: it follows the Jacobsthal number sequence. This sequence is used to optimize the number of comparisons, which is a big flex in the Ford-Johnson algorithm (the OG behind PmergeMe).

- Each value in jacobIndices is an index into pend.
- The order is not just 0, 1, 2, ... but is determined by the Jacobsthal sequence, which spaces out insertions to minimize the number of comparisons.
- When you loop over jacobIndices, you’re inserting pend[jacobIndices[i]] into the sorted chain at the right spot (using lower_bound).

So yeah, your summary is on point:
**jacobIndices is a list of indices into pend that tells us the optimal order to insert them, based on the Jacobsthal sequence, to keep the sort as efficient as possible.**

This is straight out of the 42 project constraints—no wasted moves, no extra comparisons, just pure algorithmic drip.