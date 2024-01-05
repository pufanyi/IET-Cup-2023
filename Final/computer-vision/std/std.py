import queue
from typing import List


BASE64_CHARS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"


def base64_decode(s: str) -> List[int]:
    """Decode base64 string to bytes

    Args:
        s (str): The base64 string

    Returns:
        List[int]: The list of bytes, each byte is an integer (0/1).
    """
    ans = []
    for c in s:
        ans.append(bin(BASE64_CHARS.index(c))[2:].zfill(6))
    return list(map(int, "".join(ans)))


def get_input():
    n, m = map(int, input().split())
    input_bytes = base64_decode(input())
    input_map = []
    for i in range(n):
        input_map.append(input_bytes[i * m : (i + 1) * m])
    return n, m, input_map


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
            if 0 <= nx < len(maps) and 0 <= ny < len(maps[nx]) and maps[nx][ny] == 0:
                maps[nx][ny] = 1
                q.put((nx, ny))


if __name__ == "__main__":
    n, m, maps = get_input()
    maps = [[0 * m]] + maps + [[0 * m]]
    maps = list(map(lambda x: [0] + x + [0], maps))
    ans = 0
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if maps[i][j] == 0:
                bfs(maps, i, j)
                ans += 1
    print("CAB"[ans - 1])
