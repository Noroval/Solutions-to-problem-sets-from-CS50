from cs50 import get_string

letters = 0
words = 1
sentences = 0

text = get_string("Text: ")

# checks if symbol is letter, also checks for spaces(words) and finally for sentences, if yes, adds to counter


for i in range(len(text)):
    if text[i].isalpha():
        letters += 1

    elif text[i] == " ":
        words += 1

    elif text[i] == "." or text[i] == "!" or text[i] == "?":
        sentences += 1

# applying the formulas


L = letters / words * 100
S = sentences / words * 100

index = round(0.0588 * L - 0.296 * S - 15.8)


