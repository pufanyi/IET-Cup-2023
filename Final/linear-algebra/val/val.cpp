#include <cstdint>

#include "testlib.h"

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int T = inf.readInt(1, 100, "T");
    std::cout << T << '\n';
    while (T--) {
        int a = inf.readInt(1, 1000, "a");
        inf.readSpace();
        int b = inf.readInt(1, 1000, "b");
        inf.readSpace();
        int c = inf.readInt(1, 1000, "c");
        inf.readEoln();
        int x = inf.readInt(1, 1000, "x");
        inf.readSpace();
        int y = inf.readInt(1, 1000, "y");
        inf.readSpace();
        int z = inf.readInt(1, 1000, "z");
        inf.readEoln();
        ensure(z > c);
    }
    inf.readEof();
    return 0;
}