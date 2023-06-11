#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int n;
int q[N], tmp[N];

// 归并排序
void mergeSort(int q[], int l, int r) {
    // 递归结束条件：只有 0 或 1 个元素
    if (l >= r) return ;
	
    // 1.确定分界点，分成子问题（最终是 1 个元素一个序列）
    int mid = l + r >> 1;

    // 2.递归处理子问题
    mergeSort(q, l, mid), mergeSort(q, mid + 1, r);

    // 定义 i j 双指针
    int k = 0, i = l, j = mid + 1;

    // 3.合并子问题
    while (i <= mid && j <= r) {
        if (q[i] < q[j]) tmp[k ++ ] = q[i ++ ];
        else tmp[k ++ ] = q[j ++ ];
    }

    // 鉴定两个序列中，是否有多余元素（未遍历完）
    while (i <= mid) tmp[k ++ ] = q[i ++ ];
    while (j <= r) tmp[k ++ ] = q[j ++ ];

    // 将临时数组，转存到原数组
    for (int i = l, j = 0; i <= r; i ++, j ++ ) q[i] = tmp[j];
}

int main() {
    
    scanf("%d", &n);

    for (int i = 0; i < n; i ++ ) scanf("%d ", &q[i]);

    mergeSort(q, 0, n - 1);

    for (int j = 0; j < n; j ++ ) printf("%d ", q[j]);

    return 0;
}
