/**
 * This is the O(n^2) solution using dfs.
 */

#include <iostream>
#include <vector>

constexpr int maxn = 1005;

int n;
long long ans;
std::vector<std::pair<int, int>> e[maxn];

void dfs(int u, int fa, int now_e) { // now_e is the maximum weight of the edge on the path from u to fa
    if (now_e != 0) {
        ans += now_e + 1; // add an edge from i to u with weight now_e + 1
    }
    for (auto [v, w] : e[u]) {
        if (v == fa) {
            continue;
        }
        dfs(v, u, std::max(now_e, w));
    }
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

    for (int i = 1; i <= n; ++i) {
        dfs(i, 0, 0); // add an edge from i to other nodes
    }

    // The code ans / 2 is because we count each edge twice. For example, we add an edge from 1 to 2, and we also add an edge from 2 to 1.
    // The code - n + 1 is because for all edges on tree, the weight is w instead of w + 1.
    std::cout << ans / 2 - n + 1 << '\n';

    return 0;
}
