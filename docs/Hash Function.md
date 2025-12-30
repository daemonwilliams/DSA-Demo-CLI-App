A **Hash Function** is defined as any function that can be used to map data of arbitrary size to fixed-size values. The values returned by a hash function are called *hash values*, *hash codes*, *digests*, or simply *hashes*. They are primarily used to index data in Hash Table(s).

The core idea is to transform a given input (`key`) into an integer that can be used as an array index, allowing for very fast data retrieval.

---
#### Properties of a Good Hash Function
For a hash function to be effective, especially for data structures like hash tables, it should exhibit several key properties:

1.  **Deterministic:** The same input key must always produce the same hash value.
2.  **Efficient Computation:** The hash value should be quick to compute. A complex hash function defeats the purpose of fast lookups.
3.  **Uniform Distribution:** It should distribute keys as evenly as possible across the entire range of possible hash values. This minimizes Collisions.

---
#### Why Hash Functions are Used
- **Fast Data Retrieval (Hash Tables):** Provides $O(1)$ average-case lookup, insertion, and deletion times.
- **Data Integrity (Checksums):** Verifying that data has not been altered (e.g., file downloads, network packets).
- **Cryptography:** Used in digital signatures, password storage, and message authentication codes. (These are specialized cryptographic hash functions).
- **Uniqueness Identification:** Quickly checking if an item has been seen before (e.g., in caches).

---
#### Common Techniques & Implementations

**1. Simple Summation (Illustrative, but Flawed)**
This method sums the ASCII values of characters in a string. It's easy to understand but results in many collisions for different strings with the same characters.
*Limitations: Poor distribution, sensitive to character order only (not position).*

**2. Polynomial Rolling Hash (Better Distribution)**
This method considers the position of each character, giving more weight to characters earlier in the string. It involves multiplying by a prime number `p` at each step.

**Rust Implementation Example (using `std::collections::hash::Hasher`)**
In Rust, you typically use the built-in `std::hash::Hash` trait and `std::collections::HashMap` which uses a cryptographic-ally secure, yet fast, default hash function (SipHash). For custom hashing, you'd implement the `Hasher` trait.

---
#### Collision Handling
Since a hash function maps a potentially large set of inputs to a smaller, fixed-size output range, **collisions are inevitable**. Effective hash tables require strategies to handle these collisions, such as:
- **Separate Chaining:** Store colliding elements in a linked list at each hash table index.
- **Open Addressing:** Find another open spot in the hash table when a collision occurs (e.g., Linear Probing, Quadratic Probing, Double Hashing).

*(See Hash Table(s) for more details on collision resolution.)*

---