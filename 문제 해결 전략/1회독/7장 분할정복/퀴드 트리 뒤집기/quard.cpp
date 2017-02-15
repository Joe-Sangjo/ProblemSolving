#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

string picture;
int pictureIndex;

class node{
public:
	char data;
	node* first;
	node* second;
	node* third;
	node* fourth;
	node(char data){
		this->data = data, first = NULL, second = NULL, third = NULL, fourth = NULL;
	}
};
class tree{
public: 
	node *root;
	tree(){
		root = NULL;
	}
	void save_Data(){
		saveData(root);
	}
	void saveData(node*& savenode){
		if(picture.size() == pictureIndex) return;
	
		savenode = new node(picture[pictureIndex]);
	
		if(picture[pictureIndex++] != 'x')
			return;
		else{
			saveData(savenode->first);
			saveData(savenode->second);
			saveData(savenode->third);
			saveData(savenode->fourth);
			return;
		}
	}
	void print_(){
		print(root);
	}
	void print(node* printnode){
		if(printnode == NULL) return;
		cout<<printnode->data;
		print(printnode->third);
		print(printnode->fourth);
		print(printnode->first);
		print(printnode->second);
	}
};

int main(){

	freopen("input.txt","r",stdin);
	setbuf(stdout, NULL);

	int TC;
	cin>>TC;

	for(int test_case = 0; test_case <TC ; test_case++){
		cin>>picture;
		pictureIndex = 0;
		tree t;
		t.save_Data();
		t.print_();
		cout<<endl;
	}


	return 0;
}