#include <set>

#include "testlib.h"

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(1, 100000, "n");
    inf.readSpace();
    inf.readInt(1, 1000000000, "k");
    inf.readEoln();
    std::set<int> st;
    for (int i = 1; i <= n; ++i) {
        int x = inf.readInt(1, 1000000000, "x");
        inf.readSpace();
        ensuref(st.find(x) == st.end(), "duplicate x");
        st.insert(x);
    }
    inf.readEoln();
    inf.readEof();
    return 0;
}
