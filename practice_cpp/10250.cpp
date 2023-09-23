//problem: https://www.acmicpc.net/problem/10250
//date: 20230922

#include <iostream>
using namespace std;

void room_check(int h, int w, int n){
    int floor=1;
    int room=1;
    n--;
    floor+=n%h;
    room+=n/h;
    if(room<10){
        printf("%d0%d\n",floor,room);
    }
    else{
        printf("%d%d\n",floor,room);
    }
}

int main() {
    int t,h,w,n; //t: testcase h: height w: room n: nth guest
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>h>>w>>n;
        room_check(h,w,n);
    }
   return 0;
}

/*(아이디어만 캐치하면 구현은 쉬움)
사고 과정: 오는 순서대로 배정할 방 번호를 하나씩 써봄 -> 1층부터 꼭대기 층까지 먼저 1호실 다 채운 후 2호실, 3호실, ... 이런 식의 패턴 -> 오는 순서를 층으로 분류할 수 있겠다
- 방 번호가 무조건 세자리 이상이므로 n호실(n<10)일 때 0을 끼워서 출력하도록 설정*/