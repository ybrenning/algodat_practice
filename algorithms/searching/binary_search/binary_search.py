def binary_search(arr, val):
    l = 0
    r = len(arr) - 1
    mid = r // 2

    while l <= r:
        if arr[mid] < val:
            l = mid + 1
            mid = l + ((r - l) // 2)
        elif arr[mid] > val:
            r = mid - 1
            mid = l + ((r - l) // 2)
        else:
            return arr[mid]
    return -1
