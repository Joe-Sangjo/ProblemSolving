#include <iostream>
#include <cstdio>
#include <limits>
#include <algorithm>
using namespace std;
double t;
int n;
double runningSpeed[20], cyclingSpeed[20];

double convex(double r) {
	double cheaterTime = r / runningSpeed[n - 1] + (t - r) / cyclingSpeed[n - 1];
	double fastestRunnerTime = numeric_limits<double>::max();
	for (int i = 0; i < n - 1; i++) {
		fastestRunnerTime = min(fastestRunnerTime, r / runningSpeed[i] + (t - r) / cyclingSpeed[n - 1]);
	}
	return fastestRunnerTime - cheaterTime;
}

int main() {
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%ld %d", &t, &n);
	for (int i = 0; i < n; i++) {
		scanf("%lf %lf", &runningSpeed[i], &cyclingSpeed[i]);
	//	printf("%.2lf %.2lf\n", running[i], cycling[i]);
	}
	double lo = 0, hi = t + 0.1;
	for (int i = 0; i < 100; i++) {
		double a = (lo * 2 + hi) / 3, b = (lo + 2 * hi) / 3;
		if (convex(a) > convex(b)) {
			hi = b;
		}
		else {
			lo = a;
		}
	}
	double r = (lo + hi) / 2;

	if (r > 0) {
		printf("%.2f %.2f\n", r, r / runningSpeed[n - 1] + (t - r) / cyclingSpeed[n - 1]);
	}
	else {
		printf("이길 수 없어");
	}


	return 0;
}