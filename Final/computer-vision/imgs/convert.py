def base64_encode(s: str):
    BASE64_CHARS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
    while len(s) % 6 != 0:
        s += "0"
    base64_code = []
    for i in range(0, len(s), 6):
        base64_code.append(BASE64_CHARS[int(s[i:i + 6], 2)])
    print(base64_code)
    return "".join(base64_code)


if __name__ == "__main__":
    ans = []
    bytes_code = []
    with open("A.txt", "r") as f:
        for line in f.readlines():
            now_line = []
            for c in line[:-1]:
                if c == " ":
                    now_line.append("0")
                else:
                    now_line.append("1")
            ans.append("".join(now_line))
            bytes_code.extend(now_line)
    with open("A_convert.txt", "w") as f:
        for line in ans:
            f.write(line + "\n")
    while len(bytes_code) % 6 != 0:
        bytes_code.append("0")
    bytes_code = "".join(bytes_code)
    # print(bytes_code)
    # change bytes_code to bytes and then encode it to base64
    with open("A_convert_b64.txt", "a") as f:
        f.write(base64_encode(bytes_code) + "\n")
