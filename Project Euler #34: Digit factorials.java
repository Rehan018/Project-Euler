import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
             Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int sum = 0;

        if (n < 19) {
            sum = 0;
        } else if (n < 21) {
            sum = 19;
        } else {
            sum = 19;
            Map<Integer, Integer> dic = new HashMap<>();

            for (int j = 0; j < 10; j++) {
                dic.put(j, factorial(j));
            }

            for (int i = 21; i < n; i++) {
                int tmpSum = 0;
                int oddSum = 0;
                String strI = Integer.toString(i);

                for (char s : strI.toCharArray()) {
                    if (s == '0' || s == '1') {
                        oddSum += 1;
                    }
                }

                if (oddSum % 2 == 1 && i % 2 == 0) {
                    continue;
                }

                for (char s : strI.toCharArray()) {
                    tmpSum += dic.get(Character.getNumericValue(s));
                }

                if (tmpSum % i == 0) {
                    sum += i;
                }
            }
        }

        System.out.println(sum);
        scanner.close();
    }

    static int factorial(int n) {
        if (n <= 1) {
            return 1;
        }
        return n * factorial(n - 1);
    
    }
}
