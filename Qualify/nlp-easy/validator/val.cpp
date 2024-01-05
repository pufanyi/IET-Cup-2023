#include <string>

#include "testlib.h"

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int T = inf.readInt(1, 1'000'000, "T");
    inf.readEoln();
    int sum_n = 0;
    while (T--) {
        std::string s = inf.readString();
        sum_n += (int) s.size();
        // std::cerr << s.size() << std::endl;
        ensuref(sum_n <= 100'000, "sum of n exceeds 100'000");
        for (char c : s) {
            ensuref('a' <= c && c <= 'z', "invalid character");
        }
    }
    inf.readEof();
    ensuref(sum_n <= 1'000'000, "sum of n exceeds 100'000");
    return 0;
}
