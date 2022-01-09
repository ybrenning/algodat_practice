def binary_search(arr: list[int], val: int) -> int:
    l = 0
    r = len(arr) - 1
    mid = r // 2

    while l <= r:
        if arr[mid] == val:
            return mid
        elif arr[mid] < val:
            l = mid + 1
            mid = l + ((r - l) // 2)
        elif arr[mid] > val:
            r = mid - 1
            mid = l + ((r - l) // 2)
    return -1


def binary_search_rec(arr: list[int], val: int, l: int, r: int) -> int:
    mid = l + (r - l) // 2

    if arr[mid] == val:
        return mid
    elif l == r:
        return -1
    elif arr[mid] < val:
        l = mid + 1
        return binary_search_rec(arr, val, l, r)
    else:
        r = mid - 1
        return binary_search_rec(arr, val, l, r)
