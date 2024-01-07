#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>

using LL = long long;
using LF = long double;

constexpr int maxn = (int) 2e5 + 5;

LL a[maxn];
LL sum[maxn];

LL get_sum(int l, int r) {
    return sum[r] - sum[l - 1];
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }
    std::sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + a[i];
    }
    LF ans = 0;

    auto calc_mean = [&](int mid, int gs, int type) {
        if (type == 0) {
            return (LF) (get_sum(mid - gs, mid - 1) + a[mid] + get_sum(n - gs + 1, n)) / (LF) (gs * 2 + 1);
        } else {
            return (LF) (get_sum(mid - gs, mid - 1) + get_sum(n - gs + 1, n) + a[mid] + a[mid + 1]) / (LF) (gs * 2 + 2);
        }
    };

    for (int mid = 1; mid <= n; ++mid) {
        int l = 0, r = std::min(mid - 1, n - mid);
        while (l < r) {
            int mid_1 = (2 * l + r) / 3;
            int mid_2 = (2 * r + l + 2) / 3;
            LF mean_1 = calc_mean(mid, mid_1, 0);
            LF mean_2 = calc_mean(mid, mid_2, 0);
            if (mean_1 < mean_2) {
                l = mid_1 + 1;
            } else {
                r = mid_2 - 1;
            }
        }
        ans = std::max(ans, calc_mean(mid, l, 0) - a[mid]);
        l = 0, r = std::min(mid - 1, n - mid - 1);
        while (l < r) {
            int mid_1 = (2 * l + r) / 3;
            int mid_2 = (2 * r + l + 2) / 3;
            LF mean_1 = calc_mean(mid, mid_1, 1);
            LF mean_2 = calc_mean(mid, mid_2, 1);
            if (mean_1 < mean_2) {
                l = mid_1 + 1;
            } else {
                r = mid_2 - 1;
            }
        }
        ans = std::max(ans, calc_mean(mid, l, 1) - (LF) (a[mid] + a[mid + 1]) / 2.0L);
    }
    std::cout << std::fixed << std::setprecision(10) << ans << '\n';
    return 0;
}