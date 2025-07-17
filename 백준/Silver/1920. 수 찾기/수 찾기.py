import sys
n = int(sys.stdin.readline())
l1 = list(map(int, sys.stdin.readline().split()))
m = int(sys.stdin.readline())
l2 = list(map(int, sys.stdin.readline().split()))

l1.sort()


def cal(a, l1) :
    left = 0
    right = len(l1)-1
    while left <= right :
        mid = (left + right) // 2
        if l1[mid] == l2[a] :
            return 1
        elif l1[mid] > l2[a] :
            right = mid - 1
        else :
            left = mid + 1
    return 0 

for i in range(m) :
    print(cal(i, l1))