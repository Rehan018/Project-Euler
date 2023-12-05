/*
1. **Objective:**
   - The goal is to generate six-digit palindromes, where the upper three digits are a mirrored version of the lower three digits.

2. **Function to Create Palindrome:**
   - Implement a function named `makePalindrome` that takes a three-digit number and returns its corresponding six-digit palindrome.
   - Ensure that the palindrome doesn't have leading zeros, as this would violate the definition of a palindrome.

3. **Number of Six-Digit Palindromes:**
   - Acknowledge that there are only 899 six-digit palindromes possible, as the range for three-digit numbers is 100 to 999.

4. **Finding Divisors:**
   - Iterate through all possible combinations of three-digit palindromes, searching for a three-digit divisor.
   - Note that no leading zeros are allowed in the divisor to maintain the palindrome property.

5. **Optimization Technique:**
   - Optimize the search process by starting from 999 and looping downwards.
   - Observe that at least one divisor \(i\) must satisfy \(100 < i < \text{{palindrome}}\).

6. **Algorithm Optimization:**
   - Consider optimizing the algorithm for speed, such as by using a more efficient approach to find divisors.

7. **Overall Algorithm:**
   - Combine the steps into an overall algorithm that generates six-digit palindromes, checks for divisors, and ensures the palindrome property.

*/
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
