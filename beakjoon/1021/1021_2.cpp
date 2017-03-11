#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>
#include <cmath>

using namespace std;
int n, m;
vector<int> popNum;
deque<int> dq;
int main(){

    scanf("%d %d", &n, &m);
    // printf("%d %d\n", n, m);
    for(int i = 0; i < m; i++){
        int inp; scanf("%d", &inp);
        popNum.push_back(inp);
    }

    for(int i = 1; i <= n; i++){
        dq.push_back(i);
        // printf("%d\n", dq.front());
    }
    int ret = 0;
    int nowPosition = 0;
    for(int i = 0; i < popNum.size();i++){
        int nowPopNum = popNum[i];
        int size = dq.size();

        for(int j = 0; j < size; j++){
            if(nowPopNum == dq[j]){
                ret += min(abs(nowPosition - j),  nowPosition + size - j);
                nowPosition = j;
                dq.erase(dq.begin() + j);
                break;
            }
        }
    }
    printf("%d\n", ret);
    return 0;
}