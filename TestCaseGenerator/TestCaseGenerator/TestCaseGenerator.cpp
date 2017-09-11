#include <random>
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	mt19937 rng;
	rng.seed(random_device()());
	uniform_int_distribution<mt19937::result_type> dist(0, 200); 

	freopen("input.txt", "w", stdout);


	int testcase = 100;
	cout << testcase << endl;

	for (int i = 0; i < testcase; i++) {
		
		int xmin = dist(rng), ymin = dist(rng);
		uniform_int_distribution<mt19937::result_type> dist2(xmin, 200); 
		uniform_int_distribution<mt19937::result_type> dist3(ymin, 200);

		int xmax = dist2(rng), ymax = dist3(rng);

		int x1 = dist(rng), y1 = dist(rng), x2 = dist(rng), y2 = dist(rng);

		cout << xmin - 100 << " " << ymin - 100 << " " << xmax - 100 << " " << ymax - 100 << endl << x1 - 100 << " " << y1 -100 << " " << x2 - 100 << " " << y2 - 100 << endl;



	}

}