import sys
n = int(sys.stdin.readline())
l = []
for i in range(n) :
    l.append(list(map(int, sys.stdin.readline().split())))
l = sorted(l, key = lambda x : (x[1], x[0]))
for i in range(n) :
    print(l[i][0], l[i][1])