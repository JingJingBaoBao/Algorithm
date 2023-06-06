/*
题目描述（POJ1915）：写程序，计算骑士从一个位置移动到另一个位置所需的最少移动次数。骑士移动的规则如dx dy。
输入：输入的第1行为测试用例的个数N。每个测试用例都包含3行。第1行表示棋盘的长度L（4≤L≤300），棋盘的大小为L×L；
第2行和第3行包含一对{0,…,L-1}×{0,…,L-1}的整数，表示骑士在棋盘上的起始位置和结束位置。假设这些位置是该棋盘上的有效位置。
输出：对于每个测试用例，都单行输出骑士从起点移动到终点所需的最少移动次数。如果起点和终点相等，则移动次数为零。

dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2}
dy[8] = {1, -1, 2, -2, 2, -2, 1, -1}
*/

#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int maxn = 310;
int bfs();

int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {1, -1, 2, -2, 2, -2, 1, -1};
bool vis[maxn][maxn];
int sx, sy, ex, ey, tx, ty, L;

struct point {
    int x, y;
    int step;
};

int bfs()
{
    if (sx == ex && sy == ey) {
        return 0;
    }
    memset(vis, false, sizeof(vis));
    queue <point> Q;
    point start, node;
    start.x = sx;
    start.y = sy;
    start.step = 0;
    Q.push(start);
    int step, x, y;
    while (!Q.empty()) {
        start = Q.front();
        Q.pop();
        x = start.x;
        y = start.y;
        step = start.step;
        printf("x = %d y = %d step = %d\n", x, y, step);
        for (int i = 0; i < 8; i++) {
            tx = x + dx[i];
            ty = y + dy[i];
            if (tx == ex && ty == ey) {
                return step + 1;
            }
            if (tx >= 0 && tx < L && ty >= 0 && ty < L && !vis[tx][ty]) {
                node.x = tx;
                node.y = ty;
                node.step = step + 1;
                Q.push(node);
                vis[tx][ty] = true;
            }
        }
    }
    return 0;
}
int main(void)
{
    int N;
    scanf("%d", &N);
    while (N--) {
        scanf("%d", &L);
        scanf("%d%d", &sx, &sy);
        scanf("%d%d", &ex, &ey);
        printf("%d\n", bfs());

    }
    return 0;
}

/*
测试用例    输出
3           5
8           28
0 0         0
7 0
100
0 0
30 50
10
1 1
1 1
*/