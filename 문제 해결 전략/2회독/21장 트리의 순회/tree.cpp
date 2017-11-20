struct TreeNode{
	string label;
	TreeNode* parent;
	vector<TreeNode *> children;
}

void printLabels(TreeNode * root){

	cout<<root->label<<endl;
	for(TreeNode* ch : root -> children){
		printLabels(ch);
	}
}


int height(TreeNode * root){
	int h = 0;
	for(int i = 0; i < root->children.size(); i++)
		h = max(h, 1 + height(root->children[i]));
	return h;
}

