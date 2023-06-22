#include <iostream>

using namespace std;

const int N = 100010;

int n;
int stk[N], tt;

int main()
{
    cin >> n;
    while (n -- )
    {
        int x;
        cin >> x;
        // 如果栈顶元素大于等于当前待入栈元素，则出栈
        while (tt && stk[tt] >= x) tt --;  // 注意大于等于
        if (!tt) cout << "-1 " ;  // 栈空，没有比该元素小的值
        else    cout << stk[tt] << ' ';  // 栈顶元素就是左侧第一个比它小的元素
        stk[++ tt] = x;
    }
    return 0;
}