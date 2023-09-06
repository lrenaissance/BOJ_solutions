//problem: https://www.acmicpc.net/problem/2798
//date: 20230902

#include <iostream>

using namespace std;

int main(void) {
	int n, m, sum;
	int max = 0;
	cin >> n >> m;
	int* cards = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> cards[i];
	}
	for (int i = 0; i < n-2; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				sum = cards[i] + cards[j] + cards[k];
				if (sum > max && sum<=m) {
					max = sum;
				}
			}
		}
	}
	cout << max;
	return 0;
}