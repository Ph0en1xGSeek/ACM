
import java.math.*;
import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args){
		BigInteger c[] = new BigInteger[105];
		c[0] = c[1] = BigInteger.valueOf(1);
		for(int i = 2; i <= 100; i++)
			c[i] = c[i-1].multiply(BigInteger.valueOf(4*i-2)).divide(BigInteger.valueOf(i+1));
		int n;
		Scanner in = new Scanner(System.in);
		while(in.hasNext()){
			n = in.nextInt();
			System.out.println(c[n]);
		}
		
	}
}
