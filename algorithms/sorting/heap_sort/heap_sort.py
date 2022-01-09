def max_heapify(arr: list[int], size: int, index: int) -> None:
    largest = index
    left = (index * 2) + 1
    right = (index * 2) + 2

    if left < size and arr[largest] < arr[left]:
        largest = left
    if right < size and arr[largest] < arr[right]:
        largest = right

    if largest != index:
        arr[largest], arr[index] = arr[index], arr[largest]
        max_heapify(arr, size, largest)


def heap_sort(arr: list[int]) -> None:
    n = len(arr)
    for i in range(n // 2 - 1, -1, -1):
        max_heapify(arr, n, i)

    for i in range(n - 1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]
        max_heapify(arr, i, 0)
