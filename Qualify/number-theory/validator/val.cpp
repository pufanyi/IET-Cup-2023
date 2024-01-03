#include "testlib.h"

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(1, 100000, "n");
    inf.readSpace();
    int k = inf.readInt(1, 1000000000, "k");
    inf.readEoln();
    for (int i = 1; i <= n; ++i) {
        inf.readInt(1, 1000000000, "x");
        inf.readSpace();
    }
    inf.readEoln();
    inf.readEof();
    return 0;
}
