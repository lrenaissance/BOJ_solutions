//problem: https://www.acmicpc.net/problem/1358
//date: 20231004

#include <iostream>
#include <cmath>
using namespace std;
typedef struct{
    int x;
    int y;
}point;

int check_link(int w,int h,int x0,int y0,point input){
    if(input.x<=x0+w&&input.x>=x0&&input.y>=y0&&input.y<=y0+h){//직사각형
        return 1;
    }
    //떨어진 거리<=반지름이면 영역 내에 속함
    else if(input.x<=x0){ //왼쪽 반원
        if(sqrt((input.x-x0)*(input.x-x0)+(input.y-y0-h/2)*(input.y-y0-h/2))<=h/2){
            return 1;
        }
    }
    else if(input.x>=x0+w){ //오른쪽 반원
        if(sqrt((input.x-x0-w)*(input.x-x0-w)+(input.y-y0-h/2)*(input.y-y0-h/2))<=h/2){
            return 1;
        }
    }
    return 0;
}

int main() {
    //w가로h세로p선수 x0y0 기준점
    int w,h,x0,y0,p;
    int cnt=0;
    cin>>w>>h>>x0>>y0>>p;
    point *ath=new point[p];
    for(int i=0;i<p;i++){
        cin>>ath[i].x>>ath[i].y;
        cnt+=check_link(w,h,x0,y0,ath[i]);
    }
    printf("%d",cnt);
    return 0;
}
