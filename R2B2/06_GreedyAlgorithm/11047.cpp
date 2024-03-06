//problem: https://www.acmicpc.net/problem/11047
//date: 20230902

#include <iostream>

using namespace std;

int main(void) {
	int n, k, max_ind;
	int min = 0;
	cin >> n >> k;
	int* coin = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> coin[i]; //코인 가치 입력
		if (coin[i] <= k) {
			max_ind = i;//최대 코인 가치 인덱스
		}
	}
	for (int i = max_ind; i>=0; i--) {
		min = min + k / coin[i];
		k = k % coin[i];
		if (k == 0) {
			break;
		}
	}
	printf("%d", min);
	return 0;
}