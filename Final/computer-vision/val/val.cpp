#include <string>

#include "testlib.h"

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(1, 1000, "n");
    inf.readSpace();
    int m = inf.readInt(1, 1000, "m");
    inf.readEoln();
    for (int i = 1; i <= n; ++i) {
        inf.readString("[01]{" + std::to_string(m) + "}", "s");
    }
    inf.readEof();
    return 0;
}
