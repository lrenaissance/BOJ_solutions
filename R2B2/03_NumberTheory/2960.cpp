//problem: https://www.acmicpc.net/problem/2960
//date: 20230720

#include <iostream>
#include <cmath>

using namespace std;

int isPrime(int n, int k) {
	bool *is_prime=new bool(n+1);
	
	for (int i = 0; i < n+1; i++) {
	    is_prime[i]=1;
	}

	int cnt = 0;
	for (int i = 2; i <= n; i++) {
		if (is_prime[i] == 1) {
		    cnt++;
			if (cnt == k) {
				return i;
			}
			for (int j = i * i; j <= n; j = j + i) {
				if(is_prime[j] == 0){
				    continue;
				}
				is_prime[j] = 0;
				cnt++;
				if (cnt == k) {
					return j;
				}
			}
		}
	}
}

int main(void) {
	int n, k;
	cin >> n >> k;
	cout << isPrime(n, k);
	return 0;
}