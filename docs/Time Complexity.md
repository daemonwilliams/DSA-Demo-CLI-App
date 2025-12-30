**Time Complexity** is a measure of the amount of time taken by an algorithm to run as a function of the length of the input. It is the core mechanism used in Data Structures & Algorithms to analyze and compare the efficiency and *scalability* of different solutions.

Crucially, Time Complexity does **not** measure wall-clock execution time (which is dependent on many variables such as hardware, programming language, and OS), but rather counts the number of **operations that scale with the amount of data** performed by the algorithm. 

---
### Asymptotic Notations
Asymptotic notation describes the limiting behavior of a function when the argument tends towards a particular value ($\infty$). We use it to describe how an algorithm's running time scales with the size of the input (n). The definitions below rely on **Logic and Propositions** to establish strict bounds.

**Big-O ($O$): "Upper Bound" (The Ceiling)**
Big-O describes the maximum growth rate. It guarantees the algorithm will never be slower than this.
- Note: Usually used for the *Worst Case* because we care about the safety limit.

**Omega ($\Omega$): "Lower Bound" (The Floor)**
Omega describes the minimum growth rate. It guarantees the algorithm will never be faster than this.
- Note: Usually used for the Best Case.

**Theta ($\Theta$): "Tight Bound" (The Exact Fit)**
Theta is the most precise. It is used when the Upper Bound ($O$) and Lower Bound ($\Omega$) are the same. 
- It is never faster, never slower. So it is $\Theta(n)$.

| Notation             | Name            | Formal Definition                                                | What it Represents                                                                       |
| :------------------- | :-------------- | :--------------------------------------------------------------- | :--------------------------------------------------------------------------------------- |
| $O$ (Big-Oh)         | **Upper Bound** | $f(n) \le c \cdot g(n)$ for all $n \ge n_0$                      | **Worst-Case** or maximum time required. *E.g.,* A function is **no worse than** $g(n)$. |
| $\Omega$ (Big-Omega) | **Lower Bound** | $f(n) \ge c \cdot g(n)$ for all $n \ge n_0$                      | **Best-Case** or minimum time required. *E.g.,* A function is **no better than** $g(n)$. |
| $\Theta$ (Big-Theta) | **Tight Bound** | $c_1 \cdot g(n) \le f(n) \le c_2 \cdot g(n)$ for all $n \ge n_0$ | **Average-Case** running time. The algorithm is **exactly proportional** to $g(n)$.      |

---
### Common Complexities (Scalability Hierarchy)
The efficiency of algorithms is ranked by their growth rate. When $n$ is large, slower growing functions are preferred.

| Name             | Complexity    | Description                                                                                                                                   |
| :--------------- | :------------ | :-------------------------------------------------------------------------------------------------------------------------------------------- |
| **Constant**     | $O(1)$        | Time is independent of the input size ($n$). *E.g.,* Array index lookup, Linked List(s) head/tail insertion.                              |
| **Logarithmic**  | $O(\log n)$   | Time grows slowly as the input size doubles. *E.g.,* Binary Search in a sorted array, searching in a Binary-Search Tree(s).           |
| **Linear**       | $O(n)$        | Time is directly proportional to the input size ($n$). *E.g.,* Linear search, traversal of a Linked List(s).                              |
| **Linearithmic** | $O(n \log n)$ | Time increases slightly faster than linear. *E.g.,* Efficient sorting algorithms like Quick Sort and Merge Sort.                          |
| **Quadratic**    | $O(n^2)$      | Time is proportional to the square of the input size. *E.g.,* Inefficient sorting like Bubble Sort, nested loops iterating over an array. |
| **Exponential**  | $O(2^n)$      | Time doubles for every single element added to the input. *E.g.,* Solving the Traveling Salesperson Problem (unoptimized).                    |

---
### Examples: Analyzing Code
To determine the complexity, we ignore **constants** and **lower-order terms** because we are only concerned with the dominant term as $n$ approaches infinity.

**Example 1: Constant Time $O(1)$**

---