#include <iostream>
#include <vector>

using namespace std;

vector<int> highAccuracyAdd(vector<int> &A, vector<int> &B){
    vector<int> C;

    int t = 0;  // ��λ��־λ
    for (int i = 0; i < A.size() || i < B.size(); i ++ ) {
        if (i < A.size()) t += A[i];
        if (i < B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }

    if (t) C.push_back(1);
    return C;  // ���ص���
}

int main() {

    string a, b;  // a = "123456"   b = "789"
    cin >> a >> b;

    vector<int> A, B;
    for (int i = a.size() - 1; i >= 0; i -- ) A.push_back(a[i] - '0');  // A = [6, 5, 4, 3, 2, 1]
    for (int i = b.size() - 1; i >= 0; i -- ) B.push_back(b[i] - '0');  // B = [9, 8, 7]

    auto C = highAccuracyAdd(A, B);  // ��������Ϊ auto �� vector<int> ���

    for (int i = C.size() - 1; i >= 0; i -- ) printf("%d", C[i]);

    return 0;
}