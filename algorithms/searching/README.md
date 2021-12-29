## Searching
### Linear Search
Simple approach to searching for a value `val` within an array `arr`.
* Start from leftmost element and one by one compare `val` with each element of `arr`
* If `val` matches with an element, return the index
* If `val` doesn't match with any of the elements, return -1

![Source: TutorialsPoint](media/linear_search.gif)

Time Complexity: **O(n)**
<br> </br>

### Binary Search
Search a sorted array by repeatedly dividing the search interval in half. 
Compare the middle item of the array with `val` and continue searching in the left or
right side depending on if `val` is lesser or more than the middle element.

We basically ignore half of the arr after just one comparison.
* Compare `val` with the middle element
* If `val` matches the middle element, return the mid index
* If `val` is higher than mid, search the right half
* If `val` is lesser than mid, search the left half

![Source: Medium](media/binary_search.png)

Time Complexity: **O(log n)** \
Space Complexity: **O(1)**
> Keep in mind the array must be already sorted in ascending order 
> for binary search to work.

**More on binary search:**
* [MyCodeSchool](https://www.youtube.com/watch?v=j5uXyPJ0Pew&ab_channel=mycodeschool)
* [GeeksforGeeks](https://www.geeksforgeeks.org/binary-search/)