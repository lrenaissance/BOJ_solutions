//problem: https://www.acmicpc.net/problem/1325
//date: 20240128

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

#define MAX 10001
using namespace std;

vector<int> adj[MAX]; //인접 리스트

int dfs(vector<bool>& visited, int start) {
	int node = start;
	visited[node] = true;
	int cnt = 1;

	for (int i = 0; i < adj[node].size(); i++) {
		int next = adj[node][i];
		if (visited[next] == false) {
			cnt += dfs(visited, next); //cnt++이 아니라 밑의 결과를 더해줘야함
		}
	}
	return cnt;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m, start, end, cnt,tmp, max;
	cin >> n >> m;

	//int** adj = new int* [n+1]; //동적할당
	//for (int i = 0; i < n+1; i++) {
	//	adj[i] = new int[n+1];
	//}

	//for (int i = 0; i < n+1; i++) { //초기화
	//	for (int k = 0; k < n+1; k++) {
	//		adj[i][k] = 0;
	//	}
	//}

	vector<bool> visited; //visited:1
	vector<int> result;

	for (int i = 0; i < m; i++) {//신뢰관계 입력
		cin >> end >> start;
		adj[start].push_back(end);
	}

	max = 0;
	for (int i = 0; i < n; i++) {
		visited.assign(n + 1, false); //assign 이용해 초기화
		tmp = dfs(visited, i + 1); 

		if (tmp > max) {
			max = tmp;
			result = { i+1 };
		}
		else if (tmp == max) {
			result.push_back(i+1);
		}
	}
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}

	return 0;
}

// 1트: 메모리 초과
/*사유: adj matrix -> O(n^2) vs adj list -> O(n+e)
간선의 수의 최댓값(10^5)이 정점의 수(10^3)의 제곱의 최댓값보다 작음 -> adj list가 효율적*/