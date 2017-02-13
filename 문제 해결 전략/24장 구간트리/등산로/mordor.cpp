#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

const int INT_MAX = numeric_limits<int>::max();
struct RMQ
{
	int n;
	vector<int> rangeMin;
	RMQ(const vector<int>& array){
		n = array.size();
		rangeMin.resize( n * 4);
		init(array, 0, n - 1, 1);
	}
	int init(const vector<int>& array, int left, int right, int node){
		if(left == right)	return rangeMin[node] = array[left];

		int mid = (left + right) / 2;
		int leftMin = init(array, left, mid, node * 2);
		int rightMin = init(array, mid + 1, right, node * 2 + 1);
		return rangeMin[node] = min(leftMin, rightMin);
	}
	int query(int left, int right, int node, int nodeLeft, int nodeRight){

		if(right < nodeLeft || nodeRight < left)	return INT_MAX;

		if(left <= nodeLeft && nodeRight <= right)	return rangeMin[node];

		int mid = (nodeLeft +nodeRight) / 2;

		return min(query(left, right, node*2, nodeLeft, mid), query(left, right, node * 2 + 1, mid + 1, nodeRight));
	}
	int query(int left, int right){
		return query(left, right, 1, 0, n - 1);
	}

	int update(int index, int newValue,int node, int nodeLeft, int nodeRight){

		if(index < nodeLeft || nodeRight < index)		return rangeMin[node];

		if(nodeLeft == nodeRight)	return rangeMin[node] = newValue;

		int mid = (nodeLeft + nodeRight) / 2;

		return rangeMin[node] = min(update(index, newValue, node * 2, nodeLeft, mid), 
			update(index, newValue, node * 2 + 1, mid + 1, nodeRight));
	}
	int update(int index, int newValue){
		return update(index, newValue, 1, 0, n - 1);
	}
};

int N, Q;
// int from[10001], to[10001];
int main(){
	freopen("input.txt","r",stdin);
	setbuf(stdout, NULL);

	int TC; scanf("%d", &TC);

	while(TC--){
		scanf("%d %d", &N, &Q);
		int buf;
		vector<int> Height, revHeight;
		for(int i = 0; i < N; i++){
			scanf("%d", &buf);
			Height.push_back(buf);
			revHeight.push_back(-buf);
		}
		RMQ minH(Height); RMQ maxH(revHeight);
		int from, to;
		for(int i = 0; i < Q; i++){
			scanf("%d %d", &from, &to);
			printf("%d\n", -maxH.query(from, to)-minH.query(from, to));
		}
	}




	return 0;
}