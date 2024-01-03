#include <set>

#include "testlib.h"

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int T = inf.readInt(1, 1000000, "T");
    inf.readEoln();
    int sum_n = 0;
    while (T--) {
        int n = inf.readInt(1, 100000, "n");
        sum_n += n;
        ensuref(sum_n <= 1000000, "sum of n exceeds 1000000");
        inf.readSpace();
        inf.readInt(1, 1000000000, "k");
        inf.readEoln();
        std::set<int> st;
        for (int i = 1; i <= n; ++i) {
            int x = inf.readInt(1, 1000000000, "x");
            if (i != n) {
                inf.readSpace();
            }
            ensuref(st.find(x) == st.end(), "duplicate x");
            st.insert(x);
        }
        inf.readEoln();
    }
    inf.readEof();
    return 0;
}
