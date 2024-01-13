// This code do not use convex hull.
// If you want to know more about how to calculate a convex hull and its area, you can see this problem: http://poj.org/problem?id=3348.


#include <tuple>
#include <vector>
#include <utility>
#include <iomanip>
#include <iostream>

using LF = long double;

using Point2D = std::pair<LF, LF>;
using Point3D = std::tuple<LF, LF, LF>;

Point2D project(const Point3D &p1, const Point3D &p2) {
    const auto &[x1, y1, z1] = p1;
    const auto &[x2, y2, z2] = p2;
    LF x = x1 - z1 * (x1 - x2) / (z1 - z2);
    LF y = y1 - z1 * (y1 - y2) / (z1 - z2);
    return {x, y};
}

LF calc_area(const Point2D &p1, const Point2D &p2) {
    return std::abs(p1.first * p2.second - p1.second * p2.first) / 2.0;
}

LF calc_area(const std::vector<Point2D> &p) {
    LF ans = 0;
    for (decltype(p.size()) i = 0; i < p.size(); ++i) {
        ans += calc_area(p[i], p[(i + 1) % p.size()]);
    }
    return ans;
}

void solve() {
    int a, b, c, x, y, z;
    std::cin >> a >> b >> c >> x >> y >> z;
    if (b <= y && x <= a) {
        std::swap(a, b);
        std::swap(x, y);
    }
    std::vector<Point2D> p;

    auto proj = [&](const Point3D &p) -> Point2D {
        return project({x, y, z}, p);
    };

    if (x >= a && y >= b) {
        p = {
                proj({0, 0, c}),
                proj({a, 0, c}),
                {a, 0},
                {a, b},
                {0, b},
                proj({0, b, c}),
        };
    } else if (x >= a) {
        p = {
                proj({0, 0, c}),
                proj({a, 0, c}),
                {a, 0},
                {a, b},
                proj({a, b, c}),
                proj({0, b, c}),
        };
    } else {
        p = {
                proj({0, 0, c}),
                proj({a, 0, c}),
                proj({a, b, c}),
                proj({0, b, c}),
        };
    }

    std::cout << std::fixed << std::setprecision(10) << calc_area(p) << '\n';
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
