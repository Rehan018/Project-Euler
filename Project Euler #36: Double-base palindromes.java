import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int k = in.nextInt();
        System.out.println(getPalindromsSum(n, k));
    }
    
    private static  long getPalindromsSum(int n, int k) {
        int[] digits10 = new int[100];
        int[] digitsK = new int[100];
        long sum = 1;
        int size10 = 1;
        int sizeK = 1;
        digits10[0] = 1;
        digitsK[0] = 1;
        for (int i=2; i<n; ++i) {
            size10 = incrementDigits(digits10, 10, size10);
            sizeK = incrementDigits(digitsK, k, sizeK);
            if (isPalindrom(digits10, size10) && isPalindrom(digitsK, sizeK))
                sum += i;
        }
        return sum;
    }

    private static int incrementDigits(int[] digits, int k, int sizeDigits) {
        int p = 0;
        while (digits[p] == k-1) {
            digits[p] = 0;
            p++;
        }
        digits[p] = digits[p] + 1;
        return Math.max(p+1, sizeDigits);
    }
    
    private static boolean isPalindrom(int[] digits, int sizeDigits) {
        int max = sizeDigits/2;
        for (int i=0; i<max; ++i) {
            if (digits[i] != digits[sizeDigits-1-i]) {
                return false;
            }
        }
        return true;
    }
}
