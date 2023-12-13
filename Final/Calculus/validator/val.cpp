#include "testlib.h"

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int T = inf.readInt(1, 100, "T");
    inf.readEoln();
    for (int i = 0; i < T; ++i) {
        int l = inf.readInt(-100, 100, "l_i");
        inf.readSpace();
        inf.readInt(l, 100, "r_i");
        inf.readEoln();
    }
    inf.readEof();
    return 0;
}
