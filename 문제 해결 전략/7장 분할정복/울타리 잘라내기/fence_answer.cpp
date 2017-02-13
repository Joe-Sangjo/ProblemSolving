#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;

int FenceNum;
vector<int> h;
int solve(int left, int right);
int main(){
	freopen("input.txt","r",stdin);
	setbuf(stdout, NULL);
	int TC;
	cin>>TC;
	int data;
	for(int test_case = 0 ; test_case < TC ; test_case++){
		cin>>FenceNum;
		for(int i = 0; i < FenceNum; i++){
			cin>>data;
			h.push_back(data);
		}
		
		int ret = solve(0,h.size());
		cout<<ret<<endl;
		for(int i = 0; i < FenceNum ; i++){
			h.pop_back();
		}

	}
	return 0;
}

int solve(int left, int right){
	if(left == right) return h[left];

	int mid = (left + right) / 2;

	int a = (2*left + right) / 3;

	int b = (left + 2*right) / 3;
	int ret;
	if(right - left >=2){
		ret = max(solve(left, a), solve(a+1,b));
		ret = max(ret ,solve(b+1, right));
	}
	else{
		ret = max(solve(left,mid),solve(mid+1,right));
	}

	int lo = mid, hi = mid + 1;

	int height = min(h[lo], h[hi]);

	ret = max(ret, height * 2);

	while(left < lo || hi < right){
		if(hi < right && (lo == left || h[lo -1 ] < h[hi+1])){
			hi++;
			height = min(height, h[hi]);
		}
		else{
			lo--;
			height = min(height, h[lo]);
		}

		ret = max(ret, height * (hi - lo +1));
	}
	return ret;
}