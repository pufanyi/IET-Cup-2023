#include <iostream>
#include <algorithm>

#include "testlib.h"

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    const int seed = std::atoi(argv[1]);
    const int n = std::atoi(argv[2]);
    rnd.setSeed(seed);
    std::cout << n << '\n';
    for (int i = 0; i < n; ++i) {
        std::cout << rnd.next(1, 1'000'000'000) << " \n"[i == n - 1];
    }
    return 0;
}