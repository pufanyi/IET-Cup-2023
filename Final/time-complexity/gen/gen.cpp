#include <vector>
#include <cstdint>
#include <algorithm>

#include "testlib.h"

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    const int seed = std::atoi(argv[1]);
    rnd.setSeed(seed);
    long long L = std::atoll(argv[2]);
    long long R = std::atoll(argv[3]);
    std::cout << rnd.next(L, R) << '\n';
    return 0;
}