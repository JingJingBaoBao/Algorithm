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
        // ���ջ��Ԫ�ش��ڵ��ڵ�ǰ����ջԪ�أ����ջ
        while (tt && stk[tt] >= x) tt --;  // ע����ڵ���
        if (!tt) cout << "-1 " ;  // ջ�գ�û�бȸ�Ԫ��С��ֵ
        else    cout << stk[tt] << ' ';  // ջ��Ԫ�ؾ�������һ������С��Ԫ��
        stk[++ tt] = x;
    }
    return 0;
}