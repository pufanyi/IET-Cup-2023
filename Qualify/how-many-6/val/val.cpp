#include <vector>
#include <utility>
#include <queue>

#include "testlib.h"

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    inf.readInt(0, 999999999, "n");
    inf.readEoln();
    inf.readEof();
    return 0;
}
