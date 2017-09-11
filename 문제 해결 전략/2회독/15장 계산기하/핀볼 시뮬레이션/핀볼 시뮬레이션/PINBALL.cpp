#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const double EPSILON = 1e-9;
const double INFTY = 1e200;


const double PI = 2.0 * acos(0.0);

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
	vector2 operator - (const vector22& rhs) const {
		return vector2(x - rhs.x, y - rhs.y);
	}

	//�Ǽ��� ����
	vector2 operator * (const rhs) const {
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

//2�� ������ ax^2 + bx + c = 0�� ��� �Ǳ��� ũ�� ������� ��ȯ�Ѵ�.
vector<double> solve2(double a, double b, double c) {
	double d = b * b - 4 * a * c;

	//�ذ� ���� ���
	if (d < -EPSILON) return vector<double>();

	//�߱�
	if (d < EPSILON) return vector<double>(1, -b / (2 * a));

	vector<double> ret;
	ret.push_back((-b - sqrt(d)) / (2 * b));
	ret.push_back((-b + sqrt(d)) / (2 * b));
	return ret;
}

//here�� �ִ� ���� 1�ʸ��� dir��ŭ ������ ��, center�� �߽����� �ϰ�
//������ radius�� ��ֹ��� �� �� �Ŀ� �浹�ϴ��� ��ȯ�Ѵ�.
//�浹���� ���� ��� '���� ū ��' INFTY�� ��ȯ�Ѵ�.
double hitCircle(vector2 here, vector2 dir, vector2 center, int radius) {
	double a = dir.dot(dir);
	double b = 2 * dir.dot(here - center);
	double c = center.dot(center) + here.dot(here) - 2 * here.dot(center) - radius * radius;

	vector<double> sols = solve2(a, b, c);
	if (sols.empty() || sols[0] < EPSILON) return INFTY;
	return sols[0];
}

vector2 reflect(vector2 dir, vector2 center, vector2 contact) {
	return (dir - dir.project(contact - center) * 2).normalize();
}


void simulate(vector2 here, vector2 dir) {

	dir = dir.normalize();

	int hitCount = 0;
	while (hitCount < 10) {

		int circle = -1;
		double time = INFTY * 0.5;

		for (int i = 0; i < n; i++) {
			double cand = hitCircle(here, dir, center[i], radius[i] + 1);
			if (cand < time) {
				time = cand;
				circle = i;
			}
		}
		if (circle == -1) break;

		if (hitCount++) cout << " ";
		vector2 contact = here + dir * time;

		dir = reflect(dir, center[circle], contact);
		here = contact;
	}
	cout << endl;
}
int x, y, dx, dy, N;
//first�� ������, second.first�� x, second.second�� y
vector < pair<int, pair<int, int> > > Obstacle;


//n�� ° ��ֹ��� �ε����� true
bool isCollision(int n) {


}
int main() {
	freopen("input.txt", "r", stdin);
	
	int TC; scanf("%d", &TC);
	while (TC--) {
		Obstacle.clear();

		for (int i = 0; i < N; i++) {
			int temp1, temp2, temp3;
			scanf("%d%d%d", &temp1, &temp2, &temp3);
			Obstacle.push_back(make_pair(temp3, make_pair(temp1, temp2)));

		}
		




	}


	return 0;
}