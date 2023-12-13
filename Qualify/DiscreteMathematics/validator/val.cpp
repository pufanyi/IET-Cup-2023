#include "testlib.h"

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    constexpr long long L = 1, R = 1e18;
    inf.readLong(L, R, "n");
    inf.readEoln();
    inf.readEof();
    return 0;
}
