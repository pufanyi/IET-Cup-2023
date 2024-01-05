#include <string>

#include "testlib.h"

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(1, 1000, "n");
    inf.readSpace();
    int m = inf.readInt(1, 1000, "m");
    inf.readEoln();
    std::string s = inf.readToken("[A-Za-z0-9+/]{0, 1000000}", "s");
    inf.readEoln();
    inf.readEof();
    size_t len = (n * m + 5) / 6;
    ensuref(s.length() == len, "s.length() == %zu, expected %zu", s.size(), len);
    return 0;
}
