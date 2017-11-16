#include <iostream>
#include <fstream>
using namespace std;

void insert(int,int[],int);
void initializeTree(int[]);
void printingTree(int [] );
void remove(int ,int[],int);
void inorder(int bintree[],int index);
void processSets(int []);
void readData(int []);
void printOrders(int[]);
void readInstructions(int bintree[]);

const int NODES = 1000000;
const int ROOT = 0;
const int EMPTY = -1;
const int START = 1;
const int END = -999;
ifstream fin;


int main(){
	fin.open("data.txt");

	int bintree[NODES];
	initializeTree(bintree);
	//while(!fin.eof)
		processSets(bintree);


}
void processSets(int bintree[]){
	int numnodes = 0,childcount = 0;
	

	readData(bintree);

	printOrders(bintree);

	// //Counting nodes
	// count(bintree,numnodes);
	// cout<<"There are "<<numnodes<<" in the tree currently.."<<endl;
	// children(bintree,childcount);

	readInstructions(bintree);
	printOrders(bintree);

}
void initializeTree(int bintree[]){
	bintree[0] = ROOT;
	for(int i = 1;i<NODES;i++){
		bintree[i] = EMPTY;
	}
}


void readData(int bintree[]){
	string set,node;
	fin>>set;
	cout<<set<<endl;
	do{
		fin>>node;
		insert(stoi(node),bintree,START);

	}while(stoi(node) != END);		
}


void readInstructions(int bintree[]){
	string instruction,node;

	while(true){
		fin>>instruction;
		if(instruction == "Insert"){
			fin>>node;
			insert(stoi(node),bintree,START);
		}

		else if(instruction == "Delete"){
			fin>>node;
			remove(stoi(node),bintree,START);

		}
		else if(instruction == "End")
			return;
	}
}

void insert(int data,int bintree[],int index){
	//If empty initialize 1st
	if(index > NODES) return;
	if(data == END) return;
	if(bintree[index] == EMPTY) bintree[index] = data;

	else{
		if(data > bintree[index])
			insert(data,bintree,index*2+START);
		else
			insert(data,bintree,index*2);
	}
	return;
}

void remove(int data,int bintree[],int index){
	if(data == bintree[index]){
		bintree[index] = EMPTY;
	}
	else{
		if(data > bintree[index])
			remove(data,bintree,index*2+START);
		else
			remove(data,bintree,index*2);
		
	}
}

void inorder(int bintree[],int index){
	if(bintree[index] != EMPTY){
		inorder(bintree,2*index);
		cout<<bintree[index]<<endl;
		inorder(bintree,2*index+START);
	}
}
void preorder(int bintree[],int index){
	if(bintree[index] != EMPTY){
		cout<<bintree[index]<<endl;
		inorder(bintree,2*index);
		inorder(bintree,2*index+START);
	}
}
void postorder(int bintree[],int index){
	if(bintree[index] != EMPTY){
		inorder(bintree,2*index);
		inorder(bintree,2*index+START);
		cout<<bintree[index]<<endl;
	}
}

void printOrders(int bintree[]){
	//Printing tree in various orders
	cout<<"Inorder: ";
	inorder(bintree,START);
	cout<<endl;

	cout<<"Preorder: ";
	preorder(bintree,START);
	cout<<endl;

	cout<<"Postorder: ";
	postorder(bintree,START);
	cout<<endl;
}
