from cs50 import get_int

# prints hashtag and spaces


def main():
    height = get_height()
    for i in range(0, height, 1):
        for j in range(0, height, 1):
            if (i + j < height - 1):
                print(" ", end="")
            else:
                print("#", end="")
        print()

# prompts the user for height and checks if it's between 1 to 8


def get_height():
    while True:
        n = get_int("Height: ")
        if n > 0 and n < 9:
            return n


main()