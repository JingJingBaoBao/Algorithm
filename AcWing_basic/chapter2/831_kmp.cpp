#include <iostream>

using namespace std;

const int N = 100010, M = 1000010;

int n, m;

int ne[N];
char p[N], s[M];

int main()
{
    cin >> n >> p + 1 >> m >> s + 1;
    
    // 求next过程
    for (int i = 2, j = 0; i <= n; i ++ )
    {
        while (j && p[j + 1] != p[i]) j = ne[j];
        if (p[j + 1] == p[i]) j ++ ;
        ne[i] = j;
    }
    
    // KMP匹配过程
    for (int i = 1, j = 0; i <= m; i ++ )
    {
        while (j && s[i] != p[j + 1]) j = ne[j];
        if (s[i] == p[j + 1]) j ++;
        if (j == n)
        {
            cout << i - n << ' ';
            j = ne[j];
        }
    }
    
    return 0;
}