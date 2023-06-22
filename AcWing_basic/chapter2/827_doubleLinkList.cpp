#include <iostream>

using namespace std;

const int N = 100010;

int m;
int head, l[N], r[N], e[N], idx;

void init()
{
    r[0] = 1;  // 1���Ҷ˵�
    l[1] = 0;  // 0����˵�
    idx = 2;  // idx��ʱ�Ѿ��õ���������
}

// �ڽڵ�k���ұ߲���һ����x
void insert(int k, int x)
{
    e[idx] = x;
    l[idx] = k;
    r[idx] = r[k];
    l[r[k]] = idx;
    r[k] = idx ++ ;
}

// ɾ���ڵ�k
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
            insert(l[1], x);  // �±��2��ʼ����k�����룬��Ӧ���±���k+1
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

    // ��Ȼ�������Ǵ�r[0]��ʼ��ʵ��idx�Ǵӵڶ���Ԫ�ؿ�ʼ������
    for (int i = r[0]; i != 1; i = r[i])  cout << e[i] << ' ';

    return 0;
}