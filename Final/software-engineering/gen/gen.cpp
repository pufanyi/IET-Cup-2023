#include <vector>
#include <cstdint>

#include "testlib.h"

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    const int seed = std::atoi(argv[1]);
    const int n = std::atoi(argv[2]);
    const int m = std::atoi(argv[3]);
    const int lim = std::atoi(argv[4]);
    const int large_num = std::atoi(argv[5]);
    rnd.setSeed(seed);
    std::cout << n << ' ' << m << '\n';
    std::vector<std::vector<int>> a(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; j++) {
            a[i][j] = rnd.next(0, lim);
        }
    }
    for (int i = 0; i < large_num; ++i) {
        int x = rnd.next(0, n - 1);
        int y = rnd.next(0, m - 1);
        a[x][y] = rnd.next(0, INT32_MAX);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; j++) {
            std::cout << a[i][j] << " \n"[j == m - 1];
        }
    }
    return 0;
}