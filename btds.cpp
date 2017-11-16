#include <iostream>
#include <fstream>
using namespace std;


struct TreeNode{
	int data;
	TreeNode *left, *right;	
	TreeNode(){left=NULL;right=NULL;}
};

void count(TreeNode*,int&);
void children(TreeNode*,int&);
void insert(TreeNode*&,int);
void inorder(TreeNode*);
void preorder(TreeNode*);
void postorder(TreeNode*);
void newNode(TreeNode*&,int);
void remove(TreeNode*&,int);
void freeTree(TreeNode* &tree);
void readData(TreeNode* &tree);
void readInstructions(TreeNode* &tree);
void printOrders(TreeNode* tree);
void processSets(TreeNode* &tree);
TreeNode* findmin(TreeNode *tree);

ifstream fin;
TreeNode *tree = NULL;
const int EMPTY = -1;
const int END = -999;
int main(){
	string set;
	fin.open("data.txt");

    while(!fin.eof()){
	 	processSets(tree);
	 	cout<<endl<<endl;
    }
	return 0;
}

void processSets(TreeNode* &tree){
	int numnodes = 0,childcount = 0;
	

	readData(tree);

	printOrders(tree);

	//Counting nodes
	count(tree,numnodes);
	cout<<"There are "<<numnodes<<" in the tree currently.."<<endl;
	children(tree,childcount);
	
	readInstructions(tree);
	printOrders(tree);

	freeTree(tree);
}

void printOrders(TreeNode* tree){
	//Printing tree in various orders
	cout<<"Inorder: ";
	inorder(tree);
	cout<<endl;

	cout<<"Preorder: ";
	preorder(tree);
	cout<<endl;

	cout<<"Postorder: ";
	postorder(tree);
	cout<<endl;
}
void readInstructions(TreeNode* &tree){
	string instruction,node;

	while(true){
		fin>>instruction;
		
		if(instruction == "Insert"){
			fin>>node;
			insert(tree,stoi(node));
		}

		else if(instruction == "Delete"){
			fin>>node;
			remove(tree,stoi(node));

		}
		else if(instruction == "End")
			return;
	}
}
void readData(TreeNode* &tree){
	string set,node;
	fin>>set;
	cout<<set<<endl;
	do{
		fin>>node;
		insert(tree,stoi(node));

	}while(stoi(node) != -999);		
}


void newNode(TreeNode* &node,int data){
	node = new TreeNode;
	node->data = data;
}

void freeTree(TreeNode* &tree){
	delete tree;
	tree = NULL;
	cout<<"Tree Freed"<<endl;
}

void insert(TreeNode* &tree,int data){
	if(tree == NULL){
		if(data != END){
			cout<<"Inserting Node..."<<endl;
			newNode(tree,data);
		}
		else 
			return;
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
	if(tree == NULL) return;
	if(tree->data == data){
		//If no sons
		if(tree->right == NULL && tree->left == NULL){
			cout<<"Deleting Node..."<<endl;
			freeTree(tree);
		}
			// tree->data = EMPTY;
		//If one son
		else if(tree->right == NULL){
			TreeNode* temp = tree;
			tree = tree->left;
			freeTree(temp);
		}
		else if(tree->left == NULL){
			TreeNode* temp = tree;
			tree = tree->right;
			freeTree(temp);
		}
		else if(tree->left != NULL && tree->right != NULL){
			TreeNode* min = findmin(tree);
			tree->data = min->data;
			remove(tree->right,min->data);
		}
	}

	else{ 
		if(tree->data != EMPTY){
			if(data < tree->data)
	 			remove(tree->left,data);
			if(data > tree->data)
	 			remove(tree->right,data);
		}
	}
	
	
	// 	/*
	// 		Accounting for the -1 in the tree 
	// 		Just check left or right and continue as is

	// 	*/
	// 	else{
			
	//  		if(tree->left->data == data){
	// 			cout<<"Deleting Node..."<<endl;
	// 			tree->left->data = EMPTY;
	// 		}
	// 		if(tree->right->data == data){
	// 			cout<<"Deleting Node..."<<endl;
	// 			tree->right->data = EMPTY;
	// 		}

	// 		if(data < tree->left->data)
	//  			remove(tree->left,data);
	// 		if(data > tree->right->data)
	//  			remove(tree->right,data);

	// 	}	
		
		
	
	return;
}


TreeNode* findmin(TreeNode *tree){
	tree = tree->right;
	while(tree->left!=NULL){
		tree = tree->left;
	}
	return tree;
}



void inorder(TreeNode* tree){
	if(tree == NULL){
	    return;
	}
	else{
		inorder(tree->left);
		//if (tree->data != EMPTY)
			cout<<tree->data<<", ";
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
		//if(tree->data != EMPTY) 
			cout<<tree->data<<", ";
	}

}



void preorder(TreeNode* tree){
	if(tree == NULL){
	    return;
	}
	else{
		//if(tree->data != EMPTY)
			cout<<tree->data<<", ";
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

