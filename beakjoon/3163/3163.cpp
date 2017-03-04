#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <cmath>
#include <deque>
#define INF 0x3f3f3f3f
const double error = 0.00000001;
using namespace std;
int n, k;
double l;

//first는 위치, second.first는 방향, second.second는 번호
deque<pair<double, pair<int, int> > > ants;

int main(){
	freopen("input.txt","r",stdin);
	int TC;scanf("%d", &TC);
	while(TC--){
		//떨어질 아이들을 차례로 담는다. second.second가 담김
		stack<int> st;

		cin>>n>>l>>k;
		for(int i = 0; i < n; i++){
			double a;int b;
			scanf("%lf%d", &a,&b);
			ants.push_back(make_pair(a, make_pair((b > 0 ? 1 : -1), b)));
		}
		int ret; bool finish = true;
		while(ants.size() && finish){

			double left = INF;
			//첫 개미가 왼쪽을 향할 경우 떨어질 예정 시간을 저장
			if(ants[0].second.first < 0){
				left = ants[0].first;
			}
			double right = INF;
			//마지막 개미가 오른쪽을 향할 경우 떨어질 예정 시간을 저장
			if(ants[ants.size() - 1].second.first > 0){
				right = l - ants[ants.size() - 1].first;
			}

			//충돌할 예정 인 것중 가장 빠른 시간과 만나는 것의 인덱스를 저장
			double smallestCollision = INF; int colP;
			for(int i = 0; i < ants.size() - 1; i++){
				//충돌이 일어 나는 경우
				if(ants[i].second.first > 0 && ants[i + 1].second.first < 0){
					double diff = (ants[i + 1].first - ants[i].first) / 2;
					if(smallestCollision > diff){
						smallestCollision = diff;
						colP = i;
					}
				}
			}

			double smallestTime = min(left, right);
			//떨어지는 것 보다 충돌이 먼저 일어나는 경우
			if(smallestCollision < smallestTime){
				//지금 방향대로 이동을 해버리고
				for(int i = 0; i < ants.size(); i++){
					ants[i].first += ants[i].second.first * smallestCollision;
				}
				//충돌하는 것의 방향을 바꿔줌.
				ants[colP].second.first = -1, ants[colP + 1].second.first = 1;
			}
			//떨어지는 것이 먼저 발생한다 -> 떨어지는 것을 stack에 담는다.
			else{
				int endIndex = ants.size() - 1;
				//이동
				for(int i = 0; i < ants.size(); i++){
					ants[i].first += smallestTime * ants[i].second.first; 
				}
				//둘다 떨어 질 것으로 예상. 소수 계산이기 때문에 오차를 감안
				if(ants[0].first < error && fabs(l - ants[endIndex].first) < error){
					//번호의 절대 값을 비교
					//더 작은 애가 먼저 떨어짐
					if(abs(ants[0].second.second) < abs(ants[endIndex].second.second)){
						st.push(ants[0].second.second);
						st.push(ants[endIndex].second.second);
					}
					else{
						st.push(ants[endIndex].second.second);
						st.push(ants[0].second.second);
					}
					//살아 남은 개미 배열에서 삭제
					ants.pop_front(); ants.pop_back();
				}
				//왼쪽꺼가 먼저 떨어지는 경우
				else if(ants[0].first < error){

					st.push(ants[0].second.second);
					ants.pop_front();
				}
				//오른쪽 꺼가 먼저 떨어지는 경우
				else if(fabs(l -ants[endIndex].first) < error){
					st.push(ants[endIndex].second.second);
					ants.pop_back();
				}
			}
			//만약 k개가 넘게 떨어지면 그 것을 ret에 기록하고 전체 시뮬레이팅 중지
			while(st.size() >= k){
				ret = st.top(); 
				st.pop();
				finish = false;
			}
		}
		cout<<ret<<endl;
	}	

	return 0;
}