#include <iostream>
#include <cstdio>
#include <list>

using namespace std;
int N, K;


int main(){
	freopen("input.txt","r",stdin);
	setbuf(stdout, NULL);

	int TC;		cin>>TC;

	while(TC--){
		cin>>N>>K;
		// cout<<N<<" "<<K<<endl;

		list<int> l;
		for(int i = 0; i < N; i++){
			l.push_back(i+1);
			// cout<<l[i]<<" ";
			// cout<<i+1<<" ";
		}
		// cout<<endl;

		list<int>::iterator it = l.begin();
		// cout<<"///////////////"<<endl;
		while(l.size() > 2){
			// it = l.begin();
			// cout<<*it<<" ";
			it = l.erase(it);
			if(it == l.end()) it = l.begin();
			
			for(int i = 1; i < K; i++){
				it++;
				if(it == l.end()) it = l.begin();
			}
		}
		// cout<<endl;
		// cout<<"]]]]]]]]]]]]]]]]]]]]]]]]"<<endl;
		for(it = l.begin(); it != l.end(); it++){
			cout<< *it <<" ";
		}
		cout<<endl;

	}
	return 0;
}


