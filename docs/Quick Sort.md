**Quick Sort** is a highly efficient, Divide-&-Conquer sorting algorithm. It works by selecting a 'pivot' element from the array and partitioning the other elements into two sub-arrays, according to whether they are less than or greater than the pivot. The sub-arrays are then sorted recursively.

It is often faster in practice than other $O(n \log n)$ algorithms like Merge Sort because it is an **in-place** sort (requiring little additional memory) and has excellent **cache locality**, making it a favorite in Low-level Systems Programming (e.g., `qsort` in C's standard library).

---
#### Time & Space Complexity

| Case      | Time Complexity | Explanation                                                                             |
| :-------- | :-------------- | :-------------------------------------------------------------------------------------- |
| **Best**  | $O(n \log n)$   | Partition splits array exactly in half every time.                                      |
| **Worst** | $O(n^2)$        | Partition creates one empty sub-array (e.g., sorted array with first element as pivot). |

**Space Complexity:** $O(\log n)$ due to the recursive Stack Frames.

---
#### Pros & Cons

**Pros:**
1.  **Speed:** In practice, it is often faster than Merge Sort because of efficient cache usage (linear scanning of memory).
2.  **In-Place:** Requires minimal extra memory ($O(\log n)$ stack space), unlike Merge Sort which needs $O(n)$ space.
3.  **Systems Standard:** It is the standard sorting algorithm in many standard libraries (C/C++, Java).

**Cons:**
1.  **Worst Case:** If the pivot is poorly chosen (e.g., smallest element in a sorted array), complexity degrades to $O(n^2)$. *Solution: Median of a sample size as a pivot.*
2.  **Unstable:** Relative order of equal elements is NOT preserved (unlike Merge Sort).

---
#### The Algorithm (Partitioning)
The core of Quick Sort is the **Partition** logic.
1.  **Choose a Pivot:** Select an element (first, last, middle, or random).
2.  **Reorder:** Move all elements *smaller* than the pivot to its left, and all elements *larger* to its right.
3.  **Recursion:** Apply the same logic to the left and right sub-arrays.

**Visualizing Partition**
*Pivot is chosen as the last element (4).*

| Step | 0 | 1 | 2 | 3 | 4 | 5 | Description |
| :--- | :---: | :---: | :---: | :---: | :---: | :---: | :--- |
| **Initial** | 2 | 6 | 5 | 1 | 3 | **4** | |
| **Step 1** | | | | | | | Compare 2 < 4? Yes. Keep. |
| **Step 2** | | | | | | | Compare 6 < 4? No. Mark. |
| **Step 3** | | | | | | | Compare 5 < 4? No. Mark. |
| **Step 4** | | | | | | | Compare 1 < 4? Yes. Swap 1 with first marked larger (6). |
| **Swap** | 2 | **1** | 5 | **6** | 3 | **4** | |
| **Step 5** | | | | | | | Compare 3 < 4? Yes. Swap 3 with next marked larger (5). |
| **Swap** | 2 | 1 | **3** | 6 | **5** | **4** | |
| **Final** | | | | | | | Move Pivot (4) to its correct sorted position (between 3 and 6). |
| **Result** | 2 | 1 | 3 | **4** | 6 | 5 | (Sorted relative to pivot) |

---