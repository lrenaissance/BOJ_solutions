//problem: https://www.acmicpc.net/problem/10816
//date: 20231006

#include <iostream>
#include <unordered_map> //unordered_map 사용

using namespace std;

int main(void) {
	//fast io
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m, n, key;
	cin >> n;
	//map(tree. sorted)은 find가 O(logn), unordered_map(hash table. unsorted)은 O(1)
	unordered_map<int, int> m1;
	for (int i = 0; i < n; i++) {
		cin >> key;
		m1[key]++;
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> key;
		cout<<m1[key]<<" ";
	}

	return 0;
}