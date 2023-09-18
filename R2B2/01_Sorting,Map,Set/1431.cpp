//problem: https://www.acmicpc.net/problem/1431
//date: 20230918

#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>

using namespace std;

bool comp(string a, string b) {
	if (a.length() != b.length()) {
		if (a.length() > b.length()) { //switch when the lengths are the same 길이가 길면 위치 바꾸기
			return 0;
		}
		return 1;
	}
	else { //str 길이 같음
		char* arr1 = new char[a.length()];
		char* arr2 = new char[a.length()];
		int sum1 = 0;
		int sum2 = 0;
		a.copy(arr1, a.length() + 1); //copy chars of a to arr1 char배열 arr1에 a 문자 복사
		b.copy(arr2, b.length() + 1);
		for (int i = 0; i < a.length(); i++) {
			if (isdigit(arr1[i]) != 0) { //isdigit of cctype -> returns 0 when the char is not a digit
				sum1 += arr1[i] - 48; //char to int
			}
			if (isdigit(arr2[i]) != 0) {
				sum2 += arr2[i] - 48; //char to int
			}
		}
		if (sum1 != sum2) { //can compare in lexical order
			if (sum1 < sum2) {
				return 1;
			}
			else
				return 0;
		}
		else {
			if (a < b)
				return 1;
			else
				return 0;
		}
	}
}

int main(void) {
	int n;
	cin >> n;
	string* arr = new string[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n, comp);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << endl;
	}

	return 0;
}