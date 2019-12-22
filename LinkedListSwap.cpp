#include<stdio.h>
#include <iostream>
using namespace std;

struct node{
	int data;
	node *next;
};

struct node* head = NULL;

void insert_at_start(int value){
	node *temp = new node;
	temp->data = value;
	temp->next = head;
	head=temp;
}

void print_list(node *temp){
	
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}

int length_list(node *temp){
	
	int count=0;
	
	while(temp!=NULL){
		count+=1;
		temp=temp->next;
	}
	
	return count;
}

void swap_nodes(int x, int y){
	
	if(x==y){
		//cout<<"Same nodes, cannot swap";
		return;
	}

	//Search for t1->x
	
	node *t1previous = NULL;
	node *t1current = head;

	while(t1current->data!=x && t1current!=NULL){
		t1previous=t1current;
		t1current=t1current->next;
	}

	//Search for t2->y

	node *t2previous = NULL;
	node *t2current = head;

	while(t2current->data!=y && t2current!=NULL){
		t2previous=t2current;
		t2current=t2current->next;
	}

	if(t1current==NULL && t2current==NULL){
		//cout<<"Cannot find values";
	}

	//If x is the head
	if(t1previous==NULL){
		head=t2current;
	}
	else{
		t1previous->next=t2current;
	}

	//If y is the head
	if(t2previous==NULL){
		head=t1current;
	}
	else{
		t2previous->next=t1current;
	}

	node *swapping_temp= new node;

	swapping_temp=t2current->next;
	t2current->next=t1current->next;
	t1current->next=swapping_temp;
}

void selection_sort(node *temp1){

	int smallest = 0;
	node *temp2 = new node;

	while(temp1!=NULL){
		//debug
		//cout<<"temp1="<<temp1->data<<"\n";

		temp2 = temp1->next;
		smallest = temp1->data;
		node *smallest_node = temp1;

		while(temp2!=NULL){
			//debug
			//cout<<"temp2="<<temp2->data<<"\n";

			if(temp2->data < smallest){
				smallest = temp2->data;
				smallest_node=temp2;
				//cout<<"smallest_node="<<smallest_node->data<<"\n";
			}
			
			temp2 = temp2->next;
		
		}

		//cout<<"temp1="<<temp1->data<<"\n";
		//cout<<"smallest="<<smallest<<"\n";
		//cout<<"smallest_node="<<smallest_node->data<<"\n";
		swap_nodes(temp1->data,smallest);
		
		//print_list(head); cout<<"\n";
		
		//Search for 'smallest' node and equate to temp1

		
		while(smallest_node->data!=smallest && smallest_node!=NULL){
			smallest_node=smallest_node->next;
		}

		temp1 = smallest_node->next;
	}


}


int main(){

	insert_at_start(4);
	insert_at_start(25);
	insert_at_start(12);
	insert_at_start(95);
	insert_at_start(115);
	insert_at_start(114);
	insert_at_start(36);
	insert_at_start(18);
	insert_at_start(52);
	insert_at_start(17);
	insert_at_start(71);
	insert_at_start(67);
	insert_at_start(19);
	insert_at_start(83);
	insert_at_start(1);

	cout<<"Before sorting:\n";
	print_list(head);

	cout<<'\n';
	selection_sort(head);
	cout<<'\n';
	//swap_nodes(5,1);
	cout<<"After sorting:\n";
	print_list(head);

	return 0;
}
