a = input()
b = input()
c = input()
next_val = 0

if (a.isdigit()):
    next_val = int(a)+3
if (b.isdigit()):
    next_val = int(b)+2
if (c.isdigit()):
    next_val = int(c)+1

if next_val%3 == 0:
    if next_val%5 == 0:
        print("FizzBuzz")
    else:
        print("Fizz")
elif next_val%5 == 0:
    if next_val%3 != 0:
        print("Buzz")
else:
    print(next_val)