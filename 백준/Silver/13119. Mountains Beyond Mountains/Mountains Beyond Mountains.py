n, m, x = map(int, input().split())

drawing = [["."]*m for _ in range(n)]
        
height_list = list(map(int, input().split()))
highway_h = n - x

for i in range(n):
    for j in range(m):
        if i >= (n-height_list[j]):
            drawing[i][j] = "#"
        if (j+1)%3 == 0 and i > highway_h and i < (n-height_list[j]):
            drawing[i][j] = "|"
            
for i in range(m):
    if drawing[highway_h][i] == "#":
        drawing[highway_h][i] = "*"
    else:
        drawing[highway_h][i] = "-"
        
for i in range(n):
    print(''.join(drawing[i]))
   