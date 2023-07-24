#include <iostream>

using namespace std;

const int N = 100010;
int son[N][26], cnt[N], idx;
char str[N];

void insert(char str[])
{
    int p = 0;  // 指向当前节点
    for (int i = 0; str[i]; i ++ )
    {
        int u = str[i] - 'a';
        if (!son[p][u]) son[p][u] = ++ idx;  // 创建节点
        p = son[p][u];  // 使“p指针”指向下一个节点
    }
    cnt[p] ++;  // 结束标记，记录以此节点结束的字符串个数
}    

int query(char str[])
{
    int p = 0;
    for (int i = 0; str[i]; i ++ )
    {
        int u = str[i] - 'a';
        if (!son[p][u]) return 0;
        p = son[p][u];
    }
    return cnt[p];  // 返回字符串p出现的次数
}

int main()
{
    int n;
    cin >> n;
    
    while (n -- )
    {
        char op[2];
        
        scanf("%s%s", op, str);
        if (*op == 'I') insert(str);
        else printf("%d\n", query(str));
    }
    return 0;
}

