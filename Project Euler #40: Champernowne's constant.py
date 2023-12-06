def index_finder(index):
    i=1
    while True:
        index+=-(9*10**(i-1))*i
        if index<=0:
            index+=(9*10**(i-1))*i
            break
        i+=1

    l=(index-1)//i
    ans=str(10**(i-1)+l)[index-l*i-1]
    return int(ans)

for _ in range(int(input())):
    prod=1
    for i in input().split():
        prod*=index_finder(int(i))
    print(prod)
    
