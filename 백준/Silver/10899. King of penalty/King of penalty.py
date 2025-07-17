p, n = map(int, input().split())

sources = list(map(int, input().split()))
sources.sort()

penalty = 0
time = p-1
cnt = 0
i = 0

while 1:
    if time < sources[i]:
        break
    penalty += time
    time -= sources[i]
    cnt += 1
    i += 1
    if i >= len(sources):
        break

print(cnt, penalty)