#include "testlib.h"

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    constexpr int max_length = (int) 1e5;
    inf.readString("[a-z]{1," + std::to_string(max_length) + "}", "s");
    inf.readEof();
    return 0;
}
