def showArray(arr):
    for i in arr:
        print(i, end=' ')
    print()

def partition(arr, start, end):
    i, j, pivot = start, end, arr[start]
    while i < j:
        while i < j and arr[j] > pivot:
            j -= 1
        if i < j:
            arr[i], arr[j] = arr[j], arr[i]
            i += 1
        while i < j and arr[i] <= pivot:
            i += 1
        if i < j:
            arr[i], arr[j] = arr[j], arr[i]
            j -= 1
    return i

def quickSort(arr, start, end):
    if start < end:
        middle = partition(arr, start, end)
        quickSort(arr, start, middle-1)
        quickSort(arr, middle+1, end)

def main():
    arr = [42, 15, 20, 6, 8, 38, 50, 12]
    showArray(arr)
    quickSort(arr, 0, len(arr)-1)
    showArray(arr)
    
if __name__ == "__main__":
    main()