import java.io.*;
import java.util.*;
import java.math.BigInteger;

public class Solution {

public static void main(String[] args) {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    Scanner sc = new Scanner(System.in);
    int testcases = sc.nextInt();
    for(int i=0;i<testcases;i++){
        int numb = sc.nextInt();
        BigInteger num = BigInteger.valueOf(numb);
        System.out.println(sumofdigit(num));
    }
    sc.close();
}
public static BigInteger sumofdigit(BigInteger num){
    BigInteger res;
    res = factorial(num);

    BigInteger rem;
    BigInteger temp = new BigInteger("10");
    BigInteger sum =new BigInteger("0");

    while(res.compareTo(BigInteger.ZERO) > 0){
       rem = res.mod(temp);
       sum = sum.add(rem); 
       res = res.divide(temp);
    }
    return sum;
}
public static BigInteger factorial(BigInteger num){

   BigInteger sum = new BigInteger("1");
   while(num.compareTo(BigInteger.ZERO)>0){
       sum = sum.multiply(num);
       num = num.subtract(BigInteger.ONE);
   } 
   return sum;
}
}
