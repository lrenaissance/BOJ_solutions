//problem: https://www.acmicpc.net/problem/1449
//date: 20230902

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	int n, l;
	int cnt = 1;
	cin >> n >> l;
	int* where = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> where[i];
	}
	sort(where, where + n);
	for (int i =0; i<n; i++) {
		for (int j = i+1; j < n; j++) {
			if (where[i] - 0.5 + l < where[j] + 0.5) {
				cnt++;
				i = j - 1;
				break;
			}
		}
	}
	printf("%d", cnt);
	return 0;
}