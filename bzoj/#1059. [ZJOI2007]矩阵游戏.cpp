#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

#define up(i, a, b) for (register int i = a; i <= b; ++i)

const int MAXN = 300 + 10;

inline int SlowRead() {
    register int data = 0, w = 1;
    register char ch = 0;
    while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
    if (ch == '-') w = -1, ch = getchar();
    while (ch >= '0' && ch <= '9') {
        data = data * 10 + ch - '0';
        ch = getchar();
    }
    return data * w;
}

int n;
int edges[MAXN][MAXN];

inline void addEdge(int from, int to) {
	// edges[from][to] = edges[to][from] = 1;
	edges[from][to] = 1;
}

int vis[MAXN], match[MAXN];

inline bool find(int from) {
    up(i, 1, n) {
        if (vis[i] || !edges[from][i]) continue;
        vis[i] = 1;
        if (match[i] == 0 || find(match[i])) {
            match[i] = from;
            return 1;
        }
    }
    return 0;
}

inline bool check() {
    memset(match, 0, sizeof match);
    up(i, 1, n) {
        memset(vis, 0, sizeof vis);
        if (!find(i)) return 0;
    }
    return 1;
}

int main(int argc, char *const argv[]) {
    int T = SlowRead();

    while (T-- > 0) {
        memset(edges, 0, sizeof edges);
        n = SlowRead();
        up(i, 1, n) up(j, 1, n) if (SlowRead()) addEdge(i, j);
        printf(check() ? "Yes\n" : "No\n");
    }
    
    return 0;
}
