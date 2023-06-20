#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int N = 300010;  // n 次插入和 m 次查询相关数据量的上界

int a[N], s[N];  // a -- 存储需要插入的值，s -- 前缀和
int n, m;  // n 次插入，m 次查询
vector<PII> add, query;
vector<int> alls;  // 存储（所有与插入和查询有关的）坐标

// 返回输入坐标的离散化下标
int find(int x)
{
    int l = 0, r = alls.size() - 1;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (alls[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return r + 1;  // + 1 是为了求前缀和从 1 开始方便
}

int main()
{   
    cin >> n >> m;
    for (int i = 0; i < n; i ++ ) 
    {
        int x, c;
        cin >> x >> c;
        add.push_back({x, c});  // 在位置 x 上的数加 c

        alls.push_back(x);  // 待离散化的容器（离散 + 重复）
    }
    
    // 选定区间
    for (int i = 0; i < m; i ++ )  // m 次查询
    {
        int l, r;
        cin >> l >> r;
        query.push_back({l, r});  // 询问 [l, r] 之间的和

        alls.push_back(l), alls.push_back(r);
    }

    // 去重，插入和查询操作不在该容器中，它只是存储了离散化后的下标
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());

    // 执行 n 次插入
    for (auto item : add) 
    {
        int x = find(item.first);
        a[x] += item.second;
    }
    
    // 前缀和
    for (int i = 1; i <= alls.size(); i ++ ) s[i] = s[i - 1] + a[i];
    
    // 处理 m 次询问
    for (auto item : query)
    {
        int l = find(item.first), r = find(item.second);
        cout << s[r] - s[l - 1] << endl;
    }

    return 0;
}
