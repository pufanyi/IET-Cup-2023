import numpy as np
import cv2
import argparse


def convert_to_black_and_white(input_path, output_path):
    img = cv2.imread(input_path, cv2.IMREAD_GRAYSCALE)
    img = np.where(img > 128, 1, 0)
    img = img.tolist()
    with open(output_path, "w") as f:
        n, m = len(img), len(img[0])
        print(n, m, file=f)
        for line in img:
            print("".join(map(str, line)), file=f)


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--input_path", "-i", type=str, help="input path")
    parser.add_argument("--output_path", "-o", default="output.txt", type=str, help="output path")
    args = parser.parse_args()
    convert_to_black_and_white(args.input_path, args.output_path)
