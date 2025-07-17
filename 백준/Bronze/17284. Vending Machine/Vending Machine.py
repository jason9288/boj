b = list(map(int, input().split()))
money = 5000
for i in b:
    if (i == 1):
        money -= 500
    elif (i == 2):
        money -= 800
        
    else:
        money -= 1000
        
        
        
print(money)