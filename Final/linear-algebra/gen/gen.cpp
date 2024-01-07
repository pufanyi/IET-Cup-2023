#include <vector>
#include <cstdint>
#include <algorithm>

#include "testlib.h"

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    const int seed = std::atoi(argv[1]);
    rnd.setSeed(seed);
    int T = 10000;
    std::cout << T << '\n';
    while (T--) {
        int a = rnd.next(1, 1000);
        int b = rnd.next(1, 1000);
        int c = rnd.next(1, 1000);
        int x = rnd.next(1, 1000);
        int y = rnd.next(1, 1000);
        int z = rnd.next(1, 1000);
        if (c == z) {
            T++;
            continue;
        }
        if (z < c) {
            std::swap(c, z);
        }
        std::cout << a << ' ' << b << ' ' << c << ' ' << x << ' ' << y << ' ' << z << '\n';
    }
    return 0;
}