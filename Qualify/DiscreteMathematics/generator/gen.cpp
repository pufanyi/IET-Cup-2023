#include <atomic>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#include "testlib.h"

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int seed = std::atoi(argv[3]);
    rnd.setSeed(seed);
    using LL = long long;
    LL L = atoll(argv[1]);
    LL R = atoll(argv[2]);
    LL n = rnd.next(L, R);
    std::cout << n << '\n';
    return 0;
}