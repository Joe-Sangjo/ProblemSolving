#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void normalize(vector<int>& num){
	num.push_back(0);

	for(int i = 0 ; i < num.size(); i++){
		if(num[i] < 0 ) {
			int borrow = (abs(num[i]) + 9) / 10;
			num[i+1] -= borrow;
			num[i] = borrow * 10;
		}
		else{
			num[i+1] += num[i] / 10;
			num[i] %= 10;
		}
	}
	while(num.size() > 1 && num.back() == 0 ) num.pop_back();
}

vector<int> multiply(const vector<int>& a, const vector<int>& b){
	vector<int> c(a.size() + b.size() + 1, 0);
	for(int i = 0; i < a.size(); i++)
		for(int j = 0; j  < b.size(); j++)
			c[i+j] += a[i]*b[j];

	normalize(c);
	return c;
}

void addTo(vector<int>& a, const vector<int>& b, int k){
	if(a.size() - (b.size() + k) < 0){
		// cout<<1<<endl;
		for(int i = 0; i < b.size() + k - a.size() ; i++)
			a.push_back(0);
	}

	for(int i = 0; i < b.size() ; i++)
		a[i+k] += b[i];

	normalize(a);
	
}

void subFrom(vector<int>& a, const vector<int>& b){
	for(int i = 0; i < b.size() ; i++)
		a[i]-=b[i];
	normalize(a);	
}

vector<int> karatsuba(const vector<int>& a, const vector<int>& b){
	
	int an = a.size(), bn = b.size();

	if(an < bn) return karatsuba(b, a);

	if(an == 0 || bn == 0) 	return vector<int>();

	if(an <= 1) return multiply(a,b);

	int half = an / 2;

	vector<int> a0(a.begin(), a.begin()+half);
	vector<int> a1(a.begin() + half, a.end());
	vector<int> b0(b.begin(), b.begin() + min<int>(b.size(),half));
	vector<int> b1(b.begin() + min<int>(b.size(),half), b.end());


	vector<int> z2 = karatsuba(a1, b1);
	vector<int> z0 = karatsuba(a0, b0);

	addTo(a0, a1, 0); addTo(b0, b1, 0);

	vector<int> z1 = karatsuba(a0, b0);

	subFrom(z1, z0);
	subFrom(z1, z2);

	vector<int> ret;
	addTo(ret, z0, 0);
	addTo(ret, z1, half);
	addTo(ret, z2, half+half);
	return ret;
}

void print(vector<int>& a){
	for(vector<int>::iterator iter = a.begin() ; iter !=a.end(); iter++){
		cout<<*iter<<" ";
	}
	cout<<endl;
}

int main(){

	vector<int> a;
	vector<int> b;

	// a = 123 , b = 456a
	a.push_back(3); a.push_back(2); a.push_back(1);
	b.push_back(6); b.push_back(5); b.push_back(4);
	a.push_back(3); a.push_back(2); a.push_back(1);
	b.push_back(6); b.push_back(5); b.push_back(4);
	cout<<a.size()<<endl;

	cout<<"Kolmogorov"<<endl;
	vector<int> c = multiply(a,b);
	print(c);
	cout<<endl;
	cout<<"karatsuba"<<endl;
	vector<int> d = karatsuba(a,b);
	print(d);
	return 0;
}
