import java.util.*;
import java.math.*;
public class Solution {

    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        int T=sc.nextInt();
        for(int i =0;i<T;i++)
        {
            int N=sc.nextInt();
            int M=sc.nextInt();
 BigInteger path = fact(BigInteger.valueOf(N+M)) .divide(fact(BigInteger.valueOf(N))) .divide(fact(BigInteger.valueOf(M))) .mod((BigInteger.valueOf(1000000007)));
            System.out.println(path.toString());

        }
        sc.close();
    }
   static BigInteger fact(BigInteger num)
    {
        if (num == BigInteger.ZERO)
            return BigInteger.ONE;

        return num.multiply(fact(num.subtract(BigInteger.ONE )));
    }
}
