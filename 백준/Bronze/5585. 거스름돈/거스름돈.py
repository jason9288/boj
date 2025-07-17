n = int(input())
money = 1000 - n

cnt = 0
while(True):
    if money == 0:
        break
    else:
        if money >= 500:
            c = money//500
            money -= 500* c
            cnt += c
            
        if 100 <= money < 500:
            c = money//100
            money -= 100* c
            cnt += c
            
        if 50 <= money < 100:
            c = money//50
            money -= 50* c
            cnt += c
            
        if 10 <= money < 50:
            c = money//10
            money -= 10* c
            cnt += c
            
        if 5 <= money < 10:
            c = money//5
            money -= 5* c
            cnt += c
            
        if 1 <= money < 5:
            cnt += money
            money = 0
        

print(cnt)