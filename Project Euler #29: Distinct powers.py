no=int(input())
li=[True]*(no+1)
answer=0
for i in range(2,no+1):
    if li[i]:
        power=2
        answers=[]
        while i**power<=no:
            li[i**power]=False
            answers+=[n for n in range(2*power,no*power+1,power) if n>no]
            power+=1
        answer+=len(set(answers))+(no-1)
        
print(answer)
