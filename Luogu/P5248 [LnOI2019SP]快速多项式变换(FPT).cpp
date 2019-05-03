#include <iostream>
#include <cstdio>

typedef long long ll;

const int MAXN = 100000 + 1000;

ll cnt, m, result;
ll a[MAXN];

int main (int argc, char *const argv[]) {
    scanf("%lld%lld", &m, &result);

    while(result) a[++cnt] = result % m, result /= m;

    printf("%d\n", cnt);

    for(int i = 1; i <= cnt; i++) printf("%lld%c", a[i], i == cnt ? '\n' : ' ');
    return 0;
}