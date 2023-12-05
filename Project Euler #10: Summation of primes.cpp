#include <bits/stdc++.h>

using namespace std;
int main() {
    const unsigned int MaxPrime = 2000000;
    vector<unsigned int> primes;
    primes.push_back(2);
    for (unsigned int i = 3; i <= MaxPrime; i += 2) {
        bool isPrime = true;

        for (auto p : primes) {
            if (p * p > i)
                break;
            if (i % p == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime)
            primes.push_back(i);
    }
    map<unsigned int, unsigned long long> sums;
    unsigned long long sum = 0;

    for (auto p : primes) {
        sum += p;
        sums[p] = sum;
    }
    unsigned int tests;
    cin >> tests;

    while (tests--) {
        unsigned int x;
        cin >> x;
        auto i = sums.upper_bound(x);
        i--;
        cout << i->second << endl;
    }

    return 0;
}
