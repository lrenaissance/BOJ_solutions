//problem: https://www.acmicpc.net/problem/1946
//date: 20230724

#include <iostream>

using namespace std;

int main(void) {

	int testcase, cnt, doc, intv, total, min;
	cin >> testcase;

	for (int j = 0; j < testcase; j++) {
	    cin>>cnt;
		int* list = new int[cnt]; //the mistake I made: used ()(used for single space) instead of [] -> runtime error(insufficient space)
		total = cnt;

		for (int i = 0; i < cnt; i++) {
			cin >> doc >> intv;
			list[doc - 1] = intv - 1;
		}
		min = list[0];

		for (int i = 1; i < cnt; i++) {
			if (list[i] > min) {
				total--;
			}
			else {
				min = list[i];
			}
		}

		cout << total << "\n";

	}

	return 0;
}