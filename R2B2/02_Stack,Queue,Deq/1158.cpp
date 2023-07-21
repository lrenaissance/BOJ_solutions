//problem: https://www.acmicpc.net/problem/1158
//date: 20230720

#include <iostream>
#include <queue>

using namespace std;

int main(void) {

	int n, k;
	queue<int> q;
	cin >> n >> k;
	cout << "<";
	for (int i = 1; i <= n; i++) { //queue init
		q.push(i);
	}

	while (q.empty() == false) {
		if (q.size() == 1) {
			cout << q.front()<< ">";
			break;
		}
		for (int i = 0; i < k-1; i++) {
			q.push(q.front());
			q.pop();
		}
		cout << q.front()<<", ";
		q.pop();
	}
	return 0;
}