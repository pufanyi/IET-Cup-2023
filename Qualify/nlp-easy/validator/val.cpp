#include <string>

#include "testlib.h"

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int T = inf.readInt(1, 1'000'000, "T");
    inf.readEoln();
    int sum_n = 0;
    while (T--) {
        std::string s = inf.readString("[a-z]{1,100000}", "s");
        sum_n += (int) s.size();
    }
    inf.readEof();
    ensuref(sum_n <= 1'000'000, "sum of n exceeds 100'000");
    return 0;
}
