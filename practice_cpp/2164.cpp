//problem: https://www.acmicpc.net/problem/2164
//date: 20230927

#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        q.push(i+1); //숫자 집어넣기
    }
    while (q.size()!=1) {
        q.pop(); //맨 위 버리기
        q.push(q.front()); //현재 맨위 넣기
        q.pop(); //넣은 것 없애기
    }
    printf("%d", q.front());
    return 0;
}

/*제일 위에 있던 것을 제일 아래로 이동한다 -> 큐*/