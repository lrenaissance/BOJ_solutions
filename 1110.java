import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int a,b,num,cnt=0;
		num=n;
		do {
			if(num/10<1) {//10보다 작음
				a=0;
				b=num;
			}
			else {
				a=num/10;
				b=num%10;
			}
			num=(a+b)%10+b*10;
			cnt++;
		}while(num!=n);
		System.out.println(cnt);
	}
}