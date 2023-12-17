#include "testlib.h"

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(1, (int) 5e4, "n");
    inf.readSpace();
    inf.readInt(1, (int) 1e9, "k");
    inf.readSpace();
    int q = inf.readInt(1, (int) 1e5, "q");
    inf.readEoln();
    for (int i = 1; i <= n; ++i) {
        inf.readInt(1, (int) 1e6, "x_i");
        inf.readSpace();
        inf.readInt(1, (int) 1e9, "h_i");
        inf.readEoln();
    }
    for (int i = 1; i <= q; ++i) {
        int l = inf.readInt(1, (int) 1e6, "l_i");
        inf.readSpace();
        int r = inf.readInt(1, (int) 1e6, "r_i");
        ensure(l <= r);
        inf.readEoln();
    }
    inf.readEof();
    return 0;
}
