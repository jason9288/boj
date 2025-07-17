import sys

n, m = map(int, input().split())
l = [i+1 for i in range(n)]
for i in range(m):
    a, b = map(int, sys.stdin.readline().split())
    index1 = l[a-1]
    index2 = l[b-1]
    l[a-1] = index2
    l[b-1] = index1
for k in l:
    print(k, end=' ')