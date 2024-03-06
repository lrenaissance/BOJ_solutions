//problem: https://www.acmicpc.net/problem/2606
//date: 20231228

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<bool>> &adj, vector<bool>& visited) {
	queue<int> q;
	int node; //현재 노드
	int cnt = 0;
	q.push(1);
	visited[1] = true;

	while (!q.empty()) {
		node = q.front();
		q.pop();

		for (int i = 1; i < visited.size(); i++) { //인접 노드 탐색
			if (adj[node][i] == true && visited[i] == false) {
				q.push(i);
				cnt++;
				visited[i] = true;
			}
		}
	}

	printf("%d", cnt);

}

int main(void) {

	int n, m, n1, n2;
	cin >> n >> m;

	vector<vector<bool>> adj; //adjacency matrix
	vector<bool> visited; //visited:1

	//초기화
	adj.assign(n+1, vector<bool>(n+1, false));
	visited.assign(n+1, false);

	for (int i = 0; i < m ; i++) { //edge 입력받기
		cin >> n1 >> n2;
		adj[n1][n2] = true;
		adj[n2][n1] = true; //양방향
	}

	bfs(adj,visited);

	return 0;
}