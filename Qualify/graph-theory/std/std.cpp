#include <set>
#include <vector>
#include <iostream>

constexpr int maxn = 1005;

int n;
int dep[maxn];
int fa[maxn];
int fa_w[maxn];
std::vector<std::pair<int, int>> e[maxn];

void dfs(int u) {
    for (auto [v, w]: e[u]) {
        if (v == fa[u]) {
            continue;
        }
        fa[v] = u;
        fa_w[v] = w;
        dep[v] = dep[u] + 1;
        dfs(v);
    }
}

int get_path(int u, int v) {
    int res = 0;
    while (u != v) {
        if (dep[u] < dep[v]) {
            std::swap(u, v);
        }
        res = std::max(fa_w[u], res);
        u = fa[u];
    }
    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        e[u].emplace_back(v, w);
        e[v].emplace_back(u, w);
    }
    dfs(1);
    int ans = 0;
    for (int u = 1; u <= n; ++u) {
        for (int v = u + 1; v <= n; ++v) {
            ans += get_path(u, v) + 1;
        }
    }
    ans -= n - 1;
    std::cout << ans << '\n';
    return 0;
}