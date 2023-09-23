//problem: https://www.acmicpc.net/problem/2869
//date: 20230920

#include <iostream>

using namespace std;

int main() {
    int a,b,v;
    cin>>a>>b>>v;
    int days=1;
    int check=(v-a)/(a-b);
    if(v-a==0){
        printf("%d",days);
        return 0; 
    }
    else if((v-a)<(a-b)){
        days++;
    }
    else if((v-a)%(a-b)!=0){
        days++;
    }
    days+=check;
    printf("%d",days);
    return 0;
}

/*
<사고 과정>
- 시간이 0.25초로 굉장히 짧음 -> 처음에 시간 조건, input 범위 안 보고 일반적인 접근(+a,-b 반복하다가 높이가 v 되면 break하는 식)으로 풀었다가 시간 초과가 떴음. 숫자 범위가 10^9이기 때문에 for문으로 접근하면 주어진 시간을 초과하게 됨.
- 결론: 주어진 시간 내에 풀려면 반복문을  안 쓰고 풀어야 함.
- 방법을 고민하다가 결국 달팽이가 +a일 때만 막대 정상에 올라갈 수 있다는 생각이 들었음 -> (v-a)/(a-b)를 조사하면 되겠다는 생각
- 주어진 두 개의 예제에서 단순히 (v-a)/(a-b)를 1에 더하면 틀린 값이 나옴을 확인 -> 대소 비교에 따라 달라진다는 조건 추가
- 반례를 찾다가 (v-a)/(a-b)의 나머지 존재 유무로 값이 달라짐을 확인 -> 나머지 조건 추가
*/