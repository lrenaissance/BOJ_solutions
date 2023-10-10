//problem: https://www.acmicpc.net/problem/2075
//date: 20231010

#include <iostream>
#include <queue>

using namespace std;

int main() {
    //fast io
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    priority_queue<int,vector<int>,greater<int>> pq;//min heap(greater<int>), max heap(less<int>)
    int n,val;
    cin>>n;
    for(int i=0;i<n;i++){//첫번째 n개 그대로 입력
        cin>>val;
        pq.push(val);
    }
    for(int i=0;i<n*(n-1);i++){//min heap에 top(minimum)보다 큰 값일 경우 추가
        cin>>val;
        if(pq.top()<val){ //ex) heap: [5 7 9 11 13], val=15 -> push
            pq.pop(); // pq에 n개의 원소들만이 들어갈 수 있도록 pop 후 push
            pq.push(val);
        }
        //ex) heap: [5 7 9 11 13], val=3 -> continue
    }
    cout<<pq.top();
    return 0;
}

/*메모리 초과를 일으킨 첫번째 코드:
for(int i=0;i<n*n;i++){
  cin>>val;
  pq.push(val);
}
for(int i=1;i<=n-1;i++){
  pq.pop();
}
메모리 조건: 12MB, 1<=n<=1500
질문게시판에 의하면 priority_queue의 한 칸 메모리 용량이 20B로,
위 코드대로 모든 값을 priority queue에 넣으며 진행할 경우 20B*1500*1500=45MB가 필요해짐.
처음에 int=4B라 생각하고 4B*1500*1500<12MB라 괜찮을 줄 알았는데, 
priority queue의 메모리 사이즈는 다른 것 같음.

결론: 메모리 초과를 피하려면 priority_queue에 값을 선별적으로 입력해야함.
-> 필요한 것은 큰 값이니까 큰 값만 넣자! 큰 값의 기준은?
-> priority_queue에서 접근 가능한 값: top을 기준으로
-> top과 비교해서 heap에 넣으려면 min heap이어야함
*/