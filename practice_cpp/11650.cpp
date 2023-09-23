//problem: https://www.acmicpc.net/problem/11650
//date: 20230920

#include <iostream>
#include <algorithm>

using namespace std;

typedef struct {
	int x;
	int y;
}point;

bool comp(point a, point b) {
	if (a.x != b.x)
		return a.x < b.x;
	else //a.x == b.x
		return a.y < b.y;
}

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	point* arr = new point[n];

	for (int i = 0; i < n; i++) {//입력
		cin >> arr[i].x >> arr[i].y;
	}
	sort(arr, arr + n, comp);
	for (int i = 0; i < n; i++) { //출력
		cout << arr[i].x <<" "<< arr[i].y<<"\n";
	}
	return 0;
}

/*사고 과정: 단순히 정렬하면 되는 문제라 algorithm의 sort 함수 이용하였음

교훈: 계속 시간 초과가 떴는데 이유는 처음에 32번 line에 \n이 아닌 endl을 써서였음. 웬만하면 endl 쓰지말 것!! cin, cout 때문에 생기는 런타임은 
	  ios_base::sync_with_stdio(false);
	  cin.tie(NULL);
  이것을 써서 해결할 수 있으나, 이 코드를 한 번 쓰면 이제 printf나 scanf 등 stdio에서 제공하던 것들을 쓸 수 없다. 이 부분은 추후 마저 공부하겠음*/