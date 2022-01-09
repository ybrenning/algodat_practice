def merge(arr: list[int], left: int, mid: int, right: int) -> None:
    # Copy left and right sub-arrays
    arr_l = arr[left:mid+1]
    arr_r = arr[mid+1:right+1]

    i = j = 0
    k = left
    # Compare elements of sub-arrays
    while i < len(arr_l) and j < len(arr_r):
        if arr_l[i] <= arr_r[j]:
            arr[k] = arr_l[i]
            i += 1
        elif arr_l[i] > arr_r[j]:
            arr[k] = arr_r[j]
            j += 1
        k += 1

    # Copy remaining elements of whichever
    # sub-array was not fully copied
    while i < len(arr_l):
        arr[k] = arr_l[i]
        i += 1
        k += 1
    while j < len(arr_r):
        arr[k] = arr_r[j]
        j += 1
        k += 1


def merge_sort(arr: list[int], left: int, right: int) -> None:
    # If the sub-array is more
    # than one element long
    if left < right:
        mid = left + ((right - left) // 2)
        # Recursively sort each half
        merge_sort(arr, left, mid)
        merge_sort(arr, mid + 1, right)
        # Merge the sorted halves
        merge(arr, left, mid, right)
