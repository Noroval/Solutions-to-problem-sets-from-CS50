from cs50 import get_string

letters = 0
words = 1
sentences = 0

text = get_string("Text: ")

for i in range(len(text)):
    if text[i].isalpha():
        letters += 1

    elif text[i] == " ":
        words += 1

    elif 