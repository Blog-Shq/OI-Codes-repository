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
#pragma GCC optimize("Ofast")

#include <functional>
#include <streambuf>
#include <algorithm>
#include <ext/rope>
#include <iostream>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <iomanip>
#include <cctype>
#include <cstdio>
#include <cmath>
#include <ctime>

#include <complex>
#include <vector>
#include <bitset>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>

const double eps = 1e-8;
const double pi	= acos(-1.0);
const long long INF = 0x3f3f3f3f;

typedef long long ll;
typedef long double lb;
typedef unsigned long long ull;
typedef std::pair <int, int> pii;

template <class size_T> size_T min (size_T a, size_T b) {return a < b ? a : b;}
template <class size_T> size_T max (size_T a, size_T b) {return a > b ? a : b;}
template <class size_T> size_T abs (size_T a) {return (a + (a >> 31)) ^ (a >> 31);}

#define All(x) x.begin(), x.end()
#define endl '\n'

#define until(x) while (!(x))

#define up(a,b,c) for (register int a = b; a <= c; a++)
#define down(a,b,c) for (register int a = c; a >= b; a--)
#define lup(a,b,c) for (register ll a = b; a <= c; a++)
#define ldown(a,b,c) for (register ll a = c; a >= b; a--)

#define lowbit(x) ((x) & (-x))
#define mem(a) memset (a, 0, sizeof (a))
#define Fedges(x) for (register int i = head[x]; i; i = edges[i].next)

#define ctz(x) __builtin_ctz(x) //the number of zeros at the end of number
#define clz(x) __builtin_clz(x) //the number of zeros at the begin of number
#define popcnt(x) __builtin_popcount(x) //the number of ones in the number
#define parity(x) __builtin_parity(x) //the parity(odd or even) of the number

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
template <class T> std::ostream &operator << (std::ostream& os, std::vector<T> V) {
    os << "DEBUG: vector is [";
    for (auto vv : V) {os << vv; putchar (',');}
    return os << "]" << endl;
}
*/

void print() {}
template <typename T, typename ...Types>
void print (const T& firstArg, const Types& ...args) {
    std::cout << firstArg << endl;
    print (args...);
}

void input() {}
template <typename T, typename ...Types>
void input (T& firstArg, Types& ...args) {
    std::cin >> firstArg;
    input (args...);
}

template <class L, class R> std::ostream &operator << (std::ostream &os, std::pair<L,R> P) {
    return os << "(" << P.first << "," << P.second << ")";
}

