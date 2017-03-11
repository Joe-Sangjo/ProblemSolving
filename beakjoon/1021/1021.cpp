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
    freopen("input.txt","r",stdin);

    cin>>n>>m;
    for(int i = 1; i <= n;i++){
        dq.push_back(i);
        // cout<<dq.back()<<" ";
    }

    for(int i = 0; i < m; i++){
        int temp; cin>>temp;
        popNum.push_back(temp);
    }
    int ret = 0;
    for(int i = 0; i < m; i++){
        int nowPopNum = popNum[i];
        int movingNum = 0;
        int size = dq.size();
        while(nowPopNum != dq.front()){
            movingNum++;
            int f = dq.front();
            dq.pop_front();
            dq.push_back(f);            
        }
        dq.pop_front();
        ret += min(movingNum, size - movingNum);
    }
    cout<<ret<<endl;
    return 0;
}