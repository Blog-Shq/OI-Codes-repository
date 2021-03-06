/*
 * Author: Shq
 *
 * My Blog: https://blog.ishq.site/
 *
 * Real Artists simplify.
 */

#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("O2")

#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <ext/rope>
#include <functional>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <streambuf>

#include <bitset>
#include <complex>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

const double eps = 1e-8;
const double pi = acos(-1.0);
const long long INF = 0x3f3f3f3f;

typedef long long ll;
typedef long double lb;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;

template <class size_T>
size_T min(size_T a, size_T b) {
    return a < b ? a : b;
}
template <class size_T>
size_T max(size_T a, size_T b) {
    return a > b ? a : b;
}
template <class size_T>
size_T abs(size_T a) {
    return (a + (a >> 31)) ^ (a >> 31);
}

#define All(x) x.begin(), x.end()
#define endl '\n'

#define until(x) while (!(x))

#define up(a, b, c) for (register int a = b; a <= c; a++)
#define down(a, b, c) for (register int a = b; a >= c; a--)
#define lup(a, b, c) for (register ll a = b; a <= c; a++)
#define ldown(a, b, c) for (register ll a = b; a >= c; a--)

#define lowbit(x) ((x) & (-x))
#define mem(a) memset(a, 0, sizeof(a))
#define Fedges(x) for (register int i = head[x]; i; i = edges[i].next)

#define ctz(x) __builtin_ctz(x)  // the number of zeros at the end of number
#define clz(x) __builtin_clz(x)  // the number of zeros at the begin of number
#define popcnt(x) __builtin_popcount(x)  // the number of ones in the number
#define parity(x) __builtin_parity(x)  // the parity(odd or even) of the number

#define Cin(x) (scanf(lld, &x))
#define Cout(x) (printf(lld, x))

#define debug(...) fprintf(stderr, __VA_ARGS__)
#define DEBUG printf("Passing [%s] in LINE %d\n", __FUNCTION__, __LINE__)
#define Debug debug("Passing [%s] in LINE %d\n", __FUNCTION__, __LINE__)

#define fastCE (std::ios::sync_with_stdio(0), std::cin.tie(0))

#if ((_WIN32 || __WIN32__) && __cplusplus < 201103L)
#define lld "%I64d"
#else
#define lld "%lld"
#endif

/*
template <class T> std::ostream &operator << (std::ostream& os, std::vector<T>
V) { os << "DEBUG: vector is ["; for (auto vv : V) {os << vv; putchar (',');}
    return os << "]" << endl;
}
*/

void print() {}
template <typename T, typename... Types>
void print(const T &firstArg, const Types &... args) {
    std::cout << firstArg << endl;
    print(args...);
}

void input() {}
template <typename T, typename... Types>
void input(T &firstArg, Types &... args) {
    std::cin >> firstArg;
    input(args...);
}

template <class L, class R>
std::ostream &operator<<(std::ostream &os, std::pair<L, R> P) {
    return os << "(" << P.first << "," << P.second << ")";
}

#define File(x)                       \
    freopen("" #x ".in", "r", stdin); \
    freopen("" #x ".out", "w", stdout);

namespace Math {
#ifndef __Shq_Math_Mul_INT64__
#define __Shq_Math_Mul_INT64__
#endif
#ifndef __Shq_Math_Pow_INT64__
#define __Shq_Math_Pow_INT64__
ll pow(ll a, ll b, const ll &HA) {
    register ll ans = 1;
    while (b) {
        if (b & 1) ans = (ans * a) % HA;
        a = (a * a) % HA;
        b >>= 1;
    }
    return ans % HA;
}
#endif
#undef __Shq_Math_Pow_INT64__
#undef __Shq_Math_Mul_INT64__
}  // namespace Math

namespace fastIO {
#ifndef __FAST_IO__
#define __FAST_IO__
#define __FastIO_BUF_SIZE__ 100000
#define __FastIO_OUT_SIZE__ 100000
#define ll long long

bool __FastIO_Data_error__ = 0;
inline char __Fread_Getchar__() {
    static char __FastIO_buf__[__FastIO_BUF_SIZE__],
        *__first__ = __FastIO_buf__ + __FastIO_BUF_SIZE__,
        *pend = __FastIO_buf__ + __FastIO_BUF_SIZE__;
    if (__first__ == pend) {
        __first__ = __FastIO_buf__;
        pend = __FastIO_buf__ +
               fread(__FastIO_buf__, 1, __FastIO_BUF_SIZE__, stdin);
        if (pend == __first__) {
            __FastIO_Data_error__ = 1;
            return -1;
        }
    }
    return *__first__++;
}

inline bool blank(char __Input_Char__) {
    return __Input_Char__ == ' ' || __Input_Char__ == '\n' ||
           __Input_Char__ == '\r' || __Input_Char__ == '\t';
}

inline void __FastIO_read__(int &x) {
    register bool sign = 0;
    register char __Input_Char__ = __Fread_Getchar__();
    x = 0;
    for (; blank(__Input_Char__); __Input_Char__ = __Fread_Getchar__())
        ;
    if (__FastIO_Data_error__) return;
    if (__Input_Char__ == '-') sign = 1, __Input_Char__ = __Fread_Getchar__();
    for (; __Input_Char__ >= '0' && __Input_Char__ <= '9';
         __Input_Char__ = __Fread_Getchar__())
        x = x * 10 + __Input_Char__ - '0';
    sign && (x = -x);
}

inline void __FastIO_read__(ll &x) {
    register bool sign = 0;
    register char __Input_Char__ = __Fread_Getchar__();
    x = 0;
    for (; blank(__Input_Char__); __Input_Char__ = __Fread_Getchar__())
        ;
    if (__FastIO_Data_error__) return;
    if (__Input_Char__ == '-') sign = 1, __Input_Char__ = __Fread_Getchar__();
    for (; __Input_Char__ >= '0' && __Input_Char__ <= '9';
         __Input_Char__ = __Fread_Getchar__())
        x = x * 10 + __Input_Char__ - '0';
    sign && (x = -x);
}

inline void Print(ll v) {
    if (v < 0) {
        putchar('-');
        v = -v;
    }
    if (v > 9) Print(v / 10);
    putchar(v % 10 + '0');
}

inline ll SlowRead() {
    register char __Input_Char__ = 0;
    register ll __Input_Data__ = 0, __Data_Symbol__ = 1;
    while (__Input_Char__ != '-' and
           (__Input_Char__ < '0' || __Input_Char__ > '9'))
        __Input_Char__ = getchar();
    if (__Input_Char__ == '-') __Data_Symbol__ = -1, __Input_Char__ = getchar();
    while (__Input_Char__ >= '0' and __Input_Char__ <= '9') {
        __Input_Data__ = __Input_Data__ * 10 + __Input_Char__ - '0';
        __Input_Char__ = getchar();
    }
    return __Input_Data__ * __Data_Symbol__;
}

#undef ll
#undef __FastIO_OUT_SIZE__
#undef __FastIO_BUF_SIZE__
#endif
};  // namespace fastIO

namespace Graph {
#ifndef __Shq_Graph_Edge__
#define __Shq_Graph_Edge__
struct Edge {
    int to, next;
    int dist;

    Edge() {}
    Edge(int to, int next, int dist) : to(to), dist(dist), next(next) {}

    ~Edge() {}
};
#endif
};  // namespace Graph

using namespace fastIO;
// using namespace Graph;
using namespace Math;

#define read SlowRead

const int MAXN = 1000000 + 100;

struct Edge {
    int to;
    // int dist;

    Edge() {}
    // Edge (int _to, int _dist) : to(_to) , dist(_dist) {}
    Edge(int _to) : to(_to) {}
};

std::vector<Edge> edges[MAXN];

// inline void addEdge (int u, int v, int w) {
//     edges[u].push_back(Edge(v, w));
// }

inline void addEdge(int u, int v) {
    edges[u].push_back(Edge(v));
    edges[v].push_back(Edge(u));
}

ll n;

ll ans;
ll sum[MAXN];
ll siz[MAXN];

inline void dfs1(int from, int fa) {
    siz[from] = 1;
    for (auto &e : edges[from])
        if (e.to != fa) {
            dfs1(e.to, from);
            sum[from] += sum[e.to] + siz[e.to];
            siz[from] += siz[e.to];
        }
}

void dfs2(int from, int fa) {
    if (from != 1) sum[from] += sum[fa] - sum[from] - siz[from] + n - siz[from];
    if (sum[from] > sum[ans] || (sum[from] == sum[ans] && from < ans))
        ans = from;
    for (auto &e : edges[from])
        if (e.to != fa) dfs2(e.to, from);
}

int main(int argc, char const *argv[]) {
    n = SlowRead();

    // int u, v;
    up(i, 1, n - 1) addEdge(SlowRead(), SlowRead());

    dfs1(1, 0);
    dfs2(1, 0);

    Print(ans);
    return 0;
}
