#include "testlib.h"

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int T = inf.readInt(1, 100);
    inf.readEoln();
    for (int i = 0; i < T; ++i) {
        int l = inf.readInt(-100, 100);
        inf.readSpace();
        int r = inf.readInt(l, 100);
        inf.readEoln();
        ensure(l <= r);
    }
    inf.readEof();
    return 0;
}
