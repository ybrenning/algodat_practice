def partition(arr, low, high):
    pivot = arr[high]
    p_index = low

    for i in range(low, high):
        # Place smaller elements to the left
        if arr[i] <= pivot:
            arr[i], arr[p_index] = arr[p_index], arr[i]
            p_index += 1

    # Place pivot element at p_index:
    # We know that all elements to the left of
    # p_index are smaller and right are larger
    arr[high], arr[p_index] = arr[p_index], arr[high]
    return p_index


def quick_sort(arr, low, high):
    # Similar approach to merge sort
    if low < high:
        # Get partition index
        # (Index of pivot-element)
        p = partition(arr, low, high)
        # Split up left and right sides:
        # Left elements of pivot are all smaller
        quick_sort(arr, low, p - 1)
        # Right elements of pivot are larger
        quick_sort(arr, p + 1, high)
