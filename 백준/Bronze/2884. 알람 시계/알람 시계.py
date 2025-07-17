h, m = map(int, input().split())

if h>0 and m-45>=0 :
    print(h, m-45)
elif h==0 and m-45<0 :
    h=23
    print(h, 60-(45-m))
elif h==0 and m-45>=0 :
    print(h, m-45)
elif h>0 and m-45<0 :
    print(h-1, 60-(45-m))
