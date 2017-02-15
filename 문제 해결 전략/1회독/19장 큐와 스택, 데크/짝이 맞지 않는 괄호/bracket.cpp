#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;


int main(){
	freopen("input.txt","r",stdin);
	setbuf(stdout, NULL);

	int TC;	cin>>TC;
	while(TC--){
		string bracket;
		stack<char> b;
		cin>>bracket;
		// cout<<bracket<<endl;
		bool check = true;
		for(int i = 0; i < bracket.size(); i++){
			if(bracket[i] == '(' || bracket[i] == '{' || bracket[i] == '['){
				b.push(bracket[i]);
			}
			else if(bracket[i] == ')'){
				if(b.empty() || b.top() !='('){
					check = false;
					break;
				}
				b.pop();
			}
			else if(bracket[i] == '}'){
				if(b.empty() || b.top() !='{'){
					check = false;
					break;
				}
				b.pop();				
			}
			else{
				if(b.empty() || b.top() !='['){
					check = false;
					break;
				}
				b.pop();				
			}
		}

		if(check && b.empty())	cout<<"YES"<<endl;
		else	cout<<"NO"<<endl;
	}




	return 0;
}