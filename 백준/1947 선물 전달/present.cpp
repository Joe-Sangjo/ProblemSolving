#include <iostream>
#include <set>
#include <memory>
using namespace std;
int N;
int count = 0;
set<int> record;
void give(int n);
int main(){
	// cin>>N;

	for(int i=2;i<=10;i++){
		count=0;
		N=i;
		give(0);
		// cout<<count<<endl;
		cout<<count<<" = "<<count/(i-1)<<" * "<<i-1<<"      "<<endl;	
	}
	return 0;
}
int count = 0;
set<int> record;
void give(int n){
	if(n==N){
		count++;
		return;	
	}
	else{
		for(int i=0;i<N;i++){
			if(i==n){
				continue;
			}
			else{
				if(record.find(i)==record.end()){
					record.insert(i);
					give(n+1);
					record.erase(i);
				}
			}
		}
	}
}

