#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int N = 300010;  // n �β���� m �β�ѯ������������Ͻ�

int a[N], s[N];  // a -- �洢��Ҫ�����ֵ��s -- ǰ׺��
int n, m;  // n �β��룬m �β�ѯ
vector<PII> add, query;
vector<int> alls;  // �洢�����������Ͳ�ѯ�йصģ�����

// ���������������ɢ���±�
int find(int x)
{
    int l = 0, r = alls.size() - 1;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (alls[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return r + 1;  // + 1 ��Ϊ����ǰ׺�ʹ� 1 ��ʼ����
}

int main()
{   
    cin >> n >> m;
    for (int i = 0; i < n; i ++ ) 
    {
        int x, c;
        cin >> x >> c;
        add.push_back({x, c});  // ��λ�� x �ϵ����� c

        alls.push_back(x);  // ����ɢ������������ɢ + �ظ���
    }
    
    // ѡ������
    for (int i = 0; i < m; i ++ )  // m �β�ѯ
    {
        int l, r;
        cin >> l >> r;
        query.push_back({l, r});  // ѯ�� [l, r] ֮��ĺ�

        alls.push_back(l), alls.push_back(r);
    }

    // ȥ�أ�����Ͳ�ѯ�������ڸ������У���ֻ�Ǵ洢����ɢ������±�
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());

    // ִ�� n �β���
    for (auto item : add) 
    {
        int x = find(item.first);
        a[x] += item.second;
    }
    
    // ǰ׺��
    for (int i = 1; i <= alls.size(); i ++ ) s[i] = s[i - 1] + a[i];
    
    // ���� m ��ѯ��
    for (auto item : query)
    {
        int l = find(item.first), r = find(item.second);
        cout << s[r] - s[l - 1] << endl;
    }

    return 0;
}
