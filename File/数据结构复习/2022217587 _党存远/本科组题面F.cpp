#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 10005;

int n, w[MAXN];
struct Edge {
    int v;
    int next;
} e[MAXN << 1];
int head[MAXN], cnt;

void add(int u, int v) {
    e[++cnt].v = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

int f[MAXN][5];

void dfs(int u, int fa) {
    f[u][1] = w[u];
    f[u][0] = 0;
    for (int i = head[u]; i; i = e[i].next) {
        int v = e[i].v;
        if (v == fa) continue;
        dfs(v, u);
        f[u][1] += f[v][3];
        f[u][2] += max(f[v][2], f[v][3]);
        f[u][3] += max(f[v][1], max(f[v][2], f[v][3]));
    }
}

int main() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    memset(f, 0, sizeof(f));
    dfs(1, 0);
    cout << max(max(f[1][1], f[1][2]), f[1][3])+1 << endl;
    return 0;
}


