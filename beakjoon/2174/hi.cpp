#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int n,m,a,b;

struct state {
    int y,x,dir;
    state() {}
    state(int x, int y, int dir) : x(x), y(y), dir(dir) {}
};

vector<state> initpos;
int map[105][105];

bool ok(int x, int y) {
    return x>=0 && x<a && y<b && y>=0;
}

int ddxx[4] = {0,1,0,-1}, ddyy[4] = {1,0,-1,0};

int main () {
    freopen("input.txt","r",stdin);
    vector<int> ret(2,0);
    memset(map,-1,sizeof(map));
    scanf("%d%d%d%d",&a,&b,&n,&m);
    for(int i=0;i<n;i++) {
        int q,w;
        char e;
        int dirbuf = 0;
        scanf("%d %d %c",&q,&w,&e);
        q--;    w--;
        if(e == 'N')    dirbuf = 0;
        if(e == 'E')    dirbuf = 1;
        if(e == 'S')    dirbuf = 2;
        if(e == 'W')    dirbuf = 3;    
        initpos.push_back(state(q,w,dirbuf));
        map[q][w]=i;
    }        

    bool F = false, W = false;
    for(int i=0;i<m;i++) {
        // printf("\n");
        // for(int i=0;i<a;i++) {
        //     for(int j=0;j<b;j++)
        //         printf("%d ",map[i][j]);
        //     printf("\n");
        // }
        // printf("ret[0] %d ret[1] %d\n",ret[0], ret[1]);

        int robot, reps;
        char op;
        scanf("%d %c %d",&robot,&op,&reps);

        if(F || W)
            continue;
        robot--;
        if(op == 'L') {
            for(int j=0;j<reps;j++)
                initpos[robot].dir = (initpos[robot].dir-1+4)%4;
        }
        if(op == 'R') {
            for(int j=0;j<reps;j++) 
                initpos[robot].dir = (initpos[robot].dir+1+4)%4;
        }
        if(op == 'F') {
            for(int j=1;j<=reps;j++) {
                int nexty = initpos[robot].y +ddyy[initpos[robot].dir] * j, nextx = initpos[robot].x + ddxx[initpos[robot].dir] * j;
                if(!ok(nextx,nexty)) {
                    ret[0]=robot+1;
                    // printf("wall...\n");
                    W = true;
                    break;
                }
                if(F || W)
                    break;
                if(map[nextx][nexty] != -1) {
                    ret[0] = robot+1;
                    ret[1] = map[nextx][nexty]+1;
                    // printf("crash %d\n",map[nextx][nexty]);
                    // printf("ret[0] %d ret[1] %d\n",ret[0],ret[1]);
                    F = true;
                    break;
                }
                if(F || W)
                    break;
            }
            if(F || W)
                continue;
            map[initpos[robot].x][initpos[robot].y] = -1;
            map[initpos[robot].x+ddxx[initpos[robot].dir]*reps][initpos[robot].y+ddyy[initpos[robot].dir]*reps] = robot;
            // printf("Move to %d %d\n",initpos[robot].x+ddxx[initpos[robot].dir]*reps,initpos[robot].y+ddyy[initpos[robot].dir]*reps);
            initpos[robot].x += ddxx[initpos[robot].dir]*reps;
            initpos[robot].y += ddyy[initpos[robot].dir]*reps;
        }
    }
    if(W) {
        printf("Robot %d crashes into the wall\n",ret[0]);
        return 0;
    }
    if(F) {
        printf("Robot %d crashes into robot %d\n",ret[0],ret[1]);
        return 0;
    }
    printf("OK\n");    
}