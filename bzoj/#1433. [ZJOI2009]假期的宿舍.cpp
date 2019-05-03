#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

#define up(i, a, b) for (register int i = a; i <= b; ++i)

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

const int MAXN = 100 + 10;

int n;
int edges[MAXN][MAXN];
int data[MAXN][MAXN];

inline void addEdge(int from, int to) { edges[from][to] = edges[to][from] = 1; }

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

bool issch[MAXN];
bool ghome[MAXN];

int sum;

inline void check() {
    memset(match, 0, sizeof match);
    up(i, 1, n) {
        if (!issch[i] || (issch[i] && !ghome[i])) {
        	memset(vis, 0, sizeof vis);
        	if (find(i)) sum++;
    	}
    }
}

inline void clear() {
	sum = 0;
	memset(issch, 0, sizeof issch);
	memset(ghome, 0, sizeof ghome);
	memset(edges, 0, sizeof edges);
	memset(data , 0, sizeof data );
}

int main(int argc, char *const argv[]) {
	int T = SlowRead();
	
    while (T --> 0) {
    	clear();
    	n = SlowRead();
    	up(i, 1, n) issch[i] = SlowRead();
    	up(i, 1, n) ghome[i] = SlowRead();
    	up(i, 1, n) up(j, 1, n) data[i][j] = SlowRead();

    	int cnt = 0;
    	up(i, 1, n) {
    	    if (!ghome[i] && issch[i]) addEdge(i, i);
    	    if (!issch[i] || (issch[i] && !ghome[i])) cnt++;
    	    up(k, 1, n) if (data[i][k] && issch[k]) addEdge(i, k);
    	}
    	check();
    	std::cerr << "DEBUG: sum = " << sum << ", cnt = " << cnt << std::endl;
    	printf(sum == cnt ? "^_^\n" : "T_T\n");
    }
}
