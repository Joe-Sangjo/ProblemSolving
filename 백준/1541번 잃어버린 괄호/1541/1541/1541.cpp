#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);


	int num;

	int sum = 0;
	scanf("%d", &num);
	sum = num;
	bool sign = num > 0;
	while (scanf("%d", &num) == 1) {
		//printf("%d\n", num);
		if (sign) {
			sign = num > 0;
			sum += num;
		}
		else {
			sum += num < 0 ? num : -num;
		}
	}
	printf("%d\n", sum);


	return 0;
}