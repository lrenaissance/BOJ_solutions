//problem: https://www.acmicpc.net/problem/1436
//date: 20230924

#include <iostream>
#include <string>

using namespace std;

int check(int n){
    string s=to_string(n);
    for(int i=0;i<s.length()-2;i++){
        if(s.at(i)=='6'&&s.at(i+1)=='6'&&s.at(i+2)=='6'){
            return 1;
        }
    }
    return 0;
}

int main() {
    int cnt=1;
    int num=666;
    int n;
    cin>>n;
    if(n==1){
        printf("666");
        return 0;
    }
    while(cnt!=n){
        num++;
        if(check(num)==1){
            cnt++;
        }
    }
    printf("%d",num);
    return 0;
}

/*사고과정: 시간 제한 2초로 넉넉하고 숫자 범위고 작은 편. 666이 어떻게 하면 세 개 연속으로 나올 수 있는가? -> 직접 쓰면서 패턴 파악하려고 하였음 -> 반복문으로 이를 구현하려 했으나 굉장히 복잡하고 오류가 많음 -> 힌트 검색: "주어진 숫자에 666이 있는지 확인하면 된다"
- 지금까지 해당 조건의 숫자를 만드려고 해서 어려운 것이었음. 시간이 넉넉하므로 그냥 숫자를 하나씩 늘려가며 666이 있는지만 확인하면 됨
- 666 확인은 string으로 바꿔서 하나하나 확인하는 것이 편하겠다고 생각함 -> int를 string으로 바꿀 수 있는 함수? : <string>의 to_string(num) - num을 string 타입으로 바꿔줌
- 연속 3번 이상 6이 있기만 하면 1 반환 -> cnt++ */