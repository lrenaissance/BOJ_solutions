import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int num=0;
		num=sc.nextInt();
		for(int i=0;i<num;i++) {
			int sum=0;
			double over,avg=0;
			int cnt=sc.nextInt();
			int[] score=new int[cnt];
			for(int j=0;j<cnt;j++) {
				score[j]=sc.nextInt();
				sum+=score[j]; 
			}
			avg=(double)sum/cnt;
			over=0;
			for(int j=0;j<cnt;j++) {
				if(score[j]>avg) { 
					over++;
				}
			}
			System.out.printf("%.3f%%\n",over/cnt*100);
		}
		sc.close();
	}
}