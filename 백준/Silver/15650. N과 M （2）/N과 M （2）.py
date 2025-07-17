n, m =map(int, input().split())
ans = []
def backt(start):
    if len(ans) == m:
        print(" ".join(map(str, ans)))
        return
    for i in range(start, n+1):
        if i not in ans:
            ans.append(i)
            backt(i+1)
            ans.pop()
backt(1)