#include <iostream>
using namespace std;


struct TreeNode{
	int data;
	TreeNode *left, *right;	
	TreeNode(){left=NULL;right=NULL;}
	void newNode(TreeNode*,int data);
	bool hasNoSons(){
		if (left == NULL && right == NULL) return true;
		else return false;
	}
};

void count(TreeNode*,int&);
void children(TreeNode*,int&);
void insert(TreeNode*&,int);
void inorder(TreeNode*);
void preorder(TreeNode*);
void postorder(TreeNode*);
void newNode(TreeNode*&,int);
void remove(TreeNode*&,int);

TreeNode *tree = NULL;

int main(){

	int numnodes = 0,childcount = 0;

	insert(tree,5);
	insert(tree,3);
	insert(tree,4);
	insert(tree,7);
	insert(tree,1);

	//Printing tree in various orders
	cout<<"Inorder: ";
	inorder(tree);
	cout<<endl;

	cout<<"Preorder: ";
	preorder(tree);
	cout<<endl;

	cout<<"Postorder: ";
	postorder(tree);
	cout<<endl<<endl;


	//Counting nodes
	count(tree,numnodes);
	cout<<"There are "<<numnodes<<" in the tree currently.."<<endl<<endl;

	//Counting and printing amount of children for each node
	children(tree,childcount);
	

	remove(tree,4);
	remove(tree,1);
	
	cout<<endl;
	return 0;
}
void newNode(TreeNode* &node,int data){
	node = new TreeNode;
	node->data = data;
}

void insert(TreeNode* &tree,int data){
	if(tree == NULL){
		newNode(tree,data);
	}
	else{
		if(data < tree->data){
			insert(tree->left,data);
		}
		if(data > tree->data){
			insert(tree->right,data);
		}
		
	}

}

void remove(TreeNode* &tree,int data){
	if(tree->data == data){
		cout<<"Found!!"<<endl;

		if(tree->hasNoSons()){
			cout<<"Is a leaf"<<endl;
			delete tree;
			tree = NULL;
			//cout<<tree->data<<endl;
			
		}

		
	}
	else{
	 	if(data < tree->data){
	 		remove(tree->left,data);
	 	}
	 	if(data > tree->data){
	 		remove(tree->right,data);
	 	}
	}

	inorder(tree);cout<<endl;
	return;
}

void inorder(TreeNode* tree){
	if(tree == NULL){
	    return;
	}
	else{
		inorder(tree->left);
		cout<<tree->data;
		inorder(tree->right);
	}

}

void postorder(TreeNode* tree){
	if(tree == NULL){
	    return;
	}
	else{
		inorder(tree->left);
		inorder(tree->right);
		cout<<tree->data;
	}

}



void preorder(TreeNode* tree){
	if(tree == NULL){
	    return;
	}
	else{
		cout<<tree->data;
		inorder(tree->left);
		inorder(tree->right);
	}

}

//Counting nodes
void count(TreeNode* tree,int& numnodes){
	if(tree == NULL){
	    return;
	}
	else{
		count(tree->left,numnodes);
		numnodes++;
		
		count(tree->right,numnodes);
	}	
}

//Counting and printing amount of children for each node
void children(TreeNode* tree,int& childcount){
	if(tree == NULL){
	    return;
	}
	else{
		children(tree->left,childcount);
		if(tree->left != NULL) childcount++;
		if(tree->right != NULL) childcount++;
		cout<<tree->data<< ": node has " <<childcount<<" children.."<<endl;
		childcount = 0;
		children(tree->right,childcount);
		
	}	
}

