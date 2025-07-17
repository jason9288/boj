import sys
n, m = map(int, input().split())
w1 = []
w2 = []
for i in range(n) :
    w1.append(str(sys.stdin.readline().strip()))
for i in range(m) :
    w2.append(str(sys.stdin.readline().strip()))

cnt = 0
w1 = set(w1)

for i in range(m) :
    if w2[i] in w1 :
        cnt += 1

print(cnt)