#define File(x) freopen(""#x".in","r",stdin);    \
                freopen(""#x".out","w",stdout);

namespace Math {
#ifndef __Shq_Math_Mul_INT64__
#define __Shq_Math_Mul_INT64__
    inline ll mul(ll a, ll b, const ll &__Math_Mod__) {
        a = (a % __Math_Mod__ + __Math_Mod__) % __Math_Mod__; b = (b % __Math_Mod__ + __Math_Mod__) % __Math_Mod__;
        register ll c = a * (lb) b / __Math_Mod__;
        register ll ans = a * b - c * __Math_Mod__;
        ans < 0 ? ans += __Math_Mod__ : (ans >= __Math_Mod__) && (ans -= __Math_Mod__);
        return ans;
    }
#endif
#ifndef __Shq_Math_Pow_INT64__
#define __Shq_Math_Pow_INT64__
    ll pow (ll a, ll b, const ll &HA) {
	    register ll ans = 1;
	    while(b) {
		    if (b & 1) ans = (ans * a) % HA;
		    a = (a * a) % HA; b >>= 1;
	    }
    	return ans % HA;
    }
#endif
#undef __Shq_Math_Pow_INT64__
#undef __Shq_Math_Mul_INT64__
}

namespace fastIO {
#ifndef __FAST_IO__
#define __FAST_IO__
#define __FastIO_BUF_SIZE__ 100000
#define __FastIO_OUT_SIZE__ 100000
#define ll long long

    bool __FastIO_Data_error__ = 0;
    inline char __Fread_Getchar__() {
        static char __FastIO_buf__[__FastIO_BUF_SIZE__],*__first__=__FastIO_buf__+__FastIO_BUF_SIZE__,*pend=__FastIO_buf__+__FastIO_BUF_SIZE__;
        if (__first__ == pend) {
            __first__=__FastIO_buf__; pend=__FastIO_buf__ + fread(__FastIO_buf__,1,__FastIO_BUF_SIZE__,stdin);
            if (pend == __first__) {__FastIO_Data_error__ = 1; return -1;}
        }
        return *__first__++;
    }

    inline bool blank(char ch) {return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';}

    inline void __FastIO_read__(int &x) {
        register bool sign = 0; register char ch = __Fread_Getchar__(); x = 0;
        for (;blank(ch); ch = __Fread_Getchar__());
        if (__FastIO_Data_error__) return;
        if (ch == '-') sign = 1, ch = __Fread_Getchar__();
        for (;ch >= '0' && ch <= '9'; ch = __Fread_Getchar__()) x = x * 10 + ch - '0';
        sign && (x = -x);
    }

    inline void __FastIO_read__(ll &x) {
        register bool sign = 0; register char ch = __Fread_Getchar__(); x = 0;
        for (;blank(ch); ch = __Fread_Getchar__());
        if (__FastIO_Data_error__) return;
        if (ch == '-') sign = 1, ch = __Fread_Getchar__();
        for (;ch >= '0' && ch <= '9'; ch = __Fread_Getchar__()) x = x * 10 + ch - '0';
        sign && (x = -x);
    }

    inline void Print (ll v) {
        if (v < 0) { putchar('-'); v = -v; }
        if (v > 9) Print (v / 10);
        putchar (v % 10 + '0');
    }

    inline ll SlowRead () {
        register char ch = 0; register ll __Input_Data__ = 0, f = 1;
        while (ch != '-' and (ch < '0' || ch > '9')) ch = getchar();
        if (ch == '-') f = -1, ch = getchar();
        while (ch >= '0' and ch <= '9') {
            __Input_Data__ = __Input_Data__ * 10 + ch - '0';
            ch = getchar();
        }
        return __Input_Data__ * f;
    }

#undef ll
#undef __FastIO_OUT_SIZE__
#undef __FastIO_BUF_SIZE__
#endif
};

using namespace fastIO;
using namespace Math;

#define read SlowRead

struct Edge {
    int to, dist;
    int from;

    Edge () {}
    Edge (int _from, int _to, int _dist) : from(_from) , to(_to) , dist(_dist) {}

    ~Edge () {}

    bool operator < (const Edge &other)const {
        return dist < other.dist;
    }
};

const int MAXN = 100010;

int tot;
Edge edges[MAXN];

inline void addEdge (int u, int v, int w) {
    edges[tot++] = Edge(u, v, w);
}

ll n;
ll data[MAXN];

int fa[MAXN];

inline void init () {
    up (i, 1, n) fa[i] = i;
}

inline int find (int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

inline void merge (int x, int y) {
    fa[x] = y;
}

int main(int argc, char const *argv[]) {
    srand(time(NULL) + rand()); srand(time(NULL) + rand() + rand() * rand()); srand(time(NULL) + rand() + rand() ^ rand() * rand());
    while (rand() & 1) n = rand() * rand();
    n = SlowRead();

    ll tmp = n + 1;

    up (i, 1, n) data[i] = SlowRead();

    int w;
    up (u, 1, n)
        up (v, 1, n) {
            w = SlowRead();
            addEdge (u, v, w);
        }
    
    up (i, 1, n) addEdge (i, tmp, data[i]);

    std::sort (edges, edges + tot);

    init();

    int ans = 0;
    up (i, 0, tot - 1) {
        //printf("%d->%d is %d\n", edges[i].from, edges[i].to, edges[i].dist);
        int fx = find(edges[i].from);
        int fy = find(edges[i].to);
        if (fx != fy) {
            merge (fx, fy);
            ans += edges[i].dist;
        }
    }

    Print(ans);
    return 0;
}
