//problem: https://www.acmicpc.net/problem/1747
//date: 20231001

#include <iostream>
#include <string> //to_string
#include <cmath>
using namespace std;

bool palindrome(int n) {
    string str = to_string(n); //to_string: int를 string으로 처리해서 다루기 위해
    for (int i = 0; i < str.length() / 2; i++) {
        if (str[i] != str[str.length() - 1 - i]) { //대칭 확인
            return false;
        }
    }
    return true;
}

void is_prime(int n, bool* check_prime) { //초기화 이슈로 t/f 뒤집음
//false: prime number
    check_prime[0] = true;
    check_prime[1] = true;
    for (int i = 2; i <= sqrt(n); i++) {//sqrt(n)까지만 탐색해도 됨
        if (check_prime[i] == false) {
            for (int j = i * i; j <= n; j += i) {
                check_prime[j] = true;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    bool* check_prime = new bool[2000000](); //1,000,000 이상의 소수이고 팰린드롬인 수는 최대 2,000,000 이하(임의로 잡음)
    is_prime(2000000, check_prime); //일단 에라토스테네스의 체로 다 정리해놓기
    while (1) {
        if (check_prime[n] == false && palindrome(n) == true) { //소수이고 팰린드롬인지 체크
            printf("%d", n);
            return 0;
        }
        else {
            n++;
        }
    }
    return 0;
}

/*시행착오: 처음에 배열 공간 많이 쓰기 싫어서 반복문 안에다가 is_prime을 넣어버림 -> 시간 초과
어차피 최대값은 2,000,000 이하라고 생각하고 공간을 미리 할당하여 is_prime 계산하는 방식으로 수정*/