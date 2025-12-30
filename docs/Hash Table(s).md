A Hash Table is a Data Structure that maps keys to values for highly efficient lookup, insertion, and deletion. It is a fundamental data structure that relies on the concept of a Hash Function to quickly compute an index (memory address) from a given key.

Hash Tables are often referred to as a **dictionary** or **associative array** in many languages.

---
#### Time & Space Complexity
| Operation     | Best Case | Worst Case |
| :------------ | :-------- | :--------- |
| **Search**    | $O(1)$    | $O(n)$     |
| **Insertion** | $O(1)$    | $O(n)$     |
| **Deletion**  | $O(1)$    | $O(n)$     |

**Note on Worst Case:** The worst-case complexity of $O(n)$ occurs when the hash function fails spectacularly and all keys map to the same bucket, essentially degrading the Hash Table into Linked List(s).

**Space Complexity:** $\Theta(n)$ for storage of the elements.

---
#### The Core Concept: Index from Key
The fundamental operation of a Hash Table is transforming a key (e.g., a username or product ID) into a numerical index for an array. This is the Hash Function.

$$Index = HashFunction(Key) \pmod {ArraySize}$$

Since memory is sequential, just like in Basic Array(s), finding the calculated $Index$ is an $O(1)$ operation, which is what gives Hash Tables their speed.

---
#### Components of a Hash Table
A Hash Table requires three main parts to function:

1.  **The Hash Function:** A mathematical function that takes an input key and converts it into a fixed-size integer value (the hash code). A good hash function is **fast** and distributes keys **uniformly** across the array to minimize collisions.
2.  **The Array (Buckets/Slots):** A simple array (fixed or dynamically allocated) where the actual data (key-value pairs) will be stored. Each position in this array is called a **bucket** or **slot**.
3.  **The Collision Resolution Method:** A strategy to handle what happens when two different keys map to the same index (a **collision**).

---
#### Handling Collisions
Collisions are inevitable due to the Pigeonhole Principle (mapping a potentially infinite number of keys to a finite number of buckets). The two primary methods for handling them are:

| Method                           | Description                                                                                                                                                                                |     |
| :------------------------------- | :----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | :-- |
| **1. Separate Chaining**         | Each bucket in the array holds a pointer to a secondary Linked List(s) (or a small Binary-Search Tree(s)). All elements that hash to the same index are simply added to that list. |     |
| **2. Probing (Open Addressing)** | If the calculated index is already occupied, the table looks for the *next available empty slot* in the array. This search is called **probing**.                                          |     |

**Probing Sub-Methods:**
- **Linear Probing:** Searches sequentially: $Index+1, Index+2, Index+3, \dots$
- Risk: Clustering
- **Quadratic Probing:** Searches non-linearly: $Index+1^2, Index+2^2, Index+3^2, \dots$
- **Double Hashing:** Uses a *second* hash function to determine the step size for probing.
**Separate Chaining (Linked List Implementation)**
- O(1) Insertion (Insert at head)
- Traverse: O(length of the Linked List(s))
- No clustering risk
---
#### Cons
- **Performance Degradation:** If the Hash Table's **Load Factor** (the ratio of elements to buckets) gets too high, the number of collisions increases, causing average case performance to degrade toward $O(n)$.
- **Space Overhead:** Open addressing requires more space up front, and separate chaining requires extra space for pointers (like in a Linked List(s)).
- **Ordering:** Hash Tables provide no inherent order to the data, making operations like finding the minimum or maximum element an $O(n)$ scan.

---