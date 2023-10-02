//problem: https://www.acmicpc.net/problem/9366
//date: 20230929

#include <iostream>
#include <algorithm>
using namespace std;

void check_triangle(int side[3]){
    if(side[2]>=side[0]+side[1]){
        printf("invalid!\n");
        return;
    }
    if(side[0]==side[1] && side[0]==side[2]&&side[1]==side[2]){
        printf("equilateral\n");
        return;
    }
    if(side[0]==side[1]||side[1]==side[2]||side[0]==side[2]){
        printf("isosceles\n");
        return;
    }
    if(side[0]!=side[1] && side[1]!=side[2]&&side[0]!=side[2]){
        printf("scalene\n");
        return;
    }
}

int main() {
    int t;
    int side[3];
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>side[0]>>side[1]>>side[2];
        sort(side,side+3);
        printf("Case #%d: ",i+1);
        check_triangle(side);
    }
    return 0;
}

/*시행착오: 매우 쉬운 문제이나 invalid 뒤에 개행문자 안 넣어서 여러번 틀림...*/