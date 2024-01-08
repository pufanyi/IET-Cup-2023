#include <cstdlib>
#include <iostream>

#include "testlib.h"

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int seed = std::atoi(argv[1]);
    rnd.setSeed(seed);
    long long ans = 0;
    for (int i = 0; i < 9; ++i) {
        ans *= 10;
        if (rnd.next(0, 1)) {
            ans += 6;
        } else {
            ans += rnd.next(0, 9);
        }
    }
    std::cout << ans << '\n';
    return 0;
}