#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

const double PI = 2.0 * acos(0.0);

double x, y, dx, dy;
int N;
int x_[51], y_[51], r_[51];
bool isIn(int num);
void reflect(int num);
int main(){
	freopen("input.txt","r",stdin);
	setbuf(stdout, NULL);

	int TC; cin>>TC;

	for(int test_case = 0; test_case < TC; test_case++){
		cin>>x>>y>>dx>>dy>>N;

		for(int i = 0; i < N; i++){
			cin>>x_[i]>>y_[i]>>r_[i];
			// cout<<x_[i]<<" "<<y_[i]<<" "<<r_[i]<<endl;
		}

		double time = 0.0;
		double interval = 0.01;
		vector<int> QQang;
		while(1){
			// cout<<x<<" "<<y<<endl;
			x += dx * interval;
			y += dy * interval;

			if(x <= -100 || y <= -100 || x >= 200 || y >= 200) break;

			for(int i = 0; i < N; i++){
				if(isIn(i)){
					// cout<<"!!!!!!!!!!!!!"<<endl;

					if(QQang.size() >=1 && QQang[QQang.size()-1] == i){
						continue;
					}
					QQang.push_back(i);
					reflect(i);
					// cout<<dx<<" "<<dy<<endl;
					x += dx * 40 * interval;
					y += dx * 40 * interval;
					break;
				}
			}

			if(QQang.size() >= 100)	break;

			time += interval;
		}
		for(int i = 0; i < QQang.size(); i++){
			cout<<QQang[i]<<" ";
		}
		cout<<endl;

	}

	return 0;
}

bool isIn(int num){
	return (x - x_[num])*(x - x_[num]) + (y - y_[num]) * (y - y_[num]) <= (r_[num] + 1)*(r_[num] + 1);
}

void reflect(int num){
	double theta1 = fmod(atan2( y_[num] - y, x_[num] - x) + 2* PI, 2 * PI);
	double theta2 = fmod(atan2(dy, dx) + 2 * PI, 2 * PI);

	double angle = 2 * theta1 - theta2;
	double norm = hypot(1, tan(angle));
	// dx = 1;
	// dy = tan(2 * theta1 - theta2);
	if(angle >= 0 && angle < PI/2){
		dx = fabs(1/norm);
		dy = fabs(tan(angle)/norm);
	}
	else if(angle >= PI/2 && angle < PI){
		dx = -fabs(1/norm);
		dy = fabs(tan(angle)/norm);
	}
	else if(angle >= PI && angle < PI*3/2 ){
		dx = -fabs(1/norm);
		dy = -fabs(tan(angle)/norm);
	}
	else{
		dx = fabs(1/norm);
		dy = -fabs(tan(angle)/norm);
	}
	return;
}