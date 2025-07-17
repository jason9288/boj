import math

x, y = map(int, input().split())
if (x == y):
    print(-1)
    exit(0)

t_x = x
t_y = y

z = math.floor((100*y)/x)
t_z = z
cnt_win = 0
if z == 99:
    print(-1)
    exit(0)

while 1: 
    x += 100000
    y += 100000
    cnt_win += 100000
    z = math.floor((100*y)/x)
    if z != t_z:
        for i in range(100000):
            x -= 1
            y -= 1
            cnt_win -= 1
            z = math.floor((100*y)/x)
            if z == t_z:
                cnt_win += 1
                break
        break


print(cnt_win)
