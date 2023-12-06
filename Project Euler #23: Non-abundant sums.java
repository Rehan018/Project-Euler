import java.io.*;
import java.util.*;

public class Solution {

    static ArrayList<Integer> primes = new ArrayList<>(Arrays.asList(2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47));
    static ArrayList<Integer> abundants = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());

        findPrimes(28123);
        findAbundants(28123);

        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            if (n > 28123) {
                System.out.println("YES");
                continue;
            }
            if (solve(n)) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }

    static long power(long x, long y) {
        long ans = 1;
        while (y > 0) {
            if ((y & 1) == 1) {
                ans = ans * x;
            }
            x = x * x;
            y >>= 1;
        }
        return ans;
    }

    static void findPrimes(int n) {
        for (int i = 51; i <= n; i += 2) {
            boolean flag = false;
            for (int j : primes) {
                if (j * j > i) {
                    break;
                }
                if (i % j == 0) {
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                primes.add(i);
            }
        }
    }

    static boolean isAbundant(int n) {
        long ans = 1;
        int nCopy = n;
        for (int i : primes) {
            if (i * i > nCopy) {
                break;
            }
            if (n % i == 0) {
                int cnt = 0;
                while (n % i == 0) {
                    cnt++;
                    n /= i;
                }
                ans *= ((power(i, cnt + 1) - 1) / (i - 1));
            }
        }
        if (n > 1) {
            ans *= ((n * n - 1) / (n - 1));
        }
        ans -= nCopy;
        return ans > nCopy;
    }

    static boolean solve(int n) {
        for (int i : abundants) {
            if (i > n / 2 + 1) {
                return false;
            }
            if (Collections.binarySearch(abundants, n - i) >= 0) {
                return true;
            }
        }
        return false;
    }

    static void findAbundants(int n) {
        for (int i = 2; i <= n; i++) {
            if (isAbundant(i)) {
                abundants.add(i);
            }
        }
    }
}
