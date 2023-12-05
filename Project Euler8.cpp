#include <iostream>
#include <vector>
#include <string>
using namespace std;
long long calculateProduct(const string& number, int k) {
    long long maxProduct = 0;

    for (int i = 0; i < number.length() - k + 1; ++i) {
        long long product = 1;
        for (int j = 0; j < k; ++j) {
            product *= (number[i + j] - '0');
        }
        maxProduct = max(maxProduct, product);
    }

    return maxProduct;
}

int main() {
    int t; 
    cin >> t;

    while (t--) {
        int n, k; 
        cin >> n >> k;

        string number;
        cin >> number;
        long long result = calculateProduct(number, k);
        cout << result << endl;
    }

    return 0;
}
