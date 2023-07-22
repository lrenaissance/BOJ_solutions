//problem: https://www.acmicpc.net/problem/2231
//date: 20230721

#include <iostream>

using namespace std;

int generator(int num) {
	int sum = num;
	while (num / 10 != 0) {
		sum = sum + num % 10;
		num /= 10;
	}
	sum = sum + num % 10; //can miss the largest digit without this line
	return sum;
}

int main(void) {
	int num,check;
	cin >> num;

	for (int i = 1; i <= num; i++) {
		check = generator(i);
		if (check == num) {
			cout << i;
			break;
		}
		if (i == num) { //always check conditions!!! when i==num and there is no generator -> print 0
			cout << 0;
		}
	}

	return 0;
}