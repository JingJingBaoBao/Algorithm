#include <iostream>
#include <vector>

using namespace std;

// A >= B
bool cmp(vector<int> &A, vector<int> &B) {
    if (A.size() != B.size()) return A.size() > B.size();
    for (int i = A.size() - 1; i >= 0; i -- ) {
        if (A[i] != B[i])
            return A[i] > B[i];
    }
    return true;
}

vector<int> sub(vector<int> &A, vector<int> &B) {
    vector<int> C;
    
    // high - high
    for (int i = 0, t = 0; i < A.size(); i ++ ) {  // borrow a seat flag
        t = A[i] - t;
        if (i < B.size()) t -= B[i];
        // t >= 0  ---> t
        // t < 0   ---> t + 10
        C.push_back((t + 10) % 10);  
        if (t < 0) t = 1;
        else t = 0;
    }
    
    // erease pre 0
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

int main() {
    string a, b;  // a = "123456"
    cin >> a >> b;
    
    vector<int> A, B;
    
    for (int i = a.size() - 1; i >= 0; i -- ) A.push_back(a[i] - '0');  // A = [6, 5, 4, 3, 2, 1]
    for (int i = b.size() - 1; i >= 0; i -- ) B.push_back(b[i] - '0');

    for (int i = 0; i < A.size(); i ++ ) cout << A[i] << ' ';
    
    if (cmp(A, B)) {  // big sub small
        auto C = sub(A, B);
        
        for (int i = C.size() - 1; i >= 0; i -- ) printf("%d", C[i]);
    }
    else {  // small sub big
        auto C = sub(B, A);
        
        cout << '-';  // negative
        
        for (int i = C.size() - 1; i >= 0; i -- ) printf("%d", C[i]);
    }
    
    return 0;
}