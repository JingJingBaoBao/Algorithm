//差分 -- 时间复杂度 o(m)
#include<iostream>

using namespace std;

const int N = 1e5 + 10;

int n, m;
int a[N], b[N];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        b[i] = a[i] - a[i - 1];  // 构建差分数组
    }
    int l, r, c;
    while (m -- )
    {
        scanf("%d%d%d", &l, &r, &c);
        b[l] += c;  // 将序列中[l, r]之间的每个数都加上 c
        b[r + 1] -= c;
    }
    for (int i = 1; i <= n; i++)
    {
        a[i] = b[i] + a[i - 1];  // 前缀和运算
        printf("%d ", a[i]);
    }
    return 0;
}