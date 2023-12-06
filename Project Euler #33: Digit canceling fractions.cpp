#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

vector<char> insert(vector<char>& array, int count, char target) {
    vector<char> in_new(array.size() + count);
    for(int k = 0; k < count; k++) {
        in_new[k] = target;
    }
    for(int k = count; k < in_new.size(); k++) {
        in_new[k] = array[k - count];
    }
    return in_new;
}

bool nextPermutation(vector<char>& array) {
    for(int i = array.size() - 1; i > 0; i--) {
        if(array[i - 1] < array[i]) {
            int dest = array[i - 1];
            int s = i;
            int e = array.size() - 1;
            int swapIndex = 0;
            while(true) {
                if(s == e) {
                    swapIndex = s;
                    break;
                }
                int m = (s + e + 1) / 2;
                if(array[m] <= dest) {
                    e = m - 1;
                } else {
                    s = m;
                }
            }
            char temp = array[swapIndex];
            array[swapIndex] = array[i - 1];
            array[i - 1] = temp;
            sort(array.begin() + i, array.end());
            return true;
        }
    }
    return false;
}

vector<char> NumToCharArray(int x, int digits) {
    string result = to_string(x);
    while(result.length() != digits) {
        result = "0" + result;
    }
    vector<char> charArray(result.begin(), result.end());
    return charArray;
}

int merge(vector<char>& strFill, vector<char>& mask) {
    int index = 0;
    int result = 0;
    for(char m : mask) {
        result *= 10;
        if(m == '.') {
            result += strFill[index] - '0';
            index++;
        } else {
            result += m - '0';
        }
    }
    return result;
}

int main() {
    int N, K;
    cin >> N >> K;
    int keep = N - K;
    vector<int> Tens = {1, 10, 100, 1000, 10000};
    int sumN = 0;
    int sumD = 0;
    unordered_set<int> used;
    for(int d = 1; d < Tens[keep]; d++) {
        for(int n = 1; n < d; n++) {
            vector<char> charN = NumToCharArray(n, keep);
            vector<char> charD = NumToCharArray(d, keep);
            for(int i = Tens[K - 1]; i < Tens[K]; i++) {
                vector<char> in = NumToCharArray(i, K);
                bool isAscending = true;
                for(int j = 1; j < in.size(); j++) {
                    if(in[j - 1] > in[j]) {
                        isAscending = false;
                        break;
                    }
                }
                if(isAscending) {
                    in = insert(in, keep, '.');
                    vector<char> charInsertN = in;
                    do {
                        int newN = merge(charN, charInsertN);
                        if(newN >= Tens[N - 1]) {
                            vector<char> charInsertD = in;
                            do {
                                int newD = merge(charD, charInsertD);
                                if(newN * d == newD * n) {
                                    int id = newN * 10000 + newD;
                                    if(used.find(id) == used.end()) {
                                        sumN += newN;
                                        sumD += newD;
                                        used.insert(id);
                                    }
                                }
                            } while(nextPermutation(charInsertD));
                        }
                    } while(nextPermutation(charInsertN));
                }
            }
        }
    }
    cout << sumN << " " << sumD << endl;
    return 0;
}


