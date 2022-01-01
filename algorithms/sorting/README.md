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

* Time Complexity: **O(n log n)** 
* Space Complexity: **O(n)** 
* Sorting in-place: **No**
* Stable: **Yes**
<br></br>
> Merge Sort is useful for sorting Linked Lists as we can complete the `merge()` operation without extra space.
> It is also used for large amounts of data like in [External Sorting](https://en.wikipedia.org/wiki/External_sorting).

---

### Quick Sort
Quick Sort is a divide and conquer algorithm that picks a so-called pivot-element and partitions
the given array around this element. As a result, there are different versions of Quick Sort that
pick the pivot-element in different ways.
1. Always pick first element
2. Always pick last element
3. Pick a random element
4. Pick the median

The key process is the `partition()` function. The point of this function is to take a
pivot-element `p` of an array `arr` and put `p` at the correct position in the sorted array
such that all elements before `p` are smaller and all elements after are greater.

![Source: GeeksforGeeks](media/QuickSort2.png)
<br></br>

* Time Complexity: **O(n^2) worst case, O(n log n) average case**
* Space Complexity: **O(log n)**
* Sorting in-place: **Yes**
* Stable: **No**

> The time complexity will vary depending on the choice of the pivot-element. 
> Although O(n^2) is the worst case, QuickSort is faster in practice.

> Randomized Quick Sort works well in practice and has a better space complexity than Merge Sort.
