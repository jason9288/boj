N = int(input())
i = 2
while 1 :
    if N % i == 0 :
        print(i)
        N = N/i
        i = 2
    else :
        i += 1
    if N == 1 :
        break