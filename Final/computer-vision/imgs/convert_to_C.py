import json


if __name__ == "__main__":
    l = []
    for c in ['A', 'B', 'C']:
        with open(f"{c}.txt", "r") as f:
            n, m = map(int, f.readline().split())
            img = []
            for line in f.readlines():
                img.append(list(map(int, line[:-1])))
                assert(len(img[-1]) == m)
            l.append(img)
        assert n == len(img)
    s = json.dumps(l)
    s = s.replace(' ', '')
    s = s.replace('[', '{')
    s = s.replace(']', '}')
    with open("imgs.txt", "w") as f:
        f.write(s)
