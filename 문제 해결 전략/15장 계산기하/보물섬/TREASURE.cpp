#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
using namespace std;
const double PI = 2.0 * acos(0.0);
const double EPSILON = 1e-9;
class vector2 {

public:

	double x, y;

	explicit vector2(double x_ = 0, double y_ = 0) : x(x_), y(y_){}

	bool operator == (const vector2& rhs) const {
		return x == rhs.x && y == rhs.y;
	}

	bool operator < (const vector2& rhs) const {
		return x != rhs.x ? x <rhs.x : y < rhs.y;
	}

	vector2 operator + (const vector2& rhs) const {
		return vector2(x + rhs.x, y + rhs.y);
	}

	vector2 operator - (const vector2 rhs) const {
		return vector2(x - rhs.x, y - rhs.y);
	}

	vector2 operator * (double rhs) const {
		return vector2(x * rhs, y * rhs);
	}

	double norm() const { return hypot(x, y); }

	vector2 normalize() const {
		return vector2(x / norm(), y / norm());
	}

	double polar() const { return fmod(atan2(y, x) + 2 * PI, 2 * PI); }

	double dot(const vector2& rhs) const {
		return x * rhs.x + y * rhs.y;
	}

	double cross(const vector2& rhs) const{
		return x * rhs.y - rhs.x *y;
	}

	vector2 project(const vector2& rhs) const{
		vector2 r = rhs.normalize();
		return r * r.dot(*this);
	}
};

double ccw(vector2 a, vector2 b){
	return a.cross(b);
}

double ccw(vector2 p, vector2 a, vector2 b){
	return ccw(a - p, b - p);
}

bool lineIntersection(vector2 a, vector2 b, vector2 c, vector2 d, vector2& x){
	double det = (b - a).cross(d - c);

	if(fabs(det) < EPSILON) return false;

	x = a + (b - a) *((c - a).cross(d - c) / det);
	return true;
}

bool parallelSegments(vector2 a, vector2 b, vector2 c, vector2 d, vector2& p){

	if(b < a) swap(a, b);
	if(d < c) swap(c, d);

	if(ccw(a, b, c) != 0 || b < c || d < a) return false;

	if(a < c) p = c;
	else p = a;
	return true;
}

bool inBoundingRectangle(vector2 p, vector2 a, vector2 b){
	if(b < a) swap(a, b);

	return p == a || p == b || (a < p && p < b);
}

bool segmentIntersection(vector2 a, vector2 b, vector2 c, vector2 d, vector2& p){
	if(lineIntersection(a, b, c, d, p))
		return parallelSegments(a, b, c, d, p);

	return inBoundingRectangle(p, a, b) && inBoundingRectangle(p, c, d);
}

bool segmentIntersects(vector2 a, vector2 b, vector2 c, vector2 d){
	double ab = ccw(a, b, c) * ccw(a, b, d);
	double cd = ccw(c, d, a) * ccw(c, d, b);

	if(ab == 0 && cd == 0) {
		if(b < a) swap(a, b);
		if(d < c) swap(c, d);
		return !(b < c || d < a);
	}
	return ab <= 0 && cd <= 0;
}

vector2 perpendicularFoot(vector2 p, vector2 a, vector2 b){
	return a +(p - a).project(b - a);
}

double pointToLine(vector2 p, vector2 a, vector2 b){
	return (p - perpendicularFoot(p, a, b)).norm();
}


template <class T>
void swap(T a, T b){
	T temp = a;
	a = b;
	b = temp;
	return;
}

double area(const vector<vector2>& p){

	double ret = 0;
	for(int i = 0; i < p.size(); i++){
		int j = (i + 1) % p.size();
		ret += p[i].x * p[j].y - p[j].x * p[i].y;
	}
	return fabs(ret)/2.0;
}

bool isInside(vector2 q, const vector<vector2>& p){
	int crosses = 0;
	for(int i = 0 ; i <p.size(); i++){
		int j = (i + 1) % p.size();
		if((p[i].y > q.y) != (p[j].y > q.y)){

			double atX = (p[j].x - p[i].x ) * (q.y - p[i].y) / (p[j].y - p[i].y) + p[i].x;

			if(q.x < atX)
				crosses++;
		}
	}
	return crosses % 2 > 0;
}




int N;
vector<vector2> island;
vector<vector2> rectangle;
bool isIn[101];
int main(){
	freopen("input.txt","r",stdin);
	setbuf(stdout, NULL);

	int TC;	cin>>TC;

	for(int test_case = 0 ; test_case < TC; test_case++){
		int x1, y1, x2, y2;
		cin>>x1>>y1>>x2>>y2>>N;
		rectangle.push_back(vector2(x1,y1));
		rectangle.push_back(vector2(x2,y1));
		rectangle.push_back(vector2(x2,y2));
		rectangle.push_back(vector2(x1,y2));
		int x_buf, y_buf;
		for(int i = 0; i < N; i++){
			cin>>x_buf>>y_buf;
			island.push_back(vector2(x_buf, y_buf));
		}
		// int num = 0;
		for(int i = 0; i < N; i++){
			isIn[i] = isInside(island[i], rectangle);
		}
		vector<vector2> get;
		for(int i = 0; i < N; i++){


			int j = (i + 1) % N;

			if(!isIn[i] && !isIn[j]){
				
			}
			else if(!isIn[i] && isIn[j]){
				for(int k = 0; k < 4; k++){
					int l = (k + 1) % 4;
					vector2 p;
					if(segmentIntersection(rectangle[k], rectangle[l], island[i], island[j], p)){
						get.push_back(p);
					}
				}

			}
			else if(isIn[i] && !isIn[j]){
				get.push_back(island[i]);
				for(int k = 0; k < 4; k++){
					int l = (k + 1) % 4;
					vector2 p;
					if(segmentIntersection(rectangle[k], rectangle[l], island[i], island[j], p)){
						get.push_back(p);
					}
				}
			}
			else{
				get.push_back(island[i]);
			}
		



		}

	}



	return 0;
}