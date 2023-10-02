//problem: https://www.acmicpc.net/problem/1977
//date: 20230930
#include <iostream>
#include <cmath> //ceil(), floor() 함수 이용
using namespace std;

int main(void) {
	int m, n;
	int sum = 0;
	int cnt = 0;
	cin >> m >> n;
  //m이상 n이하의 자연수 완전제곱수여야 하므로 처리 다르게
	m = (int)ceil(sqrt(m)); //소수 올림 ex) 3.1 -> 4.0
	n = (int)floor(sqrt(n)); //소수 버림 ex) 3.9 -> 3.0
	for (int i = m; i <= n; i++) {
		sum += i * i;
		cnt++;
	}
	if(cnt==0)
		printf("-1");
	else {
		printf("%d\n", sum);
		printf("%d\n", m*m);
	}
	return 0;
}