# This is the O(n log n) solution for the problem B


class UnionFind(object):
    def __init__(self, n):
        self.parent = list(range(n))
        self.size = [1] * n

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x, y):
        x = self.find(x)
        y = self.find(y)
        if x != y:
            if self.size[x] < self.size[y]:
                x, y = y, x
            self.parent[y] = x
            self.size[x] += self.size[y]
            return True
        return False

    def get_size(self, x):
        return self.size[self.find(x)]


if __name__ == "__main__":
    n = int(input())
    edges = []
    for i in range(n - 1):
        edges.append(tuple(map(int, input().split())))
    edges.sort(key=lambda x: x[2])
    uf_set = UnionFind(n)
    ans = 0
    for edge in edges:
        u, v, w = edge
        # Don't forget the Union-Find is 0-indexed
        ans += (w + 1) * (uf_set.get_size(u - 1) * uf_set.get_size(v - 1) - 1)
        ans += w    # Don't forget to add the weight of the edge itself
        uf_set.union(u - 1, v - 1)
    print(ans)
