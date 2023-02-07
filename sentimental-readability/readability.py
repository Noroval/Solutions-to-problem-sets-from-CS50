from cs50 import get_string

letters = 0
words = 1
sentences = 0

text = get_string("Text: ")

# checks if symbol is letter, if yes, adds to counter
for i in range(len(text)):
    if text[i].isalpha():
        letters += 1

    elif text[i] == " ":
        words += 1

    elif text[i] == "." or text[i] == "!" or text[i] == "?":
        sentences += 1


