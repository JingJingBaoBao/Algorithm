/*
    快排在大规模数据排序中，速度要远远大于其他7种常用排序算法
    快排的思路：
    1.分解：取出数组中的一个元素作为基准元素，将数组分为左右两部分，小于基准在左，大于基准在右
    2.治理：对两个子序列进行快排
    3.合并：将两个有序序列合并
*/
#include <iostream>
using namespace std;
void ShowArray(const int arr[], int size);
int Partition(int arr[], int start, int end);
int Partition2(int arr[], int start, int end);

void QuickSort(int arr[], int start, int end);

int main(void)
{
    const int SIZE =8;
    int arr[SIZE] = {42, 15, 20, 6, 8, 38, 50, 12};
    ShowArray(arr, SIZE);
    QuickSort(arr, 0, SIZE);
    ShowArray(arr, SIZE);
    return 0;
}

int Partition(int arr[], int start, int end)
{
    int i = start, j = end, pivot = arr[start];
    while (i < j)
    {
        while (i < j && arr[j] > pivot) j--;
        if (i < j) {
            swap(arr[i++], arr[j]);
        }
        while (i < j && arr[i] <= pivot) i++;
        if (i < j) {
            swap(arr[i], arr[j--]);
        }
    }
    return i;
}

void QuickSort(int arr[], int start, int end)
{
    if (start < end) {
        int middle = Partition(arr, start, end);
        QuickSort(arr, start, middle - 1);
        QuickSort(arr, middle+1, end);
    }
}
void ShowArray(const int arr[], int size)
{
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
/*
算法分析：
时间复杂度：平均情况 O(nlogn)
空间复杂度：平均情况 O(logn)
算法还可以继续优化
*/

int Partition2(int arr[], int start, int end)
{
    int i = start, j = end, pivot = arr[start];
    while (i < j) {
        while (i < j && arr[j] > pivot) j--;
        while (i < j && arr[i] >= pivot) i++;
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }
    if (arr[i] > pivot) {
        swap(arr[i-1], arr[start]);
        return i-1;
    }
    swap(arr[i], arr[start]);
    return i;

}