#include <vector>
#include <numeric>
#include <iostream>

void solve() {
    int n, k;
    std::cin >> n >> k;
    if (n > 30) {
        while (true) {
            continue;
        }
    }
    std::vector<int> a(n);
    for (int &x : a) {
        std::cin >> x;
    }
    for (int bt = 0; bt < (1 << n); ++bt) {
        int g = 0;
        for (int i = 0; i < n; ++i) {
            if (bt >> i & 1) {
                g = std::gcd(g, a[i]);
            }
        }
        if (g == k) {
            std::cout << "Yes\n";
            return;
        }
    }
    std::cout << "No\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}