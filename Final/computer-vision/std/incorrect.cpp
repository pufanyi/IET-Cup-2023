#include <queue>
#include <cassert>
#include <iostream>

constexpr int maxn = 505;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0 ,0};

int n, m;
int mp[maxn][maxn];

void bfs(int x, int y) {
    std::queue<std::pair<int, int>> q;
    q.emplace(x, y);
    mp[x][y] = 1;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx > n + 1 || ny < 0 || ny > m + 1 || mp[nx][ny] || mp[nx][ny]) {
                continue;
            }
            mp[nx][ny] = 1;
            q.emplace(nx, ny);
        }
    }
}

int main() {
    freopen("in.txt", "r", stdin);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        std::string s;
        std::cin >> s;
        for (int j = 1; j <= m; ++j) {
            if (s[j - 1] == '0') {
                mp[i][j] = 1;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= n + 1; ++i) {
        for (int j = 0; j <= m + 1; ++j) {
            if (mp[i][j]) {
                continue;
            }
            // std::cout << i << ' ' << j << std::endl;
            bfs(i, j);
            ans++;
        }
    }
    // std::cout << ans << std::endl;
    assert(1 <= ans && ans <= 3);
    std::cout << "CAB"[ans - 1] << '\n';
    return 0;
}
