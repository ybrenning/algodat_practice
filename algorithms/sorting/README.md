## Sorting

--- 

### Insertion Sort
Simple sorting algorithm that works similar to sorting a deck of cards in your hands.
The array is "split" into a sorted and unsorted part, such that values from the unsorted part are picked
one by one and placed at the correct position in the sorted part.

![Source: Introduction to Algorithms](media/insertion_sort_cards.png)
<br></br>

* Iterate from second element to end of array
* Compare the current element to the predecessor
* If it is smaller, compare it to the elements before the predecessor and move the greater elements 
to the right to make space
<br></br>

![Source: Introduction to Algorithms](media/insertion_sort.png)
<br></br>

* Time Complexity: **O(n^2^)** 
* Space Complexity: **O(1)** 
* Sorting in-place: **Yes** 
* Stable: **Yes**
<br></br>
> Insertion Sort is useful on arrays with small amounts of elements or when the input array is almost sorted.

---
### Merge Sort
Merge Sort is a divide and conquer algorithm which divides the input array into
two halves, calls itself for these two halves and merges the sorted arrays.
The `merge()` function is used for merging two sorted halves.

* Find the middle point to divide the array
* Call `mergesort()` on left half
* Call `mergesort()` on right half
* Call `merge()` on the two sorted halves

![Source: Wikipedia](media/merge_sort_wiki.png)
<br></br>

* Time Complexity: **O(n log n)** \
* Space Complexity: **O(n)** \
* Sorting in-place: **No**
* Stable: **Yes**
<br></br>
> Merge Sort is useful for sorting Linked Lists as we can complete the `merge()` operation without extra space.
> It is also used for large amounts of data like in [External Sorting](https://en.wikipedia.org/wiki/External_sorting).

---

### Quick Sort