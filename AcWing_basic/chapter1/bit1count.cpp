#include <iostream>

using namespace std;

const int N = 100010;

// 求一个数的二进制表示中，最后一位 1 的位置，返回一个二进制数
// 等价 ~x + 1
int lowbit(int x)
{
    return x & -x;
}

// 求二进制中 1 的个数
int main()
{
    int n;
    cin >> n;
    
    while (n -- )
    {
        int x, res = 0;
        cin >> x;

        while (x) x -= lowbit(x), res ++ ;  // 每次减去 x 的最后一位 1
        cout << res << ' ';
    }

    return 0;
}