#include <iostream>
#include <vector>

using namespace std;

int recurring_digits(int n) {
    while (n % 2 == 0) {
        n = n / 2;
    }
    while (n % 5 == 0) {
        n = n / 5;
    }
    if (n == 1) {
        return 0;
    }

    int digits = 1;
    int rem = 1;

    while (true) {
        rem *= 10;
        rem = rem % n;
        if (rem == 1) {
            break;
        }
        digits++;
    }

    return digits;
}

int main() {
    vector<int> answers = {0, 0, 0, 0};
    int max_digits = 0;
    int number;

    for (int i = 3; i < 10000; i++) {
        int digits = recurring_digits(i);
        if (digits > max_digits) {
            max_digits = digits;
            number = i;
        }
        answers.push_back(number);
    }

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        cout << answers[n] << endl;
    }

    return 0;
}
