#include <cstdint>

#include "testlib.h"

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    const int seed = std::atoi(argv[1]);
    const int n = std::atoi(argv[2]);
    const int m = std::atoi(argv[3]);
    rnd.setSeed(seed);
    std::cout << n << ' ' << m << '\n';
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; j++) {
            std::cout << rnd.next(0, INT32_MAX) << " \n"[j == m - 1];
        }
    }
    return 0;
}