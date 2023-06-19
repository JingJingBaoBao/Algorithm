#include <iostream>

using namespace std;

const int N = 100010;

// ��һ�����Ķ����Ʊ�ʾ�У����һλ 1 ��λ�ã�����һ����������
// �ȼ� ~x + 1
int lowbit(int x)
{
    return x & -x;
}

// ��������� 1 �ĸ���
int main()
{
    int n;
    cin >> n;
    
    while (n -- )
    {
        int x, res = 0;
        cin >> x;

        while (x) x -= lowbit(x), res ++ ;  // ÿ�μ�ȥ x �����һλ 1
        cout << res << ' ';
    }

    return 0;
}