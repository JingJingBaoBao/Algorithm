#include <iostream>

using namespace std;

const int N = 100010;

int a[N], s[N];

// ������ظ�����������
int main()
{
    int n, res = 0;
    cin >> n;

    for (int i = 0, j = 0; i < n; i ++ )
    {
        cin >> a[i];
        ++ s[a[i]];
        while (s[a[i]] > 1) -- s[a[j ++ ]];  // �ȼ�������������
        res = max(res, i - j + 1);
    }
    cout << res;

    return 0;
}