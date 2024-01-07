if __name__ == "__main__":
    ans = []
    ans_type = "B"
    with open(f"{ans_type}.txt", "r") as f:
        for line in f.readlines():
            now_line = []
            for c in line[:-1]:
                if c == " ":
                    now_line.append("0")
                else:
                    now_line.append("1")
            ans.append("".join(now_line))
    with open(f"{ans_type}_convert.txt", "w") as f:
        for line in ans:
            f.write(line + "\n")
