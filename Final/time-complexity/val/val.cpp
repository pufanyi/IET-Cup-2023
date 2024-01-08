#include "testlib.h"

int main() {
    registerValidation();
    inf.readLong(1, (long long) 1e18, "n");
    inf.readEoln();
    inf.readEof();
    return 0;
}