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
    
    sort(segs.begin(), segs.end());  // ����˵�����
    
    int st = -2e9, ed = -2e9;  // ed ���������β��st �������俪ͷ
    for (auto seg : segs)
    {
        if (ed < seg.first)  // ��� 1�����������޷��ϲ�
        {
            if (st != -2e9) res.push_back({st, ed});
            st = seg.first, ed = seg.second;  // ά������ 2
        }
        // ��� 2������������Ժϲ�
        else ed = max(ed, seg.second);
    }

    // �洢���һ������
    if (st != -2e9) res.push_back({st, ed});

    segs = res;
}

// ����ϲ�
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