#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int N = 100010;
int n;
vector<PII> segs;

void merge(vector<PII> &segs)
{
    vector<PII> res;
    
    sort(segs.begin(), segs.end());  // 按左端点排序
    
    int st = -2e9, ed = -2e9;  // ed 代表区间结尾，st 代表区间开头
    for (auto seg : segs)
    {
        if (ed < seg.first)  // 情况 1：两个区间无法合并
        {
            if (st != -2e9) res.push_back({st, ed});
            st = seg.first, ed = seg.second;  // 维护区间 2
        }
        // 情况 2：两个区间可以合并
        else ed = max(ed, seg.second);
    }

    // 存储最后一个序列
    if (st != -2e9) res.push_back({st, ed});

    segs = res;
}

// 区间合并
int main()
{
    cin >> n;

    for (int i = 0;i < n; i ++ )
    {
        int l, r;
        cin >> l >> r;
        segs.push_back({l, r});
    }

    merge(segs);

    cout << segs.size() << endl;

    return 0;
}