#include <cstdint>

#include "testlib.h"

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(1, 500, "n");
    inf.readSpace();
    int m = inf.readInt(1, 500, "m");
    inf.readEoln();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; j++) {
            inf.readInt(0, INT32_MAX, "a_ij");
            if (j < m - 1) {
                inf.readSpace();
            }
        }
        inf.readEoln();
    }
    inf.readEof();
    return 0;
}