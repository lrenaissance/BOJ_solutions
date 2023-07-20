//problem: https://www.acmicpc.net/problem/2609
//date: 20230719

#include <iostream>

using namespace std;

int gcd(int a,int b) { //using Euclidean algorithm
	while (b) { //when b is 0, a is the gcd
		a = a % b; //GCD(a,b)=GCD(a%b,b)
		swap(a, b); //since a is now smaller than b, swap them
	}
	return a;
}

int main(void) {
	int a, b,g;
	cin >> a >> b;
	g = gcd(a, b);
	cout <<g<<"\n";
	cout << a * b / g; 
	//when A=a*G, B=b*G, then L=G*a*b -> L*G=A*B
	return 0;
}