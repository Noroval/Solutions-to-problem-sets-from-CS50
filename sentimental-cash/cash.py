from cs50 import get_float

while True:
    dollars = get_float("Change owed: ")
    if dollars > 0:
        break

cents = round(dollars * 100)

count = 0

while cents >= 25:
    cents - 25
    count += 1

elif cents >= 10:
    cents - 10
    count += 1

elif cents >= 5:
    cents - 5
    count += 1

else cents >= 1:
    cents - 1
    count += 1

print(count)