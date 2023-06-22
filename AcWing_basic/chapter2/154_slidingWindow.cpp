#include <iostream>

using namespace std;

const int N = 1000010;

int n, k;
int a[N], q[N];  // q是单调队列，存最大最小值的下标

// 滑动窗口，使用单调队列
int main()
{
    cin >> n >> k;

    for (int i = 0; i < n; i ++ ) cin >> a[i];

    // 求最小值
    int hh = 0, tt = -1;
    for (int i = 0; i < n; i ++ )
    {
        // 判断队头是否滑出窗口：队头元素是否在从i开始的前k个元素中
        if (hh <= tt && q[hh] < i - k + 1) hh ++ ;
        while (hh <= tt && a[q[tt]] >= a[i]) tt --;  // 队尾元素大于等于当前元素

        q[ ++ tt] = i;
        // 从第k个数输出
        if (i + 1 >= k) cout << a[q[hh]] << ' ';
    }
    puts("");
    // 求最大值
    hh = 0, tt = -1;
    for (int i = 0; i < n; i ++ )
    {
        if (hh <= tt && i - k + 1 > q[hh]) hh ++ ;  // 判断队头是否滑出窗口
        while (hh <= tt && a[q[tt]] <= a[i]) tt --;  // a[i]是当前值

        q[ ++ tt] = i;
        // 从第k个数输出
        if (i >= k - 1) cout << a[q[hh]] << ' ';
    }
    puts("");

    return 0;
}