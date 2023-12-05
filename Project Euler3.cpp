/*
My Algorithm
Certainly! Here's your algorithm organized and with spelling corrected:

1. **Factorization Algorithm:**
   - For each composite number \(x\), it can be expressed as \(x = \text{{factor}} \times \text{{other}}\), where \(\text{{factor}}\) is a prime number.
   - Start a loop with \(\text{{factor}} = 2\) (the smallest prime).
   - While \(x\) can be divided by \(\text{{factor}}\) with a remainder of 0:
      - If \(\text{{factor}}\) is prime, set \(x = \text{{other}}\) and continue the loop.
      - If \(x\) is prime, terminate the loop as we have found the largest prime factor.
   - The loop can be terminated as soon as all factors are processed, leaving only a prime factor.

2. **Handling Composite Factors:**
   - Note that \(\text{{factor}}\) isn't always a prime number in the program.
   - Scan through all numbers, including composite ones, because if they are composite, all smaller primes have already been checked.
   - For composite factors, the divisions will always fail since all required prime factors were already eliminated.

3. **Optimization Note:**
   - While \(\text{{factor}}\) is not always a prime in the program, checking composite factors doesn't affect the correctness of the algorithm.
   - Even though a prime sieve could be used for optimization, the program is sufficiently fast without it for this problem.

This organized version addresses the spelling mistake and arranges each point for clarity.
*/

#include <iostream>
#include <cmath>

using namespace std;

long long largestPrimeFactor(long long n) {
    long long maxPrime = -1;
    while (n % 2 == 0) {
        maxPrime = 2;
        n /= 2;
    }
    for (long long i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            maxPrime = i;
            n /= i;
        }
    }
    if (n > 2) {
        maxPrime = n;
    }

    return maxPrime;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long num;
        cin >> num;

        long long result = largestPrimeFactor(num);
        cout << result << endl;
    }

    return 0;
}
