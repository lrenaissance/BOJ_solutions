//problem: https://www.acmicpc.net/problem/1476
//date: 20230930

#include <iostream>
using namespace std;

int main(void) {
	int e, s, m;
	int x, y, z;
	int year=1;
	cin >> e >> s >> m;
  //나머지 계산의 예외를 미리 처리
	if (e == 15)
		e = 0;
	if (s == 28)
		s = 0;
	if (m == 19)
		m = 0;
	while (1) {
		//year=15*x+e=28*y+s=19*z+m
		if ((year % 15 == e) && (year % 28 == s) && (year % 19 == m)) {
			break;
		}
		year++;
	}
	printf("%d", year);
	return 0;
}
//문제 읽으면서 진법 계산하는 거랑 비슷하다고 느꼈음