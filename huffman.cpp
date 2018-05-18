#include <iostream>
#include <fstream>
#include <queue>
#include <algorithm>
using namespace std;
int size=0;
struct Node{
	int key;
	int freq;
	Node *left;
	Node *right;
	Node(int key, int value){
		this->left=NULL;
		this->right=NULL;
		this->key=key;
		this->freq=value;		
	}
};

void print(Node* root, string code, ofstream& file){
	if(root==NULL)
		return;

	if(root->key!=-128){
		file<<root->key<<"\t"<<code<<endl;
		size+=code.length()*(root->freq);
	}
	print(root->left, code+"0",file);
	print(root->right, code+"1",file);
}
struct Compare{
	bool operator() (Node*a, Node*b){
		return a->freq > b->freq;
	}
};

int main(){
	priority_queue<Node*, vector<Node*>, Compare> minheap;
	int k;
	int fq;
	while(cin>>k){
		cin>>fq;
		//cout<<fq<<endl;
		minheap.push(new Node(k,fq));
	}

	while(minheap.size()>1){
		Node* left=minheap.top();
		minheap.pop();
		Node* right=minheap.top();
		minheap.pop();
		//
		Node* mergeNode=new Node(-128,left->freq + right->freq);
		mergeNode->left=left;
		mergeNode->right=right;
		minheap.push(mergeNode);
	}
	if(minheap.top()==NULL){
		return 0;
	}
	ofstream file("codewords.txt");
	print(minheap.top(),"",file);
	file.close();
	cout<<size;
	return 0;

}






