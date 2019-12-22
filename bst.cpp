#include<stdio.h>
#include <iostream>
using namespace std;

struct node{
	int value;
	struct node *left;
	struct node *right;
};

//struct node* root = NULL;

//holder function just to create new empty node
node* create_node(int data){
	node* temp = new node;
	temp->value=data;
	temp->left=NULL;
	temp->right=NULL;

	return temp;
}

//function which inserts a node in the correct place given a root
void insert(int data, node* &root){

	if(root==NULL){
		root = create_node(data);
		return;
	}

	if(data < root->value){
		insert(data,root->left);
	}else{
		insert(data,root->right);
	}

}

//function which prints in-order traversal of a tree
void traverse(node* root){
	
	if(root==NULL){
		return;
	}

	traverse(root->left);
	cout<<root->value<<" ";
	traverse(root->right);

}

//function to find a node with a value=data
node* search(int data, node* root){
	while(root->value!=data){
		if(root->value<data){
			root=root->right;
		}else{
			root=root->left;
		}
	}
	return root;
}

//function to find the maximum value in a tree with given root
node* max_in_subtree(node* root){
	while(root->right!=NULL){
		root=root->right;
	}
	return root;
}

//function to delete node with a given value=data
node* delete_node(int data, node* root){

	node* temp = search(data,root);

	if(root==NULL){
		return root;
	}
	//keep trying to find where the data is that we want to delete
	else if (data<root->value) {
		root->left = delete_node(data,root->left);
	}
	else if (data>root->value) {
		root->right = delete_node(data,root->right);
	}
	else{
	//case when data=root->value

		//when root has no children
		if(root->left==NULL && root->right==NULL){
			delete root;
			root=NULL;
			return root;
		}
		//when root has only left child
		else if (root->right==NULL){
			node* temp2 = new node;
			temp2=root;
			root=root->left;
			delete temp2;
			return root;
		}
		//when root has only right child
		else if (root->left==NULL){
			node* temp2 = new node;
			temp2=root;
			root=root->right;
			delete temp2;
			return root;
		}
		//when root has both children
		else{
			node* temp2 = max_in_subtree(root->left);
			root->value=temp2->value;
			root->left = delete_node(temp2->value,root->left);
		}
	}

	return root;

}

int main(){

	struct node* root = NULL;
	//insert(4,root);
	//insert(45,root);
	//insert(14,root);

	int input[]={100, 50, 200, 150, 300, 25, 75, 12, 37, 125, 
		175, 250, 320, 67, 87, 94, 89,92,88};

	//int input[]={10,9,8,7,6,5,4,3,2,1};

	cout<<"Inserting values..."<<'\n';

	for(int i =0;i<19;i++){
		insert(input[i],root);
	}

	cout<<"Printing inorder..."<<'\n';
	traverse(root);
	cout<<"\n";

	cout<<"Deleting node 100..."<<'\n';
	delete_node(100,root);

	cout<<"Printing inorder..."<<'\n';
	traverse(root);


	return 0;
}