import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        int num;
        double avg=0;
        double max=0; 
        double [] score=new double[1000];
        Scanner sc=new Scanner(System.in);
        num=sc.nextInt();
        for(int i=0;i<num;i++) {
        	score[i]=sc.nextDouble();
        	if(score[i]>max) {
        		max=score[i];
        	}
        }
        for(int i=0;i<num;i++) {
        	score[i]=score[i]/max*100;
        	avg+=score[i];
        }
        System.out.println(avg/num);
        }
}