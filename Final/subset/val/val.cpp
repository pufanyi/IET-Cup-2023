#include "testlib.h"

int main() {
    registerValidation();
    int n = inf.readInt(1, 200000, "n");
    inf.readEoln();
    for (int i = 1; i <= n; ++i) {
        inf.readInt(1, 1000000000, "a_i");
        if (i < n) {
            inf.readSpace();
        }
    }
    inf.readEoln();
    inf.readEof();
    return 0;
}