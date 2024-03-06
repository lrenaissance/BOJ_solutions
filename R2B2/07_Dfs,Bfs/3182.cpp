//problem: https://www.acmicpc.net/problem/3182
//date: 20240128

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> adj[1001]; //인접 리스트

int dfs(vector<bool>& visited, int start) {
	int node = start;
	visited[node] = true; //시작 방문
	int cnt = 1;

	for (int i = 0; i < adj[node].size(); i++) {
		int next = adj[node][i]; //인접 탐색
		if (visited[next] == false) {
			cnt += dfs(visited, next);
		}
	}
	return cnt;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, start, end, tmp, max, max_ind;
	cin >> n;

	vector<bool> visited; //visited:1

	for (int i = 0; i < n; i++) {//입력
		start = i+1;
		cin >> end;
		adj[start].push_back(end);
	}

	max = 0;
	for (int i = 0; i < n; i++) {
		visited.assign(n + 1, false); //assign 이용해 초기화
		tmp = dfs(visited, i + 1); 

		if (tmp > max) { //tmp가 더 큼
			max = tmp;
			max_ind = i + 1;
		}
	}

	cout << max_ind; 

	return 0;
}