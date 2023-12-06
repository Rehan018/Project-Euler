import java.io.*;
import java.util.*;

public class Solution {

       static boolean isPrime(int x) {
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                return false;
            }
        }
        return true;
    }

    static boolean areAllRotationsPrime(int x) {
        int d = 1;
        int num = x;
        int digits = 0;

        while (d <= num) {
            d *= 10;
            digits++;
        }
        d /= 10;

        for (int k = 0; k < digits; k++) {
            int rotation = (x % 10) * d + (x / 10);
            if (!isPrime(rotation)) {
                return false;
            }
            x = rotation;
        }

        return true;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int sum = 0;

        for (int i = 2; i < n; i++) {
            if (isPrime(i) && areAllRotationsPrime(i)) {
                sum += i;
            }
        }

        System.out.println(sum);
        scanner.close();
    }
}
