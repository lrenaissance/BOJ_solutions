//problem: https://www.acmicpc.net/problem/1065
//date: 20230725

#include <iostream>

using namespace std;

int is_hansu(int n){
    int hund,ten,one;
    one=n%10;
    hund=n/100;
    ten=n%100/10; //ten!=n/10
    if((hund-ten)==(ten-one)){
        return 1; //the digits form an arithmetic progression
    }
    return 0;
}

int main(void) {
    int n,a,total=99;
    cin>>n;
    if(n<100){
        cout<<n;
        return 0;
    }
    else if(n>=100&&n<=110){
        cout<<99;
        return 0;
    }
    else if(n>110){
        for(int i=111;i<=n;i++){
            total+=is_hansu(i);
        }
        cout<<total;
    }
    return 0;
}