def showArray(arr):
    for i in arr:
        print(i, end=' ')
    print()

def merge(arr, start, middle, end):
    tmp = []
    i, j, k = start, middle+1, start
    while i <= middle and j <= end:
        if arr[i] <= arr[j]:
            tmp.append(arr[i])
            i += 1
        else:
            tmp.append(arr[j])
            j += 1
    while i <= middle:
        tmp.append(arr[i])
        i += 1
    while j <= end:
        tmp.append(arr[j])
        j += 1
    for i in range(len(tmp)):
        arr[k] = tmp[i]
        k += 1
    

def mergeSort(arr, start, end):
    if not start == end:
        middle = (start + end) // 2
        mergeSort(arr, start, middle)
        mergeSort(arr, middle+1, end)
        merge(arr, start, middle, end)

def main():
    arr = [42, 15, 20, 6, 8, 38, 50, 12]
    showArray(arr)
    mergeSort(arr, 0, len(arr)-1)
    showArray(arr)
    
if __name__ == "__main__":
    main()