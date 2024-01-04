#include <array>
#include <vector>
#include <iostream>

constexpr int maxn = 10000;
constexpr int MAP_SIZE = 4;

std::vector<int> primes;
std::vector<int> last_primes;
int is_prime[maxn];
char mp[MAP_SIZE][MAP_SIZE];
char ans[MAP_SIZE][MAP_SIZE];

bool check_prime(int x) {
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

bool check_last(int x) {
    for (int i = 0; i < MAP_SIZE; ++i) {
        int digit = x % 10;
        if (digit != 1 && digit != 3 && digit != 7 && digit != 9) {
            return false;
        }
    }
    return true;
}

bool fill_row(int x, int row) {
    for (int i = MAP_SIZE - 1; i >= 0; --i) {
        if (ans[row][i] == '.') {
            ans[row][i] = x % 10 + '0';
        } else if (ans[row][i] != x % 10 + '0') {
            return false;
        }
        x /= 10;
    }
    return true;
}

bool roll_back_row(int row) {
    for (int i = 0; i < MAP_SIZE; ++i) {
        if (ans[row][i] != '.') {
            ans[row][i] = '.';
            return true;
        }
    }
    return false;
}

bool fill_col(int x, int col) {
    for (int i = MAP_SIZE - 1; i >= 0; --i) {
        if (ans[i][col] == '.') {
            ans[i][col] = x % 10 + '0';
        } else if (ans[i][col] != x % 10 + '0') {
            return false;
        }
        x /= 10;
    }
    return true;
}

const int dfs_opt = {3, 3, 0, 0, 1, 2};


void dfs(int depth) {
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    for (int i = 2; i <= 10000; ++i) {
        if (check_prime(i)) {
            is_prime[i] = 1;
            primes.push_back(i);
            if (check_last(i)) {
                last_primes.push_back(i);
            }
        }
    }
    for (auto &s: mp) {
        std::cin >> s;
    }
    return 0;
}