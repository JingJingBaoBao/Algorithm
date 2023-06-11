#include <iostream>

using namespace std;

const int N = 100010;

int n, m;
int q[N];

int main() 
{
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i < n; i ++) scanf("%d ", &q[i]);
    
    while (m -- )
    {
        int k;
        scanf("%d", &k);
        int l = -1, r = n;  // 双指针
        while (l + 1 != r)  // l 和 r 相邻结束循环
        {
            int mid = l + r >> 1;
            // 第一个 >= 的下标
            if (q[mid] >= k) r = mid;
            else l = mid;
        }
        
        if (q[r] != k) printf("-1 -1\n");
        else 
        {
            printf("%d ", r);
            int ll = -1, rr = n;
            while (ll + 1 != rr)
            {
                int mid = ll + rr >> 1;
                // 第二个 <= 的下标
                if (q[mid] <= k) ll = mid;
                else rr = mid;
            }
            if (q[ll] != k) printf("%d\n", r);
            else printf("%d\n", ll);
        }
        
    }
    
    return 0;
}