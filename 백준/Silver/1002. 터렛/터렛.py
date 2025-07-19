import math
t = int(input())
for i in range(t) :
    x1, y1, r1, x2, y2, r2 = map(int, input().split())
    d = math.sqrt((x2-x1)**2 + (y2-y1)**2)
    rad = [r1, r2]
    if d == 0 :
        if r1 == r2 :
            print("-1")
            continue
        else :
            print("0")
            continue
            
    if d > r1 + r2 :
        print("0")
    elif d == r1 + r2 :
        print("1")
    elif d < r1 + r2 :
        if min(rad) + d == max(rad) :
            print("1")
        elif min(rad) + d < max(rad) :
            print("0")
        else :
            print("2")
    else :
        print("-1")