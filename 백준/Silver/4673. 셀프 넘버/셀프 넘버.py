def d() :
    n = 1
    l = []
    
    while n < 10 :
        l.append(n*2)
        n+=1
        
    while 10<=n<100 :
        c = []
        for i in str(n) :
            c.append(i)
        l.append(n+int(c[0])+int(c[1]))
        n+=1
    while 100 <= n < 1000 :
        c = []
        for i in str(n) :
            c.append(i) 
        l.append(n+int(c[0])+int(c[1])+int(c[2]))
        n+=1
    while 1000 <= n < 10000 :
        c = []
        for i in str(n) :
            c.append(i)
        l.append(n+int(c[0])+int(c[1])+int(c[2])+int(c[3]))
        n+=1
    for j in range(1, 10001) :
        if j not in l :
            print(j)


d()