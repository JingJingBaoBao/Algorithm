/*
分治的思想就是把一个大规模的问题分解为若干个规模较小相同子问题，分而治之。
使用分治需满足三个条件：
1. 原问题可以被分解为若干个规模较小的相同子问题
2. 子问题相互独立
3. 子问题的解可以合并为原问题的解
所以分治算法就三步：分解 治理 合并
例：归并排序
*/

#include <iostream>
using namespace std;
void ShowArray(const int arr[], int size);
void Merge(int arr[], int start, int middle, int end);
void MergeSort(int arr[], int start, int end);

int main(void)
{
    const int SIZE = 8;
    int arr[SIZE] = {42, 15, 20, 6, 8, 38, 50, 12};
    ShowArray(arr, SIZE);
    MergeSort(arr, 0, SIZE-1);
    ShowArray(arr, SIZE);

    return 0;
}

void ShowArray(const int arr[], int size)
{
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void Merge(int arr[], int start, int middle, int end)
{
    int * support = new int[end - start + 1];
    int i = start, j = middle + 1, k = 0;
    while (i <= middle && j <= end) {
        if (arr[i] <= arr[j]) {
            support[k++] = arr[i++];
        } 
        else {
            support[k++] = arr[j++];
        }
    }
    while (i <= middle) support[k++] = arr[i++];
    while (j <= end) support[k++] = arr[j++];
    for (int i = start, j = 0; i <= end; i++) {
        arr[i] = support[j++];
    }
    delete[] support;
}

void MergeSort(int arr[], int start, int end)
{
    if (start < end) {
        int middle = (start + end) / 2;
        MergeSort(arr, start, middle);
        MergeSort(arr, middle+1, end);
        Merge(arr, start, middle, end);
    }
}