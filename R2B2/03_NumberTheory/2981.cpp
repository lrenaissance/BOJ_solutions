//problem: https://www.acmicpc.net/problem/2981
//date: 20230922

#include <iostream>
#include <algorithm>

using namespace std;

int find_gcd(int a, int b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

void find_factor(int gcd) {//약수 구하는 함수
	if (gcd <= 0)
		return;
	for (int i = 2; i <= gcd / 2; i++) { 
		//약수를 자신의 절반 이하 범위에서 가짐(일반 약수면 1이지만 M>1 조건 떼문에 2부터 시작)
		if (gcd % i == 0) {
			printf("%d ", i);
		}
	}
	printf("%d", gcd); //약수에 본인 포함
}

void find_list(int* nums, int n) {
	int gcd;
	int* new_nums = new int[n - 1]();
	for (int i = 0; i < n - 1; i++) {
		new_nums[i] = nums[i + 1] - nums[i]; // 두 수의 차를 저장(나머지 처리용)
	}
	gcd = find_gcd(new_nums[0], new_nums[1]);
	for (int i = 2; i < n - 1; i++) {
		gcd = find_gcd(gcd, new_nums[i]);
	}
	find_factor(gcd);
}


int main(void) {
	int n;
	cin >> n;
	int* nums = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	sort(nums, nums + n);
	find_list(nums, n);
	return 0;
}

/*사고 과정: 나머지가 같다를 어떻게 확인하냐 -> 나머지가 뭐였지? -> n = aq+b로 표현 가능(q: 몫, b: 나머지), 이때 a를 찾아야하는 문제

1) 첫번째 생각: n1= a1q1+b1, n2=a2q2+b2일 때 b1==b2이려면 b1은 주어진 n중 가장 작은 수의 나머지일 수 밖에 없다. min의 나머지를 구해서, nk-bk의 최대공약수를 찾자.
-> 기각 사유: 실제로 구현하려고 보니 다중반복문 써야함 + 근데 시간은 1초이고 input 범위는 10^9 이하임(불가능)

2) 두번째 생각: nk-bk 말고 나머지 처리할 방법? n1과 n2를 빼자.
  2-1) 두 개씩 묶어 빼기. n이 홀수개, 짝수개일 때 케이스 분류해서 뺄셈 진행
    문제: 홀수개일 땐 남은 하나가 나머지를 갖고 있는 상태로 최대공약수를 구하게 되어 잘못된 값.
  2-2) 아예 앞뒤로 빼기. 가능한가? a와 b의 최대공약수는 (a-b)와 b의 최대공약수와 같으므로(유클리드 호제법) 가능하겠다.*/