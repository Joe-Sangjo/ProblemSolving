#include <iostream>
#include <cmath>
#include <vector>
#include <cstdio>

using namespace std;
int n, m;
class point{
public:
	double y, x;
	point(double yy, double xx){
		y = yy;
		x = xx;
	}
};

vector<point> hull1, hull2;

vector<pair<point, point> >  upper, lower;
void decompose(const vector<point>& hull);
bool between(const point& a, const point& b, double x);
double at(const point& a, const point& b, double x);
double vertical(double x);
double solve();
double maxX(const vector<point>& hull);
double minX(const vector<point>& hull);
int main(){
	freopen("input.txt","r",stdin);
	setbuf(stdout, NULL);

	int TC;	cin>>TC;

	for(int test_case = 0; test_case < TC; test_case++){
		cin>>n>>m;



		hull1.clear(); hull2.clear();
		upper.clear(); lower.clear();

		double buf1, buf2;
		for(int i = 0; i < n; i++){
			cin>>buf1>>buf2;
			point p(buf2, buf1);
			hull1.push_back(p);
		}
		for(int i = 0; i < m ;i++){
			cin>>buf1>>buf2;
			point p(buf2, buf1);
			hull2.push_back(p);
		}
		cout<<solve()<<endl;

	}



	return 0;
}

void decompose(const vector<point>& hull){
	int n = hull.size();

	for(int i = 0; i < n; i++){
		if(hull[i].x < hull[(i + 1)%n].x)
			lower.push_back(make_pair(hull[i], hull[(i+1)%n]));
		else if(hull[i].x > hull[(i+1)%n].x)
			upper.push_back(make_pair(hull[i], hull[(i+1)%n]));
	}
}

bool between(const point& a, const point& b, double x){
	return (a.x <= x && x <= b.x) || (b.x <= x && x <= a.x);
}
double at(const point& a, const point& b, double x){
	double dy = b.y - a.y, dx = b.x - a.x;
	return a.y + dy * (x - a.x) / dx;
}
double vertical(double x){
	double minUp = 1e20, maxLow = -1e20;

	for(int i = 0; i < upper.size(); i++){
		if(between(upper[i].first, upper[i].second, x))
			minUp = min(minUp, at(upper[i].first, upper[i].second, x));
	}
	for(int i = 0; i < upper.size(); i++){
		if(between(lower[i].first, lower[i].second, x))
			maxLow = max(maxLow, at(lower[i].first, lower[i].second, x));
	}
	return minUp - maxLow;
}

double solve() {

	double lo = max(minX(hull1), minX(hull2));
	double hi = min(maxX(hull1), maxX(hull2));

	if(hi < lo) return 0;

	for(int iter = 0; iter < 100; iter++){
		double aab = (lo*2 + hi) / 3.0;
		double abb = (lo + hi*2) / 3.0;
		if(vertical(aab) < vertical(abb))
			lo = aab;
		else
			hi = abb;
	}

	return max(0.0 , vertical(hi));
}

double minX(const vector<point>& hull){
	double mx = 987654321.0;
	for(int i = 0; i < hull.size(); i++){
		mx = min(mx, hull[i].x);
	}
	return mx;
}
double maxX(const vector<point>& hull){
	double mx = -1.0;
	for(int i = 0; i < hull.size(); i++){
		mx = max(mx, hull[i].x);
	}
	return mx;
}