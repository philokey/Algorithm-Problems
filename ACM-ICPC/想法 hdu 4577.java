/*
题意：给n个数k个盒子，盒子中的数字要满足ai+1=2*ai，问地一个盒子里最多可放几个数字。
解法：放进盒子的相邻的数为 x*2^(i-1)且x是奇数.对于每一个这样的序列，第一个盒子可以放 长度/k个数字。
可以以k为单位长度，放入。对于长度k，第一个盒子可以放入 n/(2^(k-1))-n/(2^k)个数字，长度2k可以放入
n/(2^(2k-1))-n/(2^2k)个数字，以此类推
*/
import java.io.BufferedInputStream;
import java.math.BigInteger;
import java.util.Scanner;

public class Main
{
	public static void main(String []args)
	{
		BigInteger a,ans,p,tmp;
		int ca,k;
		Scanner cin = new Scanner(new BufferedInputStream(System.in));
		ca = cin.nextInt();
		for(int i = 0; i < ca; i++)
		{
			ans = BigInteger.ZERO;
			a = cin.nextBigInteger();
			k = cin.nextInt();
			p = BigInteger.valueOf((1<<(k-1)));			
			while(true)
			{
				a = a.divide(p);				
				if(a.equals(BigInteger.ZERO)) break;
				tmp = a.subtract(a.shiftRight(1));				
				ans = ans.add(tmp);
				//System.out.println(tmp);
				//System.out.println(ans);
				a = a.shiftRight(1);
			}
			System.out.println(ans);
		}
	}
}
