#include <string>

#include "testlib.h"

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(1, 1000, "n");
    inf.readSpace();
    int m = inf.readInt(1, 1000, "m");
    inf.readEoln();
    for (int i = 0; i < n; i++) {
        std::string row = inf.readToken("[0-1]{1,1000}", "row");
        ensure(row.size() == m);
        inf.readEoln();
    }
    inf.readEof();
    return 0;
}
