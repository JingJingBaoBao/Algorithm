/*
贪心的思想就是总是做出当前最好的选择，期望通过局部最优选择得到全局最优的解决方案。
当问题有贪心选择性质和最优子结构的时候，可用贪心算法。

例：最优装载问题
有一搜海盗船，载重为c, 每件宝物的重量为w_i，要装最多的宝物上船。

思路：w_i越小 可装的就越多 依次选最小重量的古董 直到装不下为止
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    const int N = 8;
    const int C = 30;
    int w[N] = {4, 10, 7, 11, 3, 5, 14, 2};

    sort(w, w + N);
    double tmp = 0.0;
    int total = 0;
    for (int i = 0; i < N; i++) {
        if (tmp + w[i] <= C) {
            tmp += w[i];
            total++;
        }
        else {
            break;
        }
    }
    cout << "total = " << total << endl;

    return 0;
}

/*
选 2 3 4 5 7装的最多
算法分析：
时间复杂度：调了sort函数 O(nlogn)
空间复杂度：只使用了几个辅助变量 O(1)
*/