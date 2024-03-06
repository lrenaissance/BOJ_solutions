//problem: https://www.acmicpc.net/problem/17451
//date: 20231015

#include <iostream>
#include <cmath>
//must review again
using namespace std;

int main(void) {
	//fast io
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	

	int n;
	double vel = 1;
	cin >> n;
	double* v = new double[n];

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	
	for (int i = n-1; i>=0; i--) {
		vel = ceil(vel / v[i]) * v[i];
	}
	
	cout << (long long)vel;
	return 0;
}