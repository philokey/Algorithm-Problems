import java.io.BufferedInputStream;
import java.math.BigInteger;
import java.util.Scanner;

public class Main
{
	public static void main(String []args)
	{
		int m,n,cas;
		BigInteger a,b,tmp;
		Scanner cin = new Scanner(new BufferedInputStream(System.in));
		cas = cin.nextInt();
		for(int ca = 0; ca<cas; ca++)
		{
			m = cin.nextInt();
			n = cin.nextInt();
			a = BigInteger.valueOf(n);
			b = BigInteger.ONE;
			for(int i = 0; i < n-1; i++)
				b = b.multiply(BigInteger.valueOf(m));
			tmp = a.gcd(b);
			a = a.divide(tmp);
			b = b.divide(tmp);
			System.out.print(a);
			System.out.print("/");
			System.out.println(b);
		}

	}
}
