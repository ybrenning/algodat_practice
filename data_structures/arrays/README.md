## Arrays
An array is a collection of items stored at contiguous memory locations. The idea is to store multiple values
of the same type together. A **fixed array** is an array of which the size or length is determined upon intialization.
In languages like C and Java for instance, we can use the primitive array data type to create arrays of a 
specific type such as `int[]` or `char[]`.

A **dynamic array** is an array with a variable size, meaning it automatically grows when we make an insertion
and there is no more space left in the array. It is supplied in standard libraries in many modern programming
languages such as C++ and Java (`std::vector`, `ArrayList<>`). 

Python offers the `list` data type as an implementation of the dynamic array data structure.

### Characteristics
Time complexities:
* Accessing elements: **O(1)**
* Finding elements: **O(n)**
* Insertion/Deletion: **O(n)**

Space complexity: **O(n)**

> Dynamic arrays allow for fast random read access, but adding or removing from anywhere but
> the back of the array requires shifting all other elements over.
