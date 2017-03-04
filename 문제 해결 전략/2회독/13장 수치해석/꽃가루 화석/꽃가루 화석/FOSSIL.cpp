#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
struct point { double y, x;  };
vector<point> hull1, hull2;
vector<pair<point, point> > upper, lower;


void decompose(const vector<point>& hull) {
	int n = hull.size();

	for (int i = 0; i < n; i++) {
		if (hull[i].x < hull[(i + 1) % n].x) {
			lower.push_back(make_pair(hull[i], hull[(i + 1) % n]));
		}
		else {
			upper.push_back(make_pair(hull[i], hull[(i + 1) % n]));
		}
	}
}
bool between(const point& a, const point& b, double x) {
	return (a.x <= x && x <= b.x) || (b.x <= x && x <= a.x);
}
double at(const point& a, const point& b, double x) {
	double dy = b.y - a.y, dx = b.x - a.x;
	return a.y + dy * (x - a.x) / dx;
}

double vertical(double x) {
	double minUp = 1e20, maxLow = -1e20;
	for (int i = 0; i < upper.size(); i++) {
		if (between(upper[i].first, upper[i].second, x))
			minUp = min(minUp, at(upper[i].first, upper[i].second, x));
	}
	for (int i = 0; i < lower.size(); i++) {
		if (between(lower[i].first, upper[i].second, x))
			maxLow = max(maxLow, at(lower[i].first, lower[i].second, x));
	}
	return minUp - maxLow;
}

double solve() {

	double lo = max(minX(hull1), minX(hull2));
	double hi = min(maxX(hull1), maxX(hull2));

	if (hi < lo) return 0;

	for (int iter = 0; iter < 100; iter++) {
		double aab = (lo * 2 + hi) / 3.0;
		double abb = (lo + hi * 2) / 3.0;

		if (vertical(aab) < vertical(abb)) {
			lo = aab;
		}
		else {
			hi = abb;
		}
	}
	return max(0.0, vertical(hi));
}

int main() {
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);


	int TC; scanf("%d", &TC);
	while (TC--) {
		scanf("%d %d", &m, &n);

		for (int i = 0; i < n; i++) {
			point in;
			scanf("%lf%lf", &in.x, &in.y);
			hull1.push_back(in);
		}

		for (int i = 0; i < m; i++) {
			point in;
			scanf("%lf%lf", &in.x, &in.y);
			hull2.push_back(in);
		}
		decompose(hull1); decompose(hull2);
		printf("%lf", solve());
	}
	
	return 0;
}