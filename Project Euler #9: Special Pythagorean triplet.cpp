#include <bits/stdc++.h>
using namespace std;
long long findMaxPythagoreanTripletProduct(int n) {
   for (int c = 1 + n / 3; c < n / 2; ++c) {
        int sqa_b = c * c - n * n + 2 * n * c;
        int a_b = sqrt(sqa_b);

        if (a_b * a_b == sqa_b) {
            int b = (n - c + a_b) / 2;
            int a = n - b - c;
            return static_cast<long long>(a) * b * c;
        }
    }

    return -1;
}

int main() {
    int t; 
    cin >> t;

    while (t--) {
        int n; 
        cin >> n;
        long long result = findMaxPythagoreanTripletProduct(n);
        cout << result << endl;
    }

    return 0;
}
