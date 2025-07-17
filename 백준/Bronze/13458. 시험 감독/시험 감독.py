import sys
n = int(sys.stdin.readline())
a = list(map(int, sys.stdin.readline().split()))
b, c = map(int, sys.stdin.readline().split())

r = []
cnt = [0 for k in range(n)]
for i in range(n) :
        r.append(a[i] - b)
 
for j in range(n) :
    if r[j] <= 0 :
        cnt[j] += 1
    else :
        cnt[j] += 1
        if r[j] % c == 0 :
            cnt[j] += r[j]//c
        elif r[j] < c :
            cnt[j] += 1
        else :
            cnt[j] += r[j]//c + 1

        
print(sum(cnt))