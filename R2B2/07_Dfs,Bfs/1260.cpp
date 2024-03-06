//problem: https://www.acmicpc.net/problem/1260
//date: 20231228

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

void dfs(vector<vector<bool>> &adj, vector<bool> &visited, int start) {//stack ver
	stack<int> s;
	int node=start; //현재 노드
	printf("%d ", node);
	s.push(node);

	while (!s.empty()) {
	  bool next=false; //인접 노드 유무 확인용
	  visited[node] = true;
		node = s.top();

		for (int i = 1; i<visited.size(); i++) { //인접 노드 탐색
			if (adj[node][i] == true && visited[i] == false) {
			    printf("%d ", i); //stack에 넣은 후(방문) 출력
				s.push(i);
				visited[i] = true;
				next=true;
				break;
			}
		}
		
		if(!next){ //stack을 이용해 이전으로 돌아가기 위함인데 다음 인접 노드가 없을 경우엔 stack에 있을 필요 없음
		    s.pop();
		}
	}

}

void bfs(vector<vector<bool>> &adj, vector<bool>& visited, int start) {
	queue<int> q;
	int node; //현재 노드
	q.push(start);
	visited[start] = true;

	while (!q.empty()) {
		node = q.front();
		printf("%d ", node);
		q.pop();

		for (int i = 1; i < visited.size(); i++) { //인접 노드 탐색
			if (adj[node][i] == true && visited[i] == false) {
				q.push(i);
				visited[i] = true;
			}
		}
	}

}

int main(void) {

	int n, m, start, n1, n2;
	cin >> n >> m >> start;

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

	//dfs
	dfs(adj,visited,start);
	printf("\n");
	//bfs
	visited.assign(n+1, false);
	bfs(adj,visited,start);

	return 0;
}