from cs50 import get_int

def main():
    height = get_height()
    for i in range(0, height, 1):
        for j in range(0, height, 1):
            if (i + j < height - 1):
                print(" ", end="")
            else:
                print("#", end="")
        print()

def get_height():
    while True:
        n = get_int("Height: ")
        if n > 0 and n < 9:
            return n

main()