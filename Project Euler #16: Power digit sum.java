import java.io.*;
 import java.util.*; 
import java.math.*;

public class Solution {

public static void main(String[] args) {
    Scanner sc=new Scanner(System.in);
    int t=sc.nextInt();
    for(int i=0;i<t;i++){
        int n=sc.nextInt();
        BigInteger base=BigInteger.valueOf(2);
        BigInteger p=base.pow(n);
        BigInteger sum=BigInteger.ZERO;
        BigInteger v1=BigInteger.ZERO;
        BigInteger div=BigInteger.TEN;
        while(p.compareTo(BigInteger.ZERO)>0){
             v1=p.remainder(div);
             p=p.divide(div);
             sum=sum.add(v1);
        }
        System.out.println(sum);
    }

}
}
