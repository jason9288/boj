while 1:
    line = input()
    if line == '#':
        break
    else:
        l = line.split()
        for word in l:
            w = list(word)
            length = len(word)
            if length <= 3: 
                print(word, end=' ')
                continue
            else:
                if length%2 == 0:
                    for i in range(int((length+1)/2)):
                        if i == 0:
                            continue
                        else:
                            temp = w[i]
                            w[i] = w[length-i-1]
                            w[length-i-1] = temp
                            
                else:
                    for i in range(int(length/2)):
                        if i == 0:
                            continue
                        else:
                            temp = w[i]
                            w[i] = w[length-i-1]
                            w[length-i-1] = temp
            print(''.join(w), end=' ')
    print()
                
                