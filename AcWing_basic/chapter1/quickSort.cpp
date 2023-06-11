#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int n;
int q[N];

// 快速排序
// l, r 是两端点，i, j 是两指针
void quick_sort(int q[], int l, int r) {
    // 递归结束条件
    if (l >= r) return;

    // 1.确定分界点
    int x = q[l + r >> 1];

    // 2.使用 i, j 调整区间
    int i = l - 1, j = r + 1;  // 注意区间范围
    while (i < j) {
        do i++; while (q[i] < x);
        do j--; while (q[j] > x);
        if (i < j) swap(q[i], q[j]);
    }

    // 3.递归处理左右两端
    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) scanf("%d ", &q[i]);

    quick_sort(q, 0, n - 1);

    for (int j = 0; j < n; j++) printf("%d ", q[j]);

    return 0;
}