#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
	freopen("output.txt","w",stdout);

	srand((unsigned int)time(NULL));
	int n = rand() % 100000 + 1;
	int k = rand() % 1000 + 1;
	int m = rand() % 1000 + 1;

	cout<<n<<" "<<k<<" "<<m<<endl;

	for(int i = 0; i < m; i++){
		for(int j = 0; j < k; j++){
			cout<<rand() % 100000 + 1<<" ";
		}
		cout<<endl;
	}



	return 0;
}