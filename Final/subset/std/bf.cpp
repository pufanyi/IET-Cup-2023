#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>

constexpr int maxn = (int) 2e5 + 5;

using LL = long long;

LL a[maxn];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n = 0;
    double ans = 0;
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }
    std::sort(a + 1, a + n + 1);
    for (int i = 1; i < (1 << n); ++i) {
        std::vector<LL> v;
        int cnt = 0;
        LL sum = 0;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                ++cnt;
                sum += a[j + 1];
                v.push_back(a[j + 1]);
            }
        }
        double mid;
        if (cnt % 2 == 0) {
            mid = (double) (v[cnt / 2 - 1] + v[cnt / 2]) / 2.0;
        } else {
            mid = (double) v[cnt / 2];
        }
        ans = std::max(ans, (double) sum / cnt - mid);
    }
    std::cout << std::fixed << std::setprecision(10) << ans << '\n';
    return 0;
}