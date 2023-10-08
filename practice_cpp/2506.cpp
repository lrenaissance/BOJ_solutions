//problem: https://www.acmicpc.net/problem/2506
//date: 20231003

#include <iostream>

using namespace std;

int main(void) {
	int n;
	int accum = 0;
	int sum = 0;
	cin >> n;
	int* num = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> num[i];
		if (num[i] == 0) {
			accum = 0;
			continue;
		}
		else{
			accum++;
			sum += accum;
		}
	}
	printf("%d", sum);

	return 0;
}