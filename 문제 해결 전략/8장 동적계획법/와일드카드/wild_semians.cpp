#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
string wild;
string file[50];
string W,S;
int cache[101][101];
bool match(const string& w, const string& s);
bool matchMemoized(int w, int s);
int main(){

	freopen("input.txt","r",stdin);
	setbuf(stdout,NULL);
	int TC; cin>>TC;

	for(int test_case = 0 ; test_case < TC; test_case++){
		cin>>wild>>n;
		for(int i = 0 ; i < n ; i ++){
			cin>>file[i];
			// cout<<file[i]<<endl;
		}
		// for(int i= 0; i < n ; i++)
		// 	if(match(wild, file[i]))
		// 		cout<<file[i]<<endl;
		W = wild;
		for(int i = 0; i < n; i++){
			memset(cache, -1, sizeof(cache));		
			S = file[i];
			if(matchMemoized(0,0))
				cout<<file[i]<<endl;
		}

	}
	return 0;
}

bool match(const string& w, const string& s){
	int pos = 0;
	while(pos < s.size() && pos < w.size() && (w[pos] == '?' || w[pos] == s[pos]))
		pos++;

	if(pos == w.size())
		return pos == s.size();

	if(w[pos] == '*')
		for(int skip = 0; pos+skip <= s.size(); skip++)
			if(match(w.substr(pos+1), s.substr(pos+skip)))
				return true;


	return false;
}

bool matchMemoized(int w, int s){

	int& ret = cache[w][s];
	if(ret != -1 ) return ret;

	while(s < S.size() && w < W.size() && (W[w] == '?' || W[w] == S[s])){
		++w;
		++s;
	}

	if(w == W.size()) return ret = (s == S.size());

	if(W[w] == '*')
		for(int skip = 0; skip + s <= S.size(); skip++)
			if(matchMemoized(w+1, s + skip))
				return ret = 1;

	return ret = 0;
}