"""
This script converts an image to black and white and saves it as a text file.

Before running this script, you need to install OpenCV and numpy:
    pip install opencv-python numpy
"""


import numpy as np
import cv2
import os
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
    print(f"The 0/1 image file saved to {os.path.abspath(output_path)}.")


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument(
        "--input_path", "-i", type=str, help="path to input image", required=True
    )
    parser.add_argument(
        "--output_path",
        "-o",
        default="output.txt",
        type=str,
        help="path to output image",
    )
    args = parser.parse_args()
    convert_to_black_and_white(args.input_path, args.output_path)
