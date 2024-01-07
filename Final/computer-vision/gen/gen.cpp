#include <set>
#include <vector>
#include <cstdint>
#include <algorithm>

#include "testlib.h"
#include "img.h"

constexpr int INF = (int) 1e9;
constexpr int N = 500;
constexpr double M_PI = 3.14159265358979323846;

using Image = std::set<std::pair<int, int>>;

Image select() {
    Image image;
    int ans = rnd.next(0, 2);
    for (int i = 0; i < 224; ++i) {
        for (int j = 0; j < 224; ++j) {
            if (IMGS[ans][i][j] == 0) {
                image.emplace(i, j);
            }
        }
    }
    return image;
}

Image rotate(const Image &image, double angle) {
    Image ret;
    for (int x = -2 * N; x <= 2 * N; ++x) {
        for (int y = -2 * N; y <= 2 * N; ++y) {
            double xx = x * cos(angle) - y * sin(angle);
            double yy = x * sin(angle) + y * cos(angle);
            if (image.count({(int) xx, (int) yy})) {
                ret.emplace(x, y);
            }
        }
        // int xx = (int) (x * cos(angle) - y * sin(angle));
        // int yy = (int) (x * sin(angle) + y * cos(angle));
    }
    return ret;
}

Image fix(const Image &image) {
    if (image.empty()) {
        return image;
    }
    int minx = INF, miny = INF;
    for (auto [x, y] : image) {
        minx = std::min(minx, x);
        miny = std::min(miny, y);
    }
    Image ret;
    for (auto [x, y] : image) {
        ret.emplace(x - minx, y - miny);
    }
    return ret;
}

std::pair<int, int> size(const Image &image) {
    int maxx = -INF, maxy = -INF;
    for (auto [x, y] : image) {
        maxx = std::max(maxx, x);
        maxy = std::max(maxy, y);
    }
    return {maxx + 1, maxy + 1};
}

Image resize(Image image, int w, int h) {
    image = fix(image);
    auto [base_w, base_h] = size(image);
    // std::cerr << "image " << image.size() << std::endl;
    Image ret;
    for (int i = 0; i <= w; ++i) {
        for (int j = 0; j <= h; j++) {
            double x = 1.0 * i / w * base_w;
            double y = 1.0 * j / h * base_h;
            // if (w == 297) {
            //     std::cerr << i << ' ' << j << ' ' << x << ' ' << y << ' ' << w << ' ' << base_w << ' ' << h << ' ' << base_h << std::endl;
            // }
            if (image.count({(int) x, (int) y})) {
                ret.emplace(i, j);
            }
        }
    }
    return ret;
}

Image resize(const Image &image) {
    int w = rnd.next(100, N);
    int h = rnd.next(100, N);
    return resize(image, w, h);
}

void output(const Image &image, int w, int h, int base_w, int base_h) {
    std::vector<std::vector<char>> ans(w, std::vector<char>(h, '1'));
    for (auto [x, y] : image) {
        ans[base_w + x][base_h + y] = '0';
    }
    std::cout << w << ' ' << h << '\n';
    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < h; j++) {
            std::cout << ans[i][j];
        }
        std::cout << '\n';
    }
}

void output_directly(const Image &image) {
    Image img = fix(image);
    auto [w, h] = size(img);
    // std::cerr << w << ' ' << h << std::endl;
    output(img, w, h, 0, 0);
}

void output_with_size(const Image &image) {
    Image img = fix(image);
    auto [w, h] = size(img);
    int base_w = rnd.next(0, N - w);
    int base_h = rnd.next(0, N - h);
    output(img, N, N, base_w, base_h);
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    const int seed = std::atoi(argv[1]);
    rnd.setSeed(seed);
    Image image = select();
    image = resize(image);
    double angle = rnd.next(0, 360) * M_PI / 180;
    image = rotate(image, angle);
    image = resize(image);
    if (rnd.next(0, 1)) {
        output_directly(image);
    } else {
        output_with_size(image);
    }
    return 0;
}
