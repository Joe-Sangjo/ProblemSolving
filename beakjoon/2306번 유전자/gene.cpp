#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <stack>
using namespace std;

int KOI(string gene);
bool isKOI(string aa);
int cache[510];
int main(){
	freopen("input.txt","r",stdin);
	memset(cache, false, sizeof(cache));
	string gene;
	cin>>gene;
	cout<<KOI(gene)<<endl;
	return 0;
}

int KOI(string gene){
	if(isKOI(gene)){
		return gene.size();
	}
	if(gene.size() == 0) return 0;
	
	int size = 0;
	char buf1[2], buf2[2];
	buf1[1] = buf2[1] = '\0';
	
	string temp = gene;
	
	for(int i = 0 ; i < gene.size(); i++){
		buf1[0] = temp[i];
		
		temp.erase(i,1);

		for(int j = 0; j < temp.size(); j++){
			buf2[0] = temp[j];

			temp.erase(j,1);

			size = max(size,KOI(temp));
			temp.insert(j,buf2);
		}
		temp.insert(i, buf1);
	}
	return size;
}
bool isKOI(string aa){
	
	bool ret = true;
	stack<char> st;
	for(int i = 0; i < aa.size(); i++){
		if(aa[i] == 'a' || aa[i] == 'g'){
			st.push(aa[i]);
		}
		else if(aa[i] == 't'){
			if(st.size() == 0 || st.top() != 'a' ){
				ret = false;
				break;
			}
			st.pop();
		}else{
			if(st.size() == 0 || st.top() != 'g'){
				ret = false;
				break;
			}
			st.pop();
		}
	}
	return ret;
}