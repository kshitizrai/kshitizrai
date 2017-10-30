print('Started')
n = input()
n = int(n)

toplist=list()
count=list()

for i in range(n):
    toplist.append(input())
    count.append(0)

for i in range(n):
    if(len(toplist[i])!=10): count[i] = 1;
    if(toplist[i].isalnum() == False): count[i] = 1;

for i in range(n):
    countdigit , countuppalpha = 0 , 0
    if count[i] == 1: continue
    for j in range(len(toplist[i])):
        if((toplist[i][j].isupper() == True) and (toplist[i][j].isalpha() == True)) :
            countuppalpha = countuppalpha + 1
        if(toplist[i][j].isdigit() == True) : countdigit = countdigit +1
    if( countdigit<2 ) : count[i] = 1
    if(countuppalpha<3) : count[i] = 1
