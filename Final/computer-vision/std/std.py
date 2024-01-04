import queue


def bfs(maps, start_x, start_y):
    q = queue.Queue()
    q.put((start_x, start_y))
    maps[start_x][start_y] = 1
    dx = [0, 0, 1, -1]
    dy = [1, -1, 0, 0]
    while not q.empty():
        x, y = q.get()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if maps[nx][ny] == 0:
                maps[nx][ny] = 1
                q.put((nx, ny))


if __name__ == "__main__":
    n, m = map(int, input().split())
    maps = [[0] * (m + 2)]
    for i in range(n):
        maps.append([0] + list(map(int, input())) + [0])
    maps.append([0] * (m + 2))
    ans = 0
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if maps[i][j] == 0:
                bfs(maps, i, j)
                ans += 1
    print("CAB"[ans - 1])
