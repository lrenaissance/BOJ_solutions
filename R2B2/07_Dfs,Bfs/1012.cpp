//problem: https://www.acmicpc.net/problem/1012
//date: 20240129

#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

typedef pair<int,int> loc; //(x, y)

vector<int> adj[2500]; //인접 리스트

void bfs(vector<vector<int>>& adj, map<loc, bool> &visited, queue<loc> q, loc l, int w, int h) {
	int row, col;
	loc node;

	q.push(l);

	while (!q.empty()) {
		node = q.front();
		visited[node]=true;
		row=node.first;
		col=node.second;
		q.pop();

        if (row>=1 && adj[row-1][col] == 1) { //위
			q.push({ row-1,col });
			adj[row-1][col] = adj[row][col]++;
		}
		
		if (row<=h-2 && adj[row+1][col] == 1) { //아래
			q.push({ row+1,col });
			adj[row+1][col] = adj[row][col]++;
		}
		
		if (col>=1 && adj[row][col-1] == 1) { //왼
			q.push({ row,col-1 });
			adj[row][col-1] = adj[row][col]++;
		}
		
		if (col<=w-2 && adj[row][col+1] == 1) { //오
			q.push({ row,col+1 });
			adj[row][col+1] = adj[row][col]++;
		}
	}

}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t, m, n, k, x, y;
	cin >> t;

	for (int j = 0; j < t; j++) {
		cin >> m >> n >> k;
        int cnt = 0;
        
		//adj
		vector<vector<int>> adj;
		adj.assign(n, vector<int>(m, 0));

		//visited
		map<loc, bool> visited;

		//q
		queue<loc> q;

		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			adj[y][x]=1;
			visited.insert(pair<loc,bool>({y,x},false));
		}

		for (auto iter = visited.begin(); iter != visited.end(); iter++) {
			if (iter->second == false) {
				bfs(adj, visited, q, iter->first,m,n);
				cnt++;
			}
		}

		cout << cnt<<"\n";
		adj.clear();
		visited.clear();
	}

	return 0;
}