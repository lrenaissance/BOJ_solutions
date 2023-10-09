//problem: https://www.acmicpc.net/problem/11286
//date: 20231008

#include <iostream>
#include <queue> //priority_queue 사용

using namespace std;

struct cmp { //cmp 구조체 작성 연습 필요. sort의 cmp 함수와 부등호 방향 다름에 유의
	bool operator()(const int& x1, const int& x2) {
		if (abs(x1) != abs(x2))
			return abs(x2) < abs(x1); //절댓값 작은 애가 앞으로
		//절댓값 같으면
		return x2 < x1; //값이 작은 애가 앞으로
	}
};

int main(void) {
	//fast io
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,x;
	cin >> n;
	priority_queue<int, vector<int>, cmp> pq;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x==0) {
			if (pq.empty() == 1) {//비어있을 경우->0 출력
				cout << "0\n";
			}
			else {
				//min 절댓값 출력 후 제거
				cout << pq.top()<<"\n";
				pq.pop();
			}
		}
		else {
			//x 추가
			pq.push(x);
		}
	}
	return 0;
}