#archivo python para ordenar un arreglo de números enteros en Python

import random
from time import sleep
def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        # Track if any swaps occur; if not, array is sorted
        swapped = False
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True
        # If no swaps occurred, array is sorted
        if not swapped:
            print("Array is sorted")
            break

def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

def selection_sort(arr):
    n = len(arr)
    for i in range(n):
        min_idx = i
        # Find the minimum element in the unsorted portion
        for j in range(i + 1, n):
            if arr[j] < arr[min_idx]:
                min_idx = j
        # Swap the found minimum with the first unsorted element
        arr[i], arr[min_idx] = arr[min_idx], arr[i]
        print("Array is sorted")

def quicksort(arr):
    def _quicksort(low, high):
        if low < high:
            # Partition index
            p = partition(low, high)
            # Recursively sort elements before and after partition
            _quicksort(low, p - 1)
            _quicksort(p + 1, high)
            print()

    def partition(low, high):
        pivot = arr[high]  # Choose rightmost as pivot
        i = low - 1       # Index of smaller element
        for j in range(low, high):
            if arr[j] <= pivot:
                i += 1
                arr[i], arr[j] = arr[j], arr[i]
        # Place pivot after the last smaller element
        arr[i + 1], arr[high] = arr[high], arr[i + 1]
        return i + 1

    _quicksort(0, len(arr) - 1)
    return arr

def mergesort(arr):
    if len(arr) <= 1:
        return arr
    
    mid = len(arr) // 2
    left = mergesort(arr[:mid])
    right = mergesort(arr[mid:])
    
    result = []
    i = j = 0
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1
    
    # Append remaining elemnts
    result.extend(left[i:])
    result.extend(right[j:])
    print(result) # print the sorted ar
    return result

def heapsort(arr):
    n = len(arr)
    
    def heapify(a, i, n):
        largest = i
        left = 2 * i + 1
        right = 2 * i + 2
        
        if left < n and a[left] > a[largest]:
            largest = left
        if right < n and a[right] > a[largest]:
            largest = right
            
        if largest != i:
            a[i], a[largest] = a[largest], a[i]
            heapify(a, largest, n)
    
    # Build max-heap
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, i, n)
    
    # Extract elements one by one
    for i in range(n - 1, 0, -1):
        arr[0], arr[i] = arr[i], arr[0]
        heapify(arr, 0, i)
    return arr

def selectionsort(arr):
    n = len(arr)
    for i in range(n - 1):
        min_idx = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_idx]:
                min_idx = j
                arr[i], arr[min_idx] = arr[min_idx], arr[i]
                print("Swapped:", arr[i], "with", arr[min_idx])
                print("Array after swap:", arr)
                print("Array after sorting:", arr)
                print("Array after sorting:", arr)

# Test all sorting algorithms
if __name__ == "__main__":
    print("menu de arreglos ordenados")
    print("1. Bubble Sort")
    print("2. Insertion Sort")
    print("3. Selection Sort")
    print("4. Heap Sort")
    print("5. Exit")
    choice = int(input("Enter your choice (1-5): "))
    if choice == 5:
        exit(0)
    test_arr = [64, 34, 25, 12, 22, 11, 90]
    print(f"Original array: {test_arr}")
    
    # Copy for each algorithm (since they sort in-place)
    arr_bubble = test_arr.copy()
    bubble_sort(arr_bubble)
    print(f"Bubble Sort: {arr_bubble}")
    
    arr_insertion = test_arr.copy()
    insertion_sort(arr_insertion)
    print(f"Insertion Sort: {arr_insertion}")
    
    arr_selection = test_arr.copy()
    selection_sort(arr_selection)
    print(f"Selection Sort: {arr_selection}")
    
    arr_quicksort = test_arr.copy()
    quicksort(arr_quicksort)
    print(f"Quicksort: {arr_quicksort}")
    
    arr_mergesort = test_arr.copy()
    mergesort(arr_mergesort)
    print(f"Mergesort: {arr_mergesort}")
    
    arr_heapsort = test_arr.copy()
    heapsort(arr_heapsort)
    print(f"Heapsort: {arr_heapsort}")