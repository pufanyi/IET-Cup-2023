#include <cstdlib>
#include <iostream>

#include "testlib.h"

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int seed = std::atoi(argv[1]);
    rnd.setSeed(seed);
    int n = std::atoi(argv[2]);
    std::vector<std::tuple<int, int, int>> e;
    for (int i = 2; i <= n; ++i) {
        int u = rnd.next(1, i - 1);
        int v = i;
        int w = rnd.next(1, 1000);
        if (rnd.next(0, 1) == 0) {
            std::swap(u, v);
        }
        e.emplace_back(u, v, w);
    }
    shuffle(e.begin(), e.end());
    std::cout << n << '\n';
    for (auto [u, v, w] : e) {
        std::cout << u << ' ' << v << ' ' << w << '\n';
    }
    return 0;
}