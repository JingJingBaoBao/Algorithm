#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int n;
int q[N];

// ��������
// l, r �����˵㣬i, j ����ָ��
void quick_sort(int q[], int l, int r) {
    // �ݹ��������
    if (l >= r) return;

    // 1.ȷ���ֽ��
    int x = q[l + r >> 1];

    // 2.ʹ�� i, j ��������
    int i = l - 1, j = r + 1;  // ע�����䷶Χ
    while (i < j) {
        do i++; while (q[i] < x);
        do j--; while (q[j] > x);
        if (i < j) swap(q[i], q[j]);
    }

    // 3.�ݹ鴦����������
    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) scanf("%d ", &q[i]);

    quick_sort(q, 0, n - 1);

    for (int j = 0; j < n; j++) printf("%d ", q[j]);

    return 0;
}