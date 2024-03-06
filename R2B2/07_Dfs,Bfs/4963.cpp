//problem: https://www.acmicpc.net/problem/4963
//date: 20240126

#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

typedef pair<int, int> loc;

void bfs(vector < vector<int>>& adj, queue<loc>& q, int sr, int sc, int w, int h, map<loc, int>& visited) {
	int range[3] = { -1, 0 ,1 };
	int row, col;
	loc node;

	q.push({ sr,sc });
	adj[sr][sc] = 2;

	while (!q.empty()) {
		bool status = false;
		node = q.front();
		q.pop();

		for (int i = 0; i < 3; i++) {
			for (int k = 0; k < 3; k++) {
				row = node.first + range[i];
				col = node.second + range[k];

				if ((row == node.first && col == node.second)) {
					continue;
				}


				if (row >= 0 && row < h && col >= 0 && col < w) {
					if (adj[row][col] == 1) {
						q.push({ row,col});
						adj[row][col] = adj[node.first][node.second]++;
				
					}
				}
			}
		}
        
	}
}

int main(void) {
	int w = 1;
	int h = 1;
	int cnt = 0;
    cin >> w >> h;
    
	while (w != 0 && h != 0) {
		vector<vector<int>> adj; //adjacency matrix
		queue<loc> q;
		map<loc, int> visited; //visited

		//초기화
		adj.assign(h, vector<int>(w, 0));

		for (int i = 0; i < h; i++) {//입력
			for (int k = 0; k < w; k++) {
				cin >> adj[i][k];
			}
		}

		for (int i = 0; i < h; i++) {//입력
			for (int k = 0; k < w; k++) {
				if (adj[i][k] == 1) {
					bfs(adj, q, i,k, w, h, visited);
					cnt++;
				}
			}
		}
        
    cout << cnt << "\n";   
		cnt = 0; //cnt reset
		
		cin >> w >> h;
	}

	return 0;
}