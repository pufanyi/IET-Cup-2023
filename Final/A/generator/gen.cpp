#include <iostream>
#include <algorithm>

#include "testlib.h"

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int T = atoi(argv[1]);
    int L = atoi(argv[2]);
    int R = atoi(argv[3]);
    std::cout << T << std::endl;
    for (int i = 0; i < T; ++i) {
        int l = rnd.next(L, R);
        int r = rnd.next(L, R);
        if (l > r) {
            std::swap(l, r);
        }
        std::cout << l << " " << r << std::endl;
    }
    return 0;
}