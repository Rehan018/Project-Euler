M = 1
lookup = [] 
longest = [] 

def collatz(n: int) -> int:
    global M, lookup
    if n <= M and lookup[n] != 0:
        return lookup[n]

    c = collatz(n // 2 if n % 2 == 0 else n * 3 + 1) + 1
    if n <= M:
        lookup[n] = c

    return c
def compute_collatz_numbers(n: int):
    global M, lookup, longest
    M = n
    lookup = [0] * (M + 1)
    longest = [0] * (M + 1)
    lookup[1] = longest[1] = 1
    max_number = max_chain = -1
    for i in range(1, M + 1):
        c = collatz(i)
        if max_chain <= c:
            max_chain = c
            max_number = i
        longest[i] = max_number

ns = [int(input()) for _ in range(int(input()))]
compute_collatz_numbers(max(ns))
for n in ns:
    print(longest[n])
