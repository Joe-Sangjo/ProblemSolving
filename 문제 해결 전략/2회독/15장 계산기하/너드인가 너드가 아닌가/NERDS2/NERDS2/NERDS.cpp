#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const double PI = 2.0 * acos(0.0);
const double EPSILON = 1e-9;





class vector2 {

public:

	double x, y;

	explicit vector2(double x_ = 0, double y_ = 0) : x(x_), y(y_) {}

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

	double cross(const vector2& rhs) const {
		return x * rhs.y - rhs.x *y;
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

bool lineIntersection(vector2 a, vector2 b, vector2 c, vector2 d, vector2& x) {
	double det = (b - a).cross(d - c);

	if (fabs(det) < EPSILON) return false;

	x = a + (b - a) *((c - a).cross(d - c) / det);
	return true;
}


bool parallelSegments(vector2 a, vector2 b, vector2 c, vector2 d, vector2& p) {

	if (b < a) swap(a, b);
	if (d < c) swap(c, d);

	if (ccw(a, b, c) != 0 || b < c || d < a) return false;

	if (a < c) p = c;
	else p = a;
	return true;
}

bool inBoundingRectangle(vector2 p, vector2 a, vector2 b) {
	if (b < a) swap(a, b);

	return p == a || p == b || (a < p && p < b);
}

bool segmentIntersection(vector2 a, vector2 b, vector2 c, vector2 d, vector2& p) {
	if (lineIntersection(a, b, c, d, p))
		return parallelSegments(a, b, c, d, p);

	return inBoundingRectangle(p, a, b) && inBoundingRectangle(p, c, d);
}

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

vector2 perpendicularFoot(vector2 p, vector2 a, vector2 b) {
	return a + (p - a).project(b - a);
}

double pointToLine(vector2 p, vector2 a, vector2 b) {
	return (p - perpendicularFoot(p, a, b)).norm();
}


typedef vector<vector2> polygon;

//points�� �ִ� ������ ��� �����ϴ� �ּ��� ���� �ٰ����� ã�´�.
polygon giftWrap(const vector<vector2> points) {

	int n = points.size();
	polygon hull;

	//���� ���� �Ʒ� ���� ã�´�. �� ���� ������ �ݵ�� ���Եȴ�.
	vector2 pivot = *min_element(points.begin(), points.end());
	hull.push_back(pivot);

	while (true) {
		//ph���� �����ϴ� ���Ͱ� ���� ������ �� next�� ã�´�.
		//������ ���� ���� �� ������ ���� �� ���� �����Ѵ�.
		vector2 ph = hull.back(), next = points[0];
		for (int i = 1; i < n; i++) {
			double cross = ccw(ph, next, points[i]);
			double dist = (next - ph).norm() - (points[i] - ph).norm();
			if (cross > 0 || (cross == 0 && dist < 0))
				next = points[i];
		}

		//���������� ���ƿ����� �����Ѵ�.
		if (next == pivot) break;
		//next�� ���� ������ ���Խ�Ų��.
		hull.push_back(next);
	}
	return hull;

}

bool polygonIntersects(const polygon& p, const polygon& q) {
	int n = p.size(), m = q.size();

	//�켱 �� �ٰ����� �ٸ� �ٰ����� ���ԵǾ� �ִ� ��츦 Ȯ������
	if (isInside(p[0], q) || isInside(q[0], p)) return true;

	//�� ���� ���, �� �ٰ����� ���� ��ģ�ٸ� ��� �� ���� �ݵ�� �����Ѵ�.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (segmentIntersection(p[i], p[(i + 1) % n], q[j], q[(j + 1) % m]))
				return true;
		}
	}
}
int main() {



	return 0;
}