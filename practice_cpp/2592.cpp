//problem: https://www.acmicpc.net/problem/2592
//date: 20230724

#include <iostream>

using namespace std;

int main(void) {

	int max=0; //cannont use int max,index,sum=0 -> only initializes sum as 0(this error took me so long to fix it...)
  int index,sum = 0;
	int* input=new int[10];
	int* cnt=new int[101];//to use smaller space, divide the inputs with 10
	
	for(int i=0;i<10;i++){
	    cin>>input[i];
	    sum+=input[i];
	    cnt[input[i]/10]++;
	}
	for(int i=0;i<101;i++){
	    if(max<=cnt[i]){
	        max=cnt[i];
	        index=i;
	    }
	}
	
	
	cout << sum / 10 << "\n"; //average
	cout << index*10 << "\n"; //mode //multiply 10 to get the input back

	return 0;
}