#include <vector>
#include <iostream>
#include <functional>

using LL = long long;

constexpr int maxn = 505;
constexpr LL inf = 0x3f3f3f3f3f3f3f3fLL;

int n, m;
int a[maxn][maxn];
LL sum[maxn][maxn];
LL f[2][maxn][maxn][2];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            std::cin >> a[i][j];
            sum[i][j] = sum[i][j - 1] + a[i][j];
        }
    }

    for (int l = 1; l <= m; ++l) {
        for (int r = l; r <= m; ++r) {
            f[n & 1][l][r][0] = 0;
            f[n & 1][l][r][1] = 0;
        }
    }

    auto get_sum = [](int i, int l, int r) -> LL {
        if (l == 0) {
            return sum[i][r];
        } else {
            return sum[i][r] - sum[i][l - 1];
        }
    };

    for (int i = n - 1; i >= 1; --i) {
        f[i & 1][1][m][0] = f[(i + 1) & 1][1][1][0] + a[i + 1][1];
        f[i & 1][1][m][1] = f[(i + 1) & 1][m][m][1] + a[i + 1][m];
        for (int l = 1; l <= m; ++l) {
            for (int r = m; r >= l; --r) {
                if (l == 1 && r == m) {
                    continue;
                }
                f[i & 1][l][r][0] = std::max(
                    f[(i + 1) & 1][l][l][0] + a[i + 1][l],
                    std::min(
                        l == 1 ? inf : f[i & 1][l - 1][r][0] + a[i][l - 1],
                        r == m ? inf : f[i & 1][l][r + 1][1] + get_sum(i, l + 1, r + 1)
                    )
                );
                f[i & 1][l][r][1] = std::max(
                    f[(i + 1) & 1][r][r][1] + a[i + 1][r],
                    std::min(
                        l == 1 ? inf : f[i & 1][l - 1][r][0] + get_sum(i, l - 1, r - 1),
                        r == m ? inf : f[i & 1][l][r + 1][1] + a[i][r + 1]
                    )
                );
            }
        }
    }

    LL ans = inf;
    for (int i = 1; i <= m; ++i) {
        ans = std::min(ans, f[1][i][i][0] + a[1][i]);
    }
    std::cout << ans << '\n';
    return 0;
}
