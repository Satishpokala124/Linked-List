#include <iostream>
using namespace std;

struct Node
{	
  int data;
  Node *nxt;
};

Node * insert(Node *head, int data){
	Node *newNode = new Node;
	newNode->data = data;
	newNode->nxt = NULL;
	if(!head){
		head = newNode;
		return head;
	}
	Node *temp = head;
	while(temp->nxt)temp = temp->nxt;
	temp->nxt = newNode;
	return head;  
}

Node * insert(Node *head, int data, int pos){
	Node *newNode = new Node;
	newNode->data = data;
	newNode->nxt = NULL;
	if(head == NULL){
		head = newNode;
		return head;
	}
	if(!pos){
		newNode->nxt = head;
		head = newNode;
		return head;
	}
	Node *temp = head;
	while(temp->nxt && --pos)temp = temp->nxt;
	newNode->nxt = temp->nxt;
	temp->nxt = newNode;
	return head;
}

Node * append(Node *head, int data){
	return insert(head,data);
}

Node * remove(Node *head, int pos){
	if(!head){
		cout << "List already empty. Nothing to remove." << endl;
		return head;
	}
	if(!pos){
		Node *removed = head;
		head = head->nxt;
		cout<<"Removed "<<removed->data<<endl;
		free(removed);
		return head;
	}
	Node *temp = head;
	while(temp->nxt->nxt && --pos)temp = temp->nxt;
	Node *removed = temp->nxt;
	temp->nxt = temp->nxt->nxt;
	cout<<"Removed "<<removed->data<<endl;
	free(removed);
	return head;
}

Node * remove(Node *head){
	return remove(head,0);
}

Node * pop(Node *head){
	return remove(head,0);
}

void display(Node *head){
  Node *temp = head;
  while(temp!=NULL){
    cout<<temp->data<<" -> ";
    temp = temp->nxt;
  }
  cout<<"NULL"<<endl;
}

Node * nthNodeFromEnd(Node *head, int n){
	if (!head) return head;
	if (!n){
		cout << "Warning!! 0th Node from the end is NULL." << endl;
		cout << "Returning NULL..." << endl;	
		return NULL;
	}
	int dun_n = n;
	Node *lead = head;
	int nodes = 0;
	while(lead && --n){
		lead = lead->nxt;
		nodes++;
	}
	if (!lead){
		cout << "Warning!! There are only " << nodes << " Nodes." << endl;
		cout << "Returning head..." << endl;
		return head;
	}
	Node *tail = head;
	while(lead->nxt){
		lead=lead->nxt;
		tail=tail->nxt;
	}
	return tail;
}