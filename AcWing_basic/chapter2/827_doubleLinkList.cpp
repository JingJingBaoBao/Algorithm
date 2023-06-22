#include <iostream>

using namespace std;

const int N = 100010;

int m;
int head, l[N], r[N], e[N], idx;

void init()
{
    r[0] = 1;  // 1是右端点
    l[1] = 0;  // 0是左端点
    idx = 2;  // idx此时已经用掉两个点了
}

// 在节点k的右边插入一个数x
void insert(int k, int x)
{
    e[idx] = x;
    l[idx] = k;
    r[idx] = r[k];
    l[r[k]] = idx;
    r[k] = idx ++ ;
}

// 删除节点k
void remove(int k)
{
    l[r[k]] = l[k];
    r[l[k]] = r[k];
}

int main()
{
    init();
    cin >> m;

    string op;

    while (m -- )
    {
        cin >> op;
        if (op == "L")
        {
            int x;
            cin >> x;
            insert(0, x);
        }
        else if (op == "R")
        {
            int x;
            cin >> x;
            insert(l[1], x);  // 下标从2开始，第k个插入，对应的下标是k+1
        }
        else if (op == "D")
        {
            int k;
            cin >> k;
            remove(k + 1);
        }
        else if (op == "IL")
        {
            int k, x;
            cin >> k >> x;
            insert(l[k + 1], x);
        }
        else {
            int k, x;
            cin >> k >> x;
            insert(k + 1, x);
        }
    }

    // 虽然表面上是从r[0]开始，实际idx是从第二个元素开始遍历的
    for (int i = r[0]; i != 1; i = r[i])  cout << e[i] << ' ';

    return 0;
}