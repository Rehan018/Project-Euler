#include <iostream>
#include <cmath>

int main() {
    int n;
    std::cin >> n;
    long long sum = 0;
    for (long long i = 2; i < 1000000; i++) {
        long long temp = i;
        long long sum1 = 0;
        while (temp > 0) {
            int a = temp % 10;
            sum1 += pow(a, n);
            temp = temp / 10;
        }
        if (sum1 == i) {
            sum += sum1;
        }
    }
    std::cout << sum << std::endl;
    return 0;
}

