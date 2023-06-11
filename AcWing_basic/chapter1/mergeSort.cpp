#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int n;
int q[N], tmp[N];

// �鲢����
void mergeSort(int q[], int l, int r) {
    // �ݹ����������ֻ�� 0 �� 1 ��Ԫ��
    if (l >= r) return ;
	
    // 1.ȷ���ֽ�㣬�ֳ������⣨������ 1 ��Ԫ��һ�����У�
    int mid = l + r >> 1;

    // 2.�ݹ鴦��������
    mergeSort(q, l, mid), mergeSort(q, mid + 1, r);

    // ���� i j ˫ָ��
    int k = 0, i = l, j = mid + 1;

    // 3.�ϲ�������
    while (i <= mid && j <= r) {
        if (q[i] < q[j]) tmp[k ++ ] = q[i ++ ];
        else tmp[k ++ ] = q[j ++ ];
    }

    // �������������У��Ƿ��ж���Ԫ�أ�δ�����꣩
    while (i <= mid) tmp[k ++ ] = q[i ++ ];
    while (j <= r) tmp[k ++ ] = q[j ++ ];

    // ����ʱ���飬ת�浽ԭ����
    for (int i = l, j = 0; i <= r; i ++, j ++ ) q[i] = tmp[j];
}

int main() {
    
    scanf("%d", &n);

    for (int i = 0; i < n; i ++ ) scanf("%d ", &q[i]);

    mergeSort(q, 0, n - 1);

    for (int j = 0; j < n; j ++ ) printf("%d ", q[j]);

    return 0;
}
