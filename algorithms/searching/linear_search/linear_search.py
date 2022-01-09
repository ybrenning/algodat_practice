def linear_search(arr: list[int], val: int):
    for i in range(len(arr)):
        if arr[i] == val:
            return val
    return -1
