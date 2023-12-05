// My Algorithm
// As explained in the problem statement, you can compute all Fibonacci numbers in an iterative way: FF2F-1
// My variables a and b stand for Fi 2 and F-1 whereas next is F After each iteration, next=a+b and then a becomes b and b becomes next.
// A number is even if there is no remainder when divided by 2.
// In most programming languages it's written as variable % 2 == 0
// Internally, your compiler might translate this to the more efficient (variable & 1) == 0
// Note
// unsigned long long is required to pass all Hackerrank tests.

#include <iostream>

using namespace std;
long long evenFibonacciSum(long long n) {
  if (n <= 1) {
    return 0;
  }
  long long a = 2, b = 8;
  long long sum = a + b;
  while (b <= n) {
    long long c = 4 * b + a;
    if (c <= n) {
      sum += c;
    }
    a = b;
    b = c;
  }

  return sum;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    long long n;
    cin >> n;
    cout << evenFibonacciSum(n) << endl;
  }

  return 0;
}
