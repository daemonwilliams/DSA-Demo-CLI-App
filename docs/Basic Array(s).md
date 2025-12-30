A basic array (one dimensional), is a simple, yet powerful and very core Data Structure* A basic array is a *linear* data structure containing elements that are written *sequential in memory*. The elements being written sequential in memory is the key here. This allows us to easily retrieve data from different portions of the array.
Also see, Multi-Dimensional Array(s)

---
#### The Three Parts of an Element In an Array
At the lowest level we have the **Memory Address**. At the hardware level memory addresses are just numbers stored in Binary.  However you will often see memory addresses displayed in Hexadecimal or even just Decimal. This is simply to avoid reading super-long strings of 1's and 0's. In case of these notes, we will use a simplified or pseudo-version of hexadecimal just to express the concept with less friction. 

At the next level we have the **Array Index**. The Array's index is simply an integer value we assign to each element that allows the programmer to more easily interact with the array. 

In most languages *(Including C & Python)* arrays are *Zero-Indexed*, meaning the beginning index of any array begins at 0. In this case, finding the memory address of an element is simply given by:

$Memory Address = Base Address + (Index \times Size)$

Where *BaseAddress* is the memory address of the first element of the array, and *Size* is the size of one element in Binary.

More general equation *(for arrays that aren't zero-indexed)*:
$MemoryAddress = BaseAddress + Size \times (Index - FirstIndex)$

At the final level we have the Array's **Data**. In the diagrams and examples on this page, data will be in the form of a character variable, however it can be any type of variable or even a group of variables (i.e. a Struct in C).

---
####  Diagrams
**Legend:**
| | |
| :---: | :---: |
| Data | The actual value stored |
| Array Index | The index of the element |
| Memory Address | The hex address in memory |

**char_array[]:**

| 'A' | 'B' | 'C' | 'D' | 'E' | 'F' |
| :---: | :---: | :---: | :---: | :---: | :---: |
| 0 | 1 | 2 | 3 | 4 | 5 |
| 0x100 | 0x101 | 0x102 | 0x103 | 0x104 | 0x105 |

This is a diagram of how an array of characters gets stored in memory. It is important to understand the reason an array behaves as it does is because elements are stored sequential in memory, as opposed to its "counterpart", Linked List(s). Each character is stored using one byte.

**int_array[]:**

| 10 | 20 | 30 | 40 | 50 | 60 |
| :---: | :---: | :---: | :---: | :---: | :---: |
| 0 | 1 | 2 | 3 | 4 | 5 |
| 0x100 | 0x104 | 0x108 | 0x112 | 0x116 | 0x120 |

This is a diagram of how an array of integers is stored in memory. Here each integer is stored using four bytes.

**char_array[], index 3 (fourth element):**

| 'D' |
| :---: |
| 3 |
| 0x103 |

**int_array[], index 2 (third element):**

| 30 |
| :---: |
| 2 |
| 0x108 |
---
#### Pros & Cons (Time & Space Complexity)

**Pros:**
When the computer needs to access any element in the array, it simply uses the equation to find where its memory address will be, and then can skip to that memory address. This means retrieving any element in an array is independent from the size of array. This means the Time Complexity of retrieving an element from an array is 
*O(1) => θ(1)*. This is the key advantage to storing the elements sequential in memory.

**Cons:**
The key disadvantage to arrays is that they are fixed in size at compile time. To be able to achieve this O(1) complexity for retrieval of the data within an array, this is necessary. Consider our integer array: 
**int_array[]:**

| 10 | 20 | 30 | 40 | 50 | 60 |
| :---: | :---: | :---: | :---: | :---: | :---: |
| 0 | 1 | 2 | 3 | 4 | 5 |
| 0x100 | 0x104 | 0x108 | 0x112 | 0x116 | 0x120 |

If we wanted to add a 6th element to this array it would have to be at the memory address 0x124, however there is no allocation for 0x124, so this space in memory may be used by any other data the computer may need. To simply add one element to our array in this case actually requires us to copy the elements into a new array, with a larger fixed size. This is an *O(n) => θ(n)* process (see Time Complexity).
**int_array[] (new):**

| 10 | 20 | 30 | 40 | 50 | 60 | 70 |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| 0 | 1 | 2 | 3 | 4 | 5 | 6 |
| 0x200 | 0x204 | 0x208 | 0x212 | 0x216 | 0x220 | 0x224 |

It is important to note that while Dynamically-Allocated Array(s) exist in many programming languages, behind the scenes they still follow this process.

---
