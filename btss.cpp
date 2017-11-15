#include <iostream>
using namespace std;

void insert(int,int[]);
void initializeTree(int[]);
void printingTree(int [] );
void remove(int ,int[] );
const int NODES = 20;
const int ROOT = 0;
const int EMPTY = -1;
int main(){
	int bintree[NODES];
	initializeTree(bintree);

	insert(5,bintree);
	insert(2,bintree);
	insert(6,bintree);
	insert(9,bintree);

	printingTree(bintree);
	remove(9,bintree);
	printingTree(bintree);

}
void initializeTree(int bintree[]){
	bintree[0] = ROOT;
	for(int i = 1;i<NODES;i++){
		bintree[i] = EMPTY;
	}
}

void printingTree(int bintree[]){
	for(int i = 0;i<NODES;i++){
		cout<<bintree[i];
	}
	cout<<endl;
}
void insert(int data,int bintree[]){
	//Starting place
	int i = 1;
	bool placed = false;
	//If empty initialize 1st
	if(bintree[1] == EMPTY) bintree[1] = data;

	else{
		while(!placed){
			//If less go 2*i
			if(data < bintree[i]){
				if(bintree[2*i] == EMPTY){
					bintree[2*i] = data;
					placed = true;
				}
				else
					i++;
			}
			else if(data > bintree[i]){

				if(bintree[2*i+1] == EMPTY){
					bintree[2*i+1] = data;
					placed = true;
				}
				else
					i++;
			}
			else break;
		}
			
		
	}
	return;
}

void remove(int data,int bintree[]){
	//Starting place
	int i = 1;
	bool found = false;

	while(!found){
		if(data < bintree[i]){
			if(bintree[2*i] == data){
				bintree[2*i] = EMPTY;
				found = true;
				return;
			}
			else
				i++;
		}
		else break;
	}

	//
	while(!found){
		if(data > bintree[i]){

			if(bintree[2*i+1] == data){
				bintree[2*i+1] = EMPTY;
				found = true;
				return;
			}
			else
				i++;
		}
		else break;
	}
}
