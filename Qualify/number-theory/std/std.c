#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

void solve() {
    int n, k;
    scanf("%d %d", &n, &k);
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int x;
        scanf("%d", &x);
        if (x % k == 0) {
            ans = gcd(ans, x / k);
        }
    }
    if (ans == 1) {
        puts("YES");
    } else {
        puts("NO");
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}