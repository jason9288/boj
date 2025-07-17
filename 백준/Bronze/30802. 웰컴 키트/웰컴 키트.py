n = int(input())
size = list(map(int, input().split()))
T, P = map(int, input().split())

t_cnt = 0
p_cnt = 0
p_single = 0

for s in size:
    if s/T == 0 and s != 0:
        t_cnt += 1
    elif s%T != 0:
        t_cnt += int(s/T) + 1
    else:
        t_cnt += int(s/T)

p_cnt = int(n/P)
p_single = n%P

print(t_cnt)
print(p_cnt, p_single)