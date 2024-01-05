#include <vector>
#include <utility>
#include <queue>

#include "testlib.h"

int check_tree(const std::vector<std::vector<int>> &e, int now, int fa, std::vector<bool> &vis) {
    int siz = 1;
    vis[now] = true;
    for (auto v : e[now]) {
        if (v == fa) {
            continue;
        }
        ensuref(!vis[v], "not a tree");
        siz += check_tree(e, v, now, vis);
    }
    return siz;
}

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(1, 1000, "n");
    inf.readEoln();
    std::vector<std::vector<int>> e(n + 1);
    for (int i = 1; i < n; ++i) {
        int u = inf.readInt(1, n, "u");
        inf.readSpace();
        int v = inf.readInt(1, n, "v");
        inf.readSpace();
        inf.readInt(1, 1000, "w");
        inf.readEoln();
        e[u].push_back(v);
        e[v].push_back(u);
    }
    inf.readEof();
    std::vector<bool> vis(n + 1);
    int siz = check_tree(e, 1, 0, vis);
    ensuref(siz == n, "not a tree");
    return 0;
}
