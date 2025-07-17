n = int(input())
cnt = 0
max = -1

l = list(map(int, input().split()))
for i in range(n):
    if l[i] >= 1:
        cnt += 1
    else :
        cnt = 0
    if max < cnt:
            max = cnt
    
print(max)


