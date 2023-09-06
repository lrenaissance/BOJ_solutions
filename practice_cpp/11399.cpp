//problem: https://www.acmicpc.net/problem/11399
//date: 20230901

#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int cnt;
	int sum = 0;
	cin >> cnt;
	int* arr = new int[cnt];
	for (int i = 0; i < cnt; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + cnt); //sorting
  //smaller number should be more frequent to make the minimum
	for (int i = cnt; i>0; i--) {
		sum = sum + i * arr[cnt-i];
	}
	cout << sum;
    return 0;
}