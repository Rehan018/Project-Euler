#include <iostream>
using namespace std;

const int mod = 1000000007;
const int imod3 = 333333336;

int main() {
    long long t, n;
    cin >> t;
    
    while (t--) {
        cin >> n;
        long long nm = n % mod, n2m = n / 2 % mod;
        
        long long res = nm * (nm + 1) % mod * (2 * nm + 1) % mod * imod3 - 1;
        cout << (res - 2 * n2m * n2m % mod + mod) % mod << endl;
    }
    
    return 0;
}
