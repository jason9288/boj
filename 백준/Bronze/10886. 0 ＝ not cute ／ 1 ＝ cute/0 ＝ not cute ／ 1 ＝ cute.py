n = int(input())
a = 0
b = 0

for i in range(n):
    j = int(input())
    if j == 1:
        a += 1
    if j == 0:
        b += 1

if a > b:
    print("Junhee is cute!")
else:
    print("Junhee is not cute!")        