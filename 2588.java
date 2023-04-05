import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int a=sc.nextInt();
		int b=sc.nextInt();
		int one,ten,hun;
		one=a*(b%10);
		ten=a*(b%100-b%10)/10;
		hun=a*(b/100);
		System.out.println(one+"\n"+ten+"\n"+hun);
		System.out.println(a*b);
	}
}