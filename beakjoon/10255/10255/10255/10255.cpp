#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;


const double PI = 2.0 * acos(0.0);
const double EPSILON = 1e-7;
const double INFTY = 1e200;

struct vector2 {

	double x, y;

	vector2(double x_ = 0, double y_ = 0) : x(x_), y (y_){}

	//�� ������ ��
	bool operator == (const vector2& rhs) const {
		return x == rhs.x && y == rhs.y;
	}
	bool operator < (const vector2& rhs) const {
		return x != rhs.x ? x < rhs.x : y < rhs.y;
	}

	vector2 operator + (const vector2& rhs) const {
		return vector2(x + rhs.x, rhs.y + y);
	}
	vector2 operator - (const vector2& rhs) const {
		return vector2(x - rhs.x, y - rhs.y);
	}
	vector2 operator * (double rhs) const {
		return vector2(x * rhs, y * rhs);
	}

	double norm() const {
		return hypot(x, y);
	}

	vector2 normalize() const {
		return vector2(x / norm(), y / norm());
	}

	double polar() const {
		return fmod(atan2(y,x) + 2 * PI, 2 * PI);
	}

	double dot(const vector2& rhs) const {
		return x * rhs.x + y * rhs.y;
	}
	double cross(const vector2& rhs) const {
		return x * rhs.y - y * rhs.x;
	}

	vector2 project(const vector2& rhs) const {
		vector2 r = rhs.normalize();
		return r * r.dot(*this);
	}

};


double ccw(vector2 a, vector2 b) {
	return a.cross(b);
}
double ccw(vector2 p, vector2 a, vector2 b) {
	return ccw(a - p, b - p);
}


//(a, b)�� �����ϴ� ���� (c, d)�� �����ϴ� ���� ������ x�� ��ȯ�Ѵ�.
//�� ���� �����̸�(��ġ�� ��츦 ����) ������, �ƴϸ� ���� ��ȯ�Ѵ�.
bool lineIntersection(vector2 a, vector2 b, vector2 c, vector2 d, vector2& x) {
	
	double det = (b - a).cross(d - c);
	if (fabs(det) < EPSILON) return false;
	x = a + (b - a) * ((c - a).cross(d - c) / det);
	return true;
}

//(a, b)�� (c, d)�� ������ �� ������ �� �̵��� �� ������ ��ġ���� Ȯ���Ѵ�.
bool parallelSegments(vector2 a, vector2 b, vector2 c, vector2 d, vector2& p) {
	if (b < a) swap(a, b);
	if (d < c) swap(c, d);

	//�� ���� ���� ���ų� �� ������ ��ġ�� �ʴ� ��츦 �켱 �ɷ�����.
	if (ccw(a, b, c) != 0 || b < c || d < a) return false;

	//�� ������ Ȯ���� ��ģ��. �������� �ϳ� ã��.
	if (a < c) p = c; else p = a;
	return true;
}


//p�� (a, b)�� ���θ鼭 �� ���� x, y�࿡ ������ �ּ� �簢�� ���ο� �ִ��� Ȯ���Ѵ�.
//a, b ,p�� ������ �� �ִٰ� �����Ѵ�.
bool inBoudingRectangle(vector2 p, vector2 a, vector2 b) {
	if (b < a) swap(a, b);
	return p == a || p == b || (a < p && p < b);
}


//(a, b) ���а� (c, d)������ ������ p�� ��ȯ�Ѵ�.
//������ ���� ���� ��� �ƹ� ���̳� ��ȯ�Ѵ�.
//�� ������ �������� ���� ��� false�� ��ȯ�Ѵ�.
bool segmentIntersection(vector2 a, vector2 b, vector2 c, vector2 d, vector2& p) {

	//�� ������ ������ ��츦 �켱 ���ܷ� ó���Ѵ�.
	if (!lineIntersection(a, b, c, d, p))
		return parallelSegments(a, b, c, d, p);

	return inBoudingRectangle(p, a, b) && inBoudingRectangle(p, c, d);
}


//�� ������ ���� �����ϴ��� ���θ� ��ȯ�Ѵ�.
bool segmentIntersects(vector2 a, vector2 b, vector2 c, vector2 d) {
	double ab = ccw(a, b, c) * ccw(a, b, d);
	double cd = ccw(c, d, a) * ccw(c, d, b);

	if (ab == 0 && cd == 0) {
		if (b < a) swap(a, b);
		if (d < c) swap(c, d);
		return !(b < c || d < a);
	}
	return ab <= 0 && cd <= 0;
}

//�� p���� (a, b) ������ ���� ������ ���� ���Ѵ�.
vector2 perpendicularFoot(vector2 p, vector2 a, vector2 b) {
	return a + (p - a).project(b - a);
}

//�� p�� (a, b) ���� ������ �Ÿ��� ���Ѵ�.
double pointToLine(vector2 p, vector2 a, vector2 b) {
	return (p - perpendicularFoot(p, a, b)).norm();
}

double area(const vector<vector2>&p) {
	double ret = 0;
	for (int i = 0; i < p.size(); i++) {
		int j = (i + 1) % p.size();
		ret += p[i].x * p[j].y - p[j].x * p[i].y;
	}
	return fabs(ret) / 2.0;
}

bool isInside(vector2 q, const vector<vector2>& p) {
	int crosses = 0;
	for (int i = 0; i < p.size(); i++) {
		int j = (i + 1) % p.size();

		if ((p[i].y > q.y) != (p[j].y > q.y)) {

			double atX = (p[j].x - p[i].x) * (q.y - p[i].y) / (p[j].y - p[i].y) + p[i].x;
			if (q.x < atX)
				crosses++;
		}
	}
	return crosses % 2 > 0;
}


int main() {
	double xmin, ymin, xmax, ymax;
	double x1, y1, x2, y2;

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int TC; scanf("%d", &TC);
	//TC = 1;
	while (TC--) {
		scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &xmin, &ymin, &xmax, &ymax, &x1, &y1, &x2, &y2);


		//printf("%d %d %d %d \n", x1, y1, x2, y2);
		vector<vector2> Rectangle;
		Rectangle.push_back(vector2(xmin, ymin));
		Rectangle.push_back(vector2(xmax, ymin));
		Rectangle.push_back(vector2(xmax, ymax));
		Rectangle.push_back(vector2(xmin, ymax));


		vector2 segment1(x1, y1), segment2(x2, y2);
		vector<vector2> meetPoint;

		bool check = true;
		for (int i = 0; i < Rectangle.size(); i++) {
			int j = (i + 1) % Rectangle.size();
			vector2 temp(-1000000000.0, -1000000000.0);


			//�����ϰ� ������ ���
			if (!lineIntersection(Rectangle[i], Rectangle[j], segment1, segment2, temp) && (parallelSegments(Rectangle[i], Rectangle[j], segment1, segment2, temp))) {
				check = false;
				break;
			}

			//�������� �ʰ� ������ ���
			if (segmentIntersection(Rectangle[i], Rectangle[j], segment1, segment2, temp)) {
				meetPoint.push_back(temp);
			}
		}

		if (!check) {
			cout << 4 << endl;
			continue;
		}

		int duplicate = 0;
		if (meetPoint.size() == 0) {
			cout << 0 << endl;
			continue;
		}
		for (int i = 0; i < meetPoint.size(); i++) {
			for (int j = 0; j < 4; j++) {
				if (meetPoint[i] == Rectangle[j]) {
					duplicate++;
				}
			}
		}
		cout << meetPoint.size() - (duplicate / 2) << endl;
	}

	return 0;
}

