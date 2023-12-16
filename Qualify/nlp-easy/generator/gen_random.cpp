#include <iostream>
#include <algorithm>

#include "testlib.h"

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    const int seed = std::atoi(argv[1]);
    const int n = std::atoi(argv[2]);
    rnd.setSeed(seed);
    std::cout << rnd.next("[a-z]{" + std::to_string(n) + "}") << '\n';
    return 0;
}