import sys

N, M, B =  map(int, input().split())
xy = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]

height = 0
ans = 1000000000000000000000000000000
for i in range(257):
    use_block = 0
    take_block = 0
    for j in range(N):
        for k in range(M):
            if xy[j][k] < i :
                use_block += (i - xy[j][k])
            else :
                take_block += (xy[j][k] - i)
    inv = take_block + B
    if inv < use_block :
        continue
    time = 2 * take_block + use_block
    if time <= ans:
        ans = time
        height = i

print(ans, height)