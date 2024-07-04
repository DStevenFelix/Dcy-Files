#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int N = 110;
int a, b, c; // 容器容量
bool st[N][N]; // 状态是否出现过
struct Node {
    int x, y; // 容器中的水量
    string path; // 操作序列
};

string bfs() {
    queue<Node> q;
    q.push({ 0, 0, "" });
    st[0][0] = true;

    while (!q.empty()) {
        auto t = q.front();//在循环中，从队列中弹出一个节点 t，表示当前的状态。
        q.pop();

        int x = t.x, y = t.y;
        if (x == c || y == c) return t.path;//获取当前状态的 A 和 B 容器中的水量值，若其中任意一个等于目标值 c，则返回当前状态 t 中的操作序列 path。

        // 倒满A
        if (!st[a][y]) {
            st[a][y] = true;
            q.push({ a, y, t.path + "FILL(A)\n" });
        }
        // 倒满B
        if (!st[x][b]) {
            st[x][b] = true;
            q.push({ x, b, t.path + "FILL(B)\n" });
        }
        // 清空A
        if (!st[0][y]) {
            st[0][y] = true;
            q.push({ 0, y, t.path + "DROP(A)\n" });
        }
        // 清空B
        if (!st[x][0]) {
            st[x][0] = true;
            q.push({ x, 0, t.path + "DROP(B)\n" });
        }
        // A倒入B
        int k = min(x, b - y);
        if (!st[x - k][y + k]) {
            st[x - k][y + k] = true;
            q.push({ x - k, y + k, t.path + "POUR(A,B)\n" });
        }
        // B倒入A
        k = min(y, a - x);
        if (!st[x + k][y - k]) {
            st[x + k][y - k] = true;
            q.push({ x + k, y - k, t.path + "POUR(B,A)\n" });
        }
    }

    return "No solution";
}

int main() {
    cin >> a >> b >> c;
    cout << bfs() << endl;
    return 0;
}


/*bfs 函数使用广度优先搜索（BFS）算法来找到能够达到目标状态的操作序列。
首先创建一个队列 q，并将初始状态（A 容器中为 0，B 容器中为 0）加入队列中，同时将初始状态标记为已访问。


根据题目中给出的操作规则进行不同的操作： 
被访问过，则将 A 容器中装满水，并将新状态加入队列，并将操作序列更新。
倒满 B：如 容器还没有被访问过，则将 B 容器中装满水，并将新状态加入队列，并将操作序列更新。
清空 A：如果 A 容器还没有被访问过，则将 A 容器清空，并将新状态加入队列，并将操作序更新。
清空 B：如 容器还没有被访问过，则将 B 容器清空，并将新状态加入队列，并将操作序列更新。
A 倒入 B：计算出能够从 A 容器倒入 容器的水量，如果新状态还没有被访问过，则执行倒水操作，并将新状态加入队列，并将操作序列更新。
B 倒入 A：计算出能够从 B 容器倒入 A 容器的水量，如果新状态还没有被访问过，则执行倒水操作，并将新状态加入队列，并将操作序列更新。
如果循环结束后仍未找到符合条件的操作序列，则返回字符串 "No solution" 表示无解。
在 main 函数中，首先读取输入的 a、b 和 c 值。
调用 bfs 函数来寻找满足目标状态的操作序列，并将结果输出。

*/