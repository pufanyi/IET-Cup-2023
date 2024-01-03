#include <numeric>
#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n, k;
    std::cin >> n >> k;
    int g = 0;
    for (int i = 1; i <= n; ++i) {
        int x;
        std::cin >> x;
        if (k % x == 0) {
            g = std::gcd(g, x);
        }
    }
    if (g == k) {
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
    }
    return 0;
}