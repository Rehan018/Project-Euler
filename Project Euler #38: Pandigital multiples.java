import java.io.*;
import java.util.*;

public class Solution {

 
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
     static boolean isPandigital(int n, int k) {
        int i = 1;
        StringBuilder numbers = new StringBuilder();

        while (true) {
            numbers.append(n * i);
            if (numbers.length() >= k) {
                break;
            }
            i++;
        }

        if (numbers.length() == k && isSubset(numbers.toString(), k)) {
            return true;
        }
        return false;
    }

    static boolean isSubset(String numbers, int k) {
        for (int a = 1; a <= k; a++) {
            if (!numbers.contains(Integer.toString(a))) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] input = scanner.nextLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int k = Integer.parseInt(input[1]);

        for (int i = 2; i < n; i++) {
            if (isPandigital(i, k)) {
                System.out.println(i);
            }
        }

        scanner.close();
    }
}
