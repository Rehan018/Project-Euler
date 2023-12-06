N = int(input())

org = [i for i in range(1, N+1)]

first = 0
second = 0
last = 0


ans = set()
for i in range(1, 10**2):
    for j in range(i, 10**4):
        if i == j:
            continue
        
        prd = i * j

        st = str(i) + str(j) + str(prd)
        st = list(map(int, st))
        st = sorted(st)

        if st == org:
            ans.add(prd)
            #print(prd)

print(sum(ans))
