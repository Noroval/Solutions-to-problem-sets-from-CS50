from cs50 import get_float

while True:
    dollars = get_float("Change owed: ")
    if dollars > 0:
        return dollars

cents = round(dollars * 100)


