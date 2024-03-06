//problem: https://www.acmicpc.net/problem/15650
//date: 20240131

#include <iostream>
#include <vector>

using namespace std;

void print_seq(int* seq,int m) {
	for (int i = 1; i <=m; i++) {
		cout << seq[i] << " ";
	}
	cout << "\n";
}

void make_seq(int* seq, int pt, int n, int m) {

	if (pt == m+1) {//종료조건
		print_seq(seq, m);
		return;
	}
	for (int i = seq[pt-1]; i <=n-1; i++) {
		
		seq[pt] = i+1;

		make_seq(seq, pt + 1, n, m);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;

	cin >> n >> m;

	//숫자열
	int* seq = new int[m + 1]();
	seq[0] = 0;

	make_seq(seq, 1, n, m);

	return 0;
}