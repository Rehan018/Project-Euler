#include <iostream>
#include <algorithm>

using namespace std;

bool isPalindrome(int num) {
    string strNum = to_string(num);
    string reversedStrNum = strNum;
    reverse(reversedStrNum.begin(), reversedStrNum.end());
    return strNum == reversedStrNum;
}

int findLargestPalindrome(int limit) {
    int maxPalindrome = 0;

    for (int i = 999; i >= 100; i--) {
        for (int j = i; j >= 100; j--) {
            int product = i * j;
            if (product < limit && isPalindrome(product)) {
                maxPalindrome = max(maxPalindrome, product);
                break;
            }
        }
    }

    return maxPalindrome;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int limit;
        cin >> limit;

        int result = findLargestPalindrome(limit);
        cout << result << endl;
    }

    return 0;
}
