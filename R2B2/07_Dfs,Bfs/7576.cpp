//problem: https://www.acmicpc.net/problem/7576
//date: 20231230

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> loc; //pair 만들기

int bfs(vector<vector<int>>& adj, queue<loc>& q, int n, int m, int unripe) {
	loc node; //현재 노드
	int cnt = 0;

	while (!q.empty()) {
		node = q.front();
		q.pop();
		cnt = adj[node.first][node.second];

		if (node.first - 1 >= 0) {
			if (adj[node.first - 1][node.second] == 0) { //위
				adj[node.first - 1][node.second] = cnt+1;//n일째 익었다는 뜻
				q.push({ node.first - 1,node.second });
				unripe--;
			}
		}
		if (node.first + 1 < n) {
			if (adj[node.first + 1][node.second] == 0) { //아래
				adj[node.first + 1][node.second] = cnt + 1;
				q.push({ node.first + 1,node.second });
				unripe--;
			}
		}
		if (node.second - 1 >= 0) {
			if (adj[node.first][node.second - 1] == 0) { //왼
				adj[node.first][node.second - 1] = cnt + 1;
				q.push({ node.first,node.second - 1 });
				unripe--;
			}
		}
		if (node.second + 1 < m) {
			if (adj[node.first][node.second + 1] == 0) { //오
				adj[node.first][node.second + 1] = cnt + 1;
				q.push({ node.first,node.second + 1 });
				unripe--;
			}
		}
	}

	if (unripe == 0) {
		return cnt-1; //첫날은 포함안됨
	}
	return -1;
}

int main(void) {

	int m, n;
	int unripe = 0;//안 익은 토마토 개수
	cin >> m >> n;

	vector<vector<int>> adj; //adjacency matrix

	queue<loc> q; //queue

	//초기화
	adj.assign(n, vector<int>(m, -1));

	for (int i = 0; i < n; i++) {//입력받기
		for (int k = 0; k < m; k++) {
			cin >> adj[i][k];
			if (adj[i][k] == 1) {//riped->q push
				q.push({ i,k });
			}
			else if (adj[i][k] == 0) {
				unripe++;
			}
		}
	}
	if (unripe == 0) {
		cout << 0;
		return 0;
	}

	cout << bfs(adj, q, n, m, unripe);

	return 0;
}