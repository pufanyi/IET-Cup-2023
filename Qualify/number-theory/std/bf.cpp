#include <vector>
#include <numeric>
#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n, k;
    std::cin >> n >> k;
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
            return 0;
        }
    }
    std::cout << "No\n";
    return 0;
}