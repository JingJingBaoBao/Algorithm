#include <iostream>

using namespace std;

const int N = 1000010;

int n, k;
int a[N], q[N];  // q�ǵ������У��������Сֵ���±�

// �������ڣ�ʹ�õ�������
int main()
{
    cin >> n >> k;

    for (int i = 0; i < n; i ++ ) cin >> a[i];

    // ����Сֵ
    int hh = 0, tt = -1;
    for (int i = 0; i < n; i ++ )
    {
        // �ж϶�ͷ�Ƿ񻬳����ڣ���ͷԪ���Ƿ��ڴ�i��ʼ��ǰk��Ԫ����
        if (hh <= tt && q[hh] < i - k + 1) hh ++ ;
        while (hh <= tt && a[q[tt]] >= a[i]) tt --;  // ��βԪ�ش��ڵ��ڵ�ǰԪ��

        q[ ++ tt] = i;
        // �ӵ�k�������
        if (i + 1 >= k) cout << a[q[hh]] << ' ';
    }
    puts("");
    // �����ֵ
    hh = 0, tt = -1;
    for (int i = 0; i < n; i ++ )
    {
        if (hh <= tt && i - k + 1 > q[hh]) hh ++ ;  // �ж϶�ͷ�Ƿ񻬳�����
        while (hh <= tt && a[q[tt]] <= a[i]) tt --;  // a[i]�ǵ�ǰֵ

        q[ ++ tt] = i;
        // �ӵ�k�������
        if (i >= k - 1) cout << a[q[hh]] << ' ';
    }
    puts("");

    return 0;
}