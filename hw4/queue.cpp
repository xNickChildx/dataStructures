/**
* Data Structures: HW 4
*Code by Nick Child
*id:nchild2019
*
*/
#include <stdio.h>
#include <iostream>
using namespace std;
typedef struct singleLinkedList{
	int data;
	struct singleLinkedList *next;
}Node;  //single linked list to define structure

int menu(); //displays options
void insert(); //inserts to last
int Delete(); //deletes from begining and returns value
void display(); //show all contents
Node* getNode(); //gets data and creates new node

Node *start=NULL; //pointer to start of List;
Node *last=NULL;//pointer to last of List


int main(){
	do{
		switch(menu()){
			case(1):insert();
					break;
			case(2):printf("Deleted %d\n\n",Delete());
					break;
			case(3):display();
					break;
			case(4):
			default:
					exit(0);
					break;
				}
			}
			while(1);


		
	}
int menu(){
	int response;
	printf("--WAITING FOR NEXT INSTRUCTION:\n---Enter 1 to insert\n---Enter 2 to delete\n---Enter 3 to display\n---Enter 4 to quit\n\n");
	
	scanf("%d", &response);
	return response;
}

void insert(){
	Node *newNode=getNode();

	if(start==NULL){ //if list is empty, newNode is first and last
		start=newNode;
		last=newNode;

	}
	else{			//else add new node to last of list make new node the new last object
		last->next=newNode;
		last=newNode;
	}
}
int Delete(){
	if(start==NULL){//if list is empty display error return 0
		printf("CANNOT REMOVE, QUEUE IS EMPTY, RETURNING 0\n\n");
		return 0;

	}
	else{
		Node *temp=start;
		start=start->next;
		return temp->data;
	}
}

void display(){
	Node *iter;
	printf("Displaying oldest to newest:\n");
	iter=start;
	while(iter!=NULL){
			printf("%d\n",iter->data);
			iter=iter->next;
	}
	printf("\n");
}





	//method to create and return a new item
Node* getNode(){
	Node* newNode;
	newNode=(Node *)malloc(sizeof(Node));
	printf("Enter data\n");
	scanf("%d",&(newNode->data));
	newNode->next=NULL;
	printf("\n\n");
	return newNode;
}