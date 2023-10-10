//problem: https://www.acmicpc.net/problem/14235
//date: 20231009

#include <iostream>
#include <queue>

using namespace std;

int main(void) {
	//fast io
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,a,present;
	cin >> n;
	priority_queue<int> pq; //pq default: 내림차순
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a == 0) {//선물 나눠주기
			if (pq.empty() == 1) {//줄 선물 없음
				cout << "-1\n";
			}
			else {
				cout << pq.top()<<"\n";
				pq.pop();
			}
		}
		else {//a개의 선물
			for (int k = 0; k < a; k++) {
				cin >> present;
				pq.push(present);
			}
		}
	}
	return 0;
}