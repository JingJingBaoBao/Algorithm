/*
训练 士兵队列训练
某部队进行新兵队列训练，将新兵从一开始按顺序依次编号，并排成一行横队。
训练的规则为从头开始进行1至2报数，凡报2的出列，剩下的向小序号方向靠拢，
再从头开始进行1至3报数，凡报到3的出列，剩下的向小序号方向靠拢，
继续从头开始进行1至2报数……以后从头开始轮流进行1至2报数、1至3报数，直到剩下的人数不超过3人时为止。
输入：包含多个测试用例，第1行为测试用例数N，接着为N行新兵人数（不超过5 000）。
输出：单行输出剩下的新兵的最初编号，编号之间有一个空格。
*/

#include <cstdio>
#include <list>
using namespace std;

int main(void)
{
    int T, n;
    list<int>a;
    list<int>::iterator it;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        a.clear();
        int k = 2;
        for (int i = 1; i < n; i++) {
            a.push_back(i);
        }
        while (a.size() > 3) {
            int cnt = 1;
            for (it = a.begin(); it!= a.end();) {
                if (cnt++ % k == 0) {
                    it = a.erase(it); // it 指向下一个地址
                }
                else {
                    it++;
                }
            }
            k = (k == 2 ? 3 : 2);
        }
        for (it = a.begin(); it != a.end(); it++) {
            if(it != a.begin()) {
                printf(" ");
            }
            printf("%d", *it);
        }
        printf("\n");
    }

    return 0;
}

/*
    测试用例        输出样例
    2
    20              1 7 19
    40              1 19 37

*/