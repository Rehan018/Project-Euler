import java.io.*;
import java.util.*;
import java.util.Scanner;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

public class Solution {
    private static int SUNDAY = 0;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        while (t-- > 0) {
            long[][] dateArray = new long[2][3];
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 3; j++) {
                    dateArray[i][j] = in.nextLong();
                }
            }
            adjust(dateArray);
            long ak = 0;
            while (true) {
                if (dateArray[0][2] == 1) {
                    if (verify(dateArray[0][0], dateArray[0][1], dateArray[0][2])) {
                        ak++;
                    }
                }
                dateArray[0][2] = 1;
                dateArray[0][1]++;
                if (dateArray[0][1] > 12) {
                    dateArray[0][1] = 1;
                    dateArray[0][0]++;
                }
                if (overDate(dateArray)) {
                    break;
                }
            }
            System.out.println(ak);
        }
        in.close();
    }

    private static boolean overDate(long[][] dateArray) {
        if (dateArray[0][0] > dateArray[1][0]) {
            return true;
        } else if (dateArray[0][0] == dateArray[1][0]) {
            if (dateArray[0][1] > dateArray[1][1]) {
                return true;
            } else if (dateArray[0][1] == dateArray[1][1]) {
                if (dateArray[0][2] > dateArray[1][2])
                    return true;
            }
        }
        return false;
    }

    private static void adjust(long[][] dateArray) {
        if (overDate(dateArray)) {
            exchange(dateArray);
        }
    }

    private static void exchange(long[][] dateArray) {
        long[] tmp = new long[3];
        tmp = dateArray[1];
        dateArray[1] = dateArray[0];
        dateArray[0] = tmp;
    }

    private static boolean verify(long year, long month, long day) {
        if (month < 3) {
            month += 12;
            year -= 1;
        }
        long c = year / 100;
        long y = year % 100;
        int w = (int) ((y + (y / 4) + (c / 4) - (2 * c) + ((26 * (month + 1)) / 10) + day - 1) % 7);
        return w == SUNDAY;
    }
}
