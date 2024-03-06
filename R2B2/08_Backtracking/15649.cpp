//problem: https://www.acmicpc.net/problem/15649
//date: 20240130

#include <iostream>
#include <vector>

using namespace std;

void make_seq(int *seq, bool *used, int pt, int n, int m) {

	if (pt==m) {//종료조건
		for (int i = 0; i < m; i++) {
			cout << seq[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (used[i-1] == true) {
			continue;
		}
		
		seq[pt] = i;
		used[i-1] = true;
		//pt++; -> 잘못된 실행 결과(반복문 돌면서 pt 자체가 이동하게 됨)

		make_seq(seq, used, pt+1, n, m);

		used[i-1] = false;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;

	cin >> n >> m;
	
	int* seq = new int[m+1]();

	bool* used = new bool[n];

	make_seq(seq,used,0, n, m);

	return 0;
}