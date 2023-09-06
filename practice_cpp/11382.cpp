//problem: https://www.acmicpc.net/problem/9012
//date: 20230901

#include <iostream>

using namespace std;

int main(void) {
  //given number range was (1 ≤ A, B, C ≤ 10^12)
  //(signed) long long covers -9,223,372,036,854,775,808 ~ 9,223,372,036,854,775,807(about 10^16)
  //(unsigned) long long covers 0 ~ 18,446,744,073,709,551,615(about 10^19)
	long long a, b, c;
	cin >> a >> b >> c;
	cout << a + b + c;
	return 0;
}