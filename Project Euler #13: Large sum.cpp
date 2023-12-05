#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string add(const string& s1, const string& s2) {
    int a = s1.size();
    int b = s2.size();
    string ans;
    int carry = 0;

    if (a > b) {
        for (int i = 0; i < a; i++) {
            int sum = (i < b) ? (s1[a - 1 - i] - '0') + (s2[b - 1 - i] - '0') : (s1[a - 1 - i] - '0');
            sum += carry;

            if (sum > 9) {
                sum %= 10;
                carry = 1;
            } else {
                carry = 0;
            }

            ans.push_back(sum + '0');
        }
    } else {
        for (int i = 0; i < b; i++) {
            int sum = (i < a) ? (s1[a - 1 - i] - '0') + (s2[b - 1 - i] - '0') : (s2[b - 1 - i] - '0');
            sum += carry;

            if (sum > 9) {
                sum %= 10;
                carry = 1;
            } else {
                carry = 0;
            }

            ans.push_back(sum + '0');
        }
    }

    if (carry) {
        ans.push_back('1');
    }

    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<string> nums;
    string s;

    while (n--) {
        cin >> s;
        nums.push_back(s);
    }

    string sum = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        sum = add(sum, nums[i]);
        reverse(sum.begin(), sum.end());
    }

    string ans = sum.substr(0, 10);
    cout << ans << endl;

    return 0;
}
