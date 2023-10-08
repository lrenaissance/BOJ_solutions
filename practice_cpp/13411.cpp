//problem: https://www.acmicpc.net/problem/13411
//date: 20231005

#include <iostream>
#include <cmath> //sqrt()
#include <algorithm>

using namespace std;

typedef struct point {
	double time;
	int x,y,num;
};

double dist(point p) {
	return sqrt((double)p.x * p.x + (double)p.y * p.y); //casting to double(for sqrt)
}

bool cmp(point a, point b) {
	if (a.time == b.time) {
		return a.num < b.num;
	}
	return a.time < b.time;
}

int main(void) {
	int n,v;
	cin >> n;
	point tmp;
	point* bots = new point[n];
	for (int i = 0; i < n; i++) {
		cin >> tmp.x >> tmp.y >> v;
		bots[i].num = i+1;
		bots[i].time = dist(tmp) / v;
	}
	sort(bots, bots + n,cmp);

	for (int i = 0; i < n; i++) {
		printf("%d\n", bots[i].num);
	}

	return 0;
}