#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <cassert>

using namespace std;


const double PI = 2.0 * acos(0.0);
const double EPSILON = 2e-9;

//2���� ���͸� ǥ���Ѵ�.
struct vector2
{
	double x, y;

	//�����ڸ� explicit���� �����ϸ� vector2�� ���� ���� �߸���
	//�Ǽ��� ���� ���� �������ش�.
	explicit vector2(double x_ = 0, double y_ = 0) : x(x_), y(y_) {}

	//�� ������ ��
	bool operator == (const vector2& rhs) const {
		return x == rhs.x && y == rhs.y;
	}

	bool operator < (const vector2& rhs) const {
		return x != rhs.x ? x < rhs.x : y < rhs.y;
	}

	vector2 operator + (const vector2& rhs) const {
		return vector2(x + rhs.x, y + rhs.y);
	}
	vector2 operator - (const vector2& rhs) const {
		return vector2(x - rhs.x, y - rhs.y);
	}

	//�Ǽ��� ����
	vector2 operator * (const int rhs) const {
		return vector2(x * rhs, y * rhs);
	}

	//������ ���̸� ��ȯ�Ѵ�.
	double norm() const { return hypot(x, y); }

	//������ ���� ���� ����(unit vector)�� ��ȯ�Ѵ�.
	//�����Ϳ� ���� ȣ���� ��� ��ȯ ���� ���ǵ��� �ʴ´�
	vector2 normalize() const {
		return vector2(x / norm(), y / norm());

	}

	//x���� ���� �������κ��� �� ���ͱ��� �ݽð� �������� �� ����
	double polar() const {
		return fmod(atan2(y, x) + 2 * PI, 2 * PI);
	}

	//���� ������ ����
	double dot(const vector2& rhs) const {
		return x * rhs.x + y * rhs.y;
	}
	double cross(const vector2& rhs) const {
		return x * rhs.y - y * rhs.x;
	}
	//�� ���͸� rhs�� �翵�� ���
	vector2 project(const vector2& rhs) const {
		vector2 r = rhs.normalize();
		return r * r.dot(*this);
	}
};

double howMuchCloser(vector2 p, vector2 a, vector2 b) {
	return (b - p).norm() - (a - p).norm();
}


//�������� ���� b�� ���� a�� �ݽð� �����̸� ���, �ð� �����̸� ����,
//�����̸� 0�� ��ȯ�Ѵ�.
double ccw(vector2 a, vector2 b) {
	return a.cross(b);
}

//�� p�� �������� ���� b�� ���� a�� �ݽð� �����̸� ���, �ð�����̸� ����,
//�����̸� 0�� ��ȯ
double ccw(vector2 p, vector2 a, vector2 b) {
	return ccw(a - p, b - p);
}


//(a, b)�� �����ϴ� ���� (c, d)�� �����ϴ� ���� ������ x�� ��ȯ�Ѵ�.
//�� ���� �����̸� (��ġ�� ��츦 ����) ������, �ƴϸ� ���� ��ȯ�Ѵ�.

bool lineIntesection(vector2 a, vector2 b, vector2 c, vector2 d, vector2& x) {
	double det = (b - a).cross(d - c);

	if (fabs(det) < EPSILON) return false;
	x = a + (b - a) * ((c - a).cross(d - c) / det);
	return true;
}

//(a, b)�� (c, d)�� ������ �� ���� �� ��, �̵��� �� ������ ��ġ���� Ȯ���Ѵ�.
bool parallelSegments(vector2 a, vector2 b, vector2 c, vector2 d, vector2& p) {
	if (b < a) swap(a, b);
	if (d < c) swap(c, d);

	//�� ���� ���� ���ų� �� ������ ��ġ�� �ʴ� ��츦 �켱 �ɷ�����.
	if (ccw(a, b, c) != 0 || b < c || d < a) return false;

	//�� ������ Ȯ���� ��ģ��. �������� �ϳ� ã��
	if (a < c) p = c;
	else p = a;
	return true;

}

//p�� (a, b)�� ���θ鼭 �� ���� x, y�࿡ ������ �ּ� �簢�� ���ο� �ִ��� Ȯ���Ѵ�.
//a, b, p�� ������ �� �ִٰ� �����Ѵ�
bool inBoundingRectangle(vector2 p, vector2 a, vector2 b) {
	if (b < a) swap(a, b);
	return p == a || p == b || (a < p && p < b);
}

//(a, b) ���а� (c, d) ������ ������ p�� ��ȯ�Ѵ�.
//������ ���� ���� ��� �ƹ� ���̳� ��ȯ�Ѵ�.
//�� ������ �������� ���� ��� false�� ��ȯ�Ѵ�.
bool segmentIntersection(vector2 a, vector2 b, vector2 c, vector2 d, vector2& p) {

	//�� ������ ������ ��츦 �켱 ���ܷ� ó���Ѵ�.
	if (!lineIntesection(a, b, c, d, p))
		return parallelSegments(a, b, c, d, p);

	//p�� �� ���п� ���ԵǾ� �ִ� ��쿡�� ���� ��ȯ�Ѵ�.
	return inBoundingRectangle(p, a, b) && inBoundingRectangle(p, c, d);
}

//�� ������ ���� �����ϴ��� ���θ� ��ȯ�Ѵ�.
bool segmentIntersects(vector2 a, vector2 b, vector2 c, vector2 d) {
	double ab = ccw(a, b, c) * ccw(a, b, d);
	double cd = ccw(c, d, a) * ccw(c, d, b);

	//�� ������ �� ���� ���� �ְų� ������ ��ġ�� ���
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


int x1, x2, y1, y2, N;
typedef vector<vector2> polygon;



polygon cutPoly(const polygon& p, const vector2& a, const vector2& b) {

	int n = N;

	//�� ���� �� ��� ���� �ִ��� ���θ� �켱 Ȯ���Ѵ�.
	vector<bool> inside(n);

	for (int i = 0; i < n; i++)
		inside[i] = ccw(a, b, p[i]) >= 0;
	polygon ret;

	//�ٰ����� �� ���� ��ȸ�ϸ鼭 ��� �ٰ����� �� ���� �߰��Ѵ�.
	for (int i = 0; i < n; i++) {
		int j = (i + 1) % n;
		//����� ���� �ִ� �� p[i]�� �׻� ��� �ٰ����� ���Եȴ�.
		if (inside[i]) ret.push_back(p[i]);
		//�� p[i] - p[j]�� ������ �����ϸ� �������� ��� �ٰ����� ���Խ�Ų��.
		if (inside[i] != inside[j]) {
			vector2 cross;
			assert(lineIntesection(p[i], p[j], a, b, cross));
			ret.push_back(cross);
		}

	}
	return ret;

}


polygon intersection(const polygon& p, double x1, double y1, double x2, double y2) {

	vector2 a(x1, y1), b(x2, y1), c(x2, y2), d(x1, y2);
	polygon ret = cutPoly(p, a, b);

	ret = cutPoly(ret, b, c);
	ret = cutPoly(ret, c, d);
	ret = cutPoly(ret, d, a);
	return ret;


}
int main() {

	int TC; scanf("%d", &TC);

	while (TC--) {
		scanf("%d%d%d%d", &x1, &x2, &y1, &y2, &N);
		polygon poly;

		for (int i = 0; i < N; i++) {
			int temp1, temp2;
			scanf("%d%d", &temp1, &temp2);
			vector2 temp(temp1, temp2);
			poly.push_back(temp);

		}




	}


	return 0;
}