import sys

N, K = map(int, input().split())
l = list(int(sys.stdin.readline()) for _ in range(N))

def findmax(p):
    m = 0
    if N == 1:
        m = l[0]
    else:
        if max(l) < K:
            m = max(l)
        else:
            for i in range(N):
                if l[i] > K:
                    m = l[i-1]
                    break
                if l[i] == K:
                    m = l[i]
                    break

    return m

cnt = 0
maxvalue = findmax(K)

while True:
    if K == 0:
        print(cnt)
        break
    else:
        cnt += K//maxvalue
        K = K%maxvalue
        maxvalue = findmax(K)