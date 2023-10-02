//problem: https://www.acmicpc.net/problem/17286
//date: 20230929

#include <iostream>
#include <cmath>
using namespace std;

typedef struct point {
    int x;
    int y;
};

float find_dist(point a, point b) {
    float x = (float)(a.x - b.x);
    float y =(float)(a.y - b.y);
    return sqrt(x * x + y * y);
}

int main() {
    point yumi;
    cin >> yumi.x >> yumi.y;
    point people[3];
    float dist[6];

    for (int i = 0; i < 3; i++) {
        cin >> people[i].x>> people[i].y;
    }
    //dist:0->1->2
    dist[0] = find_dist(yumi, people[0]) + find_dist(people[0], people[1]) + find_dist(people[1], people[2]);
    //dist:0->2->1
    dist[1] = find_dist(yumi, people[0]) + find_dist(people[0], people[2]) + find_dist(people[2], people[1]);
    //dist:1->0->2
    dist[2] = find_dist(yumi, people[1]) + find_dist(people[1], people[0]) + find_dist(people[0], people[2]);
    //dist:1->2->0
    dist[3] = find_dist(yumi, people[1]) + find_dist(people[1], people[2]) + find_dist(people[2], people[0]);
    //dist:2->0->1
    dist[4] = find_dist(yumi, people[2]) + find_dist(people[2], people[0]) + find_dist(people[0], people[1]);
    //dist:2->1->0
    dist[5] = find_dist(yumi, people[2]) + find_dist(people[2], people[1]) + find_dist(people[1], people[0]);
    float min = dist[0];
    for (int i = 1; i <= 5; i++) {
        if (min > dist[i]) {
            min = dist[i];
        }
    }
    printf("%d",(int)floor(min));
    return 0;
}

/* 시간 넉넉해서 브루트포스 생각. 처음에 반복문 안에서 거리를 계산하려고 했는데 
생각해보니 케이스가 3*2*1=6가지밖에 안 되길래 그냥 하나하나 케이스 나눠 계산하였음. 
케이스 적으면 그냥 구현해도 될 듯*/