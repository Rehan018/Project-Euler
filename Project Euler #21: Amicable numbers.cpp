#include <bits/stdc++.h>
using namespace std;

const int MxN = 1e5 + 1;
vector<int> factor_sum(MxN);
vector<bool> is_amicable(MxN, false);
vector<int> sum_of_amicable(MxN);

void amicable() {
    for (int i=1; i<MxN; i++) {
        int s = 1;
        for (int j=2; j<=sqrt(i); j++) {
            if (i % j == 0) {
                if (i / j == j) s += j;
                else s += (j + (i/j));
            }
        }
        factor_sum[i] = s;
        if (factor_sum[i] < MxN) {
            if (i == factor_sum[factor_sum[i]] && i != factor_sum[i]) {
                is_amicable[i] = true;
                is_amicable[factor_sum[i]] = true;
            }
        }

    }
    for (int i=1; i<MxN; i++) {
        sum_of_amicable[i] = sum_of_amicable[i-1];
        if (is_amicable[i]) {
            sum_of_amicable[i] += i;
        }
    }
}

int main() {
    amicable();
    int t;
    cin >> t;
    for (int i=0; i<t; i++) {
        int n;
        cin >> n;
        cout << sum_of_amicable[n-1] << "\n";
    }
}
