import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		String message=sc.next();
		char[] arr=message.toCharArray();
		
		for(int i=0;i<arr.length;i++) {
			if(i==0 || i%10!=0) {
				System.out.printf("%c",arr[i]);
			}
			else {
				System.out.println();
				System.out.printf("%c",arr[i]);
			}
		}
		sc.close();
	}
}