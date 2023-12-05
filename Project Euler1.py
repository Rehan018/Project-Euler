# My Algorithm

# We are supposed to find of all multiples of 3 or 5 below the input number, therefore we decrement it by one.
# In general, the sum of all numbers between 1 and x is sum 1, x i = x(x + 1) / 2

# There are [2/3] numbers between 1 and x which are divisible by 3 (assuming [2/3] is an integer division). e.g. the range 1..10 contains |10/3| = 3 such numbers (it's 3, 6 and 9). Their sum is 3 + 6 + 9 = 18 This can be written as 3/3 * (3 + 6 + 9) which is the same as 3 x (3/36/39/3)=3×(1+2+3). Those brackets represent sum 1.3 i= sum 1.1/3 i 1 or short: sum  10/3 )
# and thus our overall formula for the sum of all multiples of 3 becomes 3 * sum  x / 3
# The same formula can be used for 5:
# The sum of all numbers divisible by 5 is 5 * sum  x / 5
# However, there are numbers divisible by 3 and 5, which means they are part of both sums. We must not count them twice, that's why we (in addition to the aforementioned sums) compute the sum of all numbers divisible by 3^ * 5 = 15 to correct for this error.
# In the end we print sumThree + sumFive sumFifteen

# Alternative Approaches
# Looping through all numbers from 1 and 1000 and checking each of those numbers whether they are divisible by 3 or 5 easily solves the problem, too, and produces the result pretty much instant Even more, the code will be probably a bit shorter.
# However, Hackerrank's input numbers are too large for that simple approach (up to 10 ^ 9 with 10 ^ 5 and will lead to timeouts. test cases)

# Certainly! Let's organize your algorithm step by step:

# 1. **Decrement the Input Number by One:**
#    - Given an input number, decrement it by one.

# 2. **Sum of All Numbers between 1 and x:**
#    - Use the formula for the sum of all numbers between 1 and x: \( \frac{x(x + 1)}{2} \).

# 3. **Sum of Multiples of 3:**
#    - Calculate the sum of all multiples of 3 below the input number:
#      \[ 3 \times \text{{sum}}\left(\frac{x}{3}\right) \]

# 4. **Sum of Multiples of 5:**
#    - Calculate the sum of all multiples of 5 below the input number:
#      \[ 5 \times \text{{sum}}\left(\frac{x}{5}\right) \]

# 5. **Correcting for Overlapping Multiples of 3 and 5:**
#    - Some numbers are multiples of both 3 and 5 (e.g., multiples of 15). Subtract the sum of these multiples to avoid double counting:
#      \[ \text{{sum}}\left(\frac{x}{15}\right) \]

# 6. **Overall Sum Calculation:**
#    - Sum all the results from steps 3, 4, and 5:
#      \[ \text{{sumThree}} + \text{{sumFive}} - \text{{sumFifteen}} \]

# 7. **Handling Large Inputs:**
#    - Mention the limitation of the simple loop approach for large inputs and explain the efficiency of the given algorithm.

# 8. **Print the Result:**
#    - Print the final result obtained in step 6.

# This organized algorithm should give you a clear structure for implementing the solution without writing the actual code.


def sum(n, k):
    d = n // k
    return k * (d * (d+1)) // 2
  
def euler1(n):
    return sum(n, 3) + sum(n, 5) - sum(n, 15)

t = int(input().strip())
for i in range(t):
    N = int(input().strip())
    print(euler1(N - 1)) 
