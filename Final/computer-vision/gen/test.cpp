#include "img.h"

#include <fstream>

int main() {
    std::ofstream fout("test.txt");
    for (int _ = 0; _ < 3; ++_) {
        for (int i = 0; i < 224; ++i) {
            for (int j = 0; j < 224; ++j) {
                fout << IMGS[_][i][j];
            }
            fout << '\n';
        }
    }
    fout.close();
    return 0;
}