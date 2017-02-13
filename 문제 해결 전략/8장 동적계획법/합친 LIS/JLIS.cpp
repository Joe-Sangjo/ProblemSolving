#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

#define INF 210000000
int n, m;
int a[100], b[100];
int cache[100][100];
int maxsize;
int JLIS(int n_start, int m_start);
int main(){
	freopen("input.txt","r",stdin);
	setbuf(stdout,NULL);

	int TC; cin>>TC;

	for(int test_case = 0 ; test_case < TC; test_case++){
		cin>>n>>m;
		for(int i = 0; i < n; i ++){
			cin>>a[i];
			// cout<<a[i]<<" ";
		}
		// cout<<endl;
		for(int j = 0 ; j < m ; j++){
			cin>>b[j];
			// cout<<b[j]<<" ";
		}
		// cout<<endl;
		maxsize = 0;
		memset(cache,-1,sizeof(cache));
		cout<<JLIS(0,0)<<endl;
	}

	return 0;
}


int JLIS(int n_start, int m_start){
	if(n_start == n || m_start == m)  return 0;

	if(n - n_start + m - m_start <= maxsize) return maxsize;

	int& ret = cache[n_start][m_start];

	if(ret < -1) return maxsize;

	if(ret != -1 ) return ret;

	vector<int> B;
	
	int n_index = n_start, m_index = m_start;

	int pre = INF;
	
	while(n_index < n || m_index < m){
		if((a[n_index] < b[m_index])){
			if(a[n_index] < pre){
				 pre = a[n_index];
				 B.push_back(pre);
				}
			n_index++;
		}
		else{
			if(b[m_index] < pre){
				pre = b[m_index];
				B.push_back(pre);
			}
			m_index++;
		}
	}

	ret = max(ret, (int)B.size() );
	for(int n_next = n_start + 1 ; n_next < n; n_next ++){
		for(int m_next = m_start + 1 ; m_next < m ; m_next ++){
			ret = max(ret, JLIS(n_next, m_next));
		}
	}
	maxsize = max(ret,maxsize);
	return ret;
}