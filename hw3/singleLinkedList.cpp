/*Design and Implement a single linked list with the following operations, lectures
single linked list 01 and 02 have example code/pseudocode for each operation.
a
-
C
reate "n" nodes 
b
-
D
elete from the middle
c
-
Insert in the middle
*/
#include <iostream>
typedef struct singleLinkedList{
	int data;
	struct singleLinkedList *next;
}Node;
 Node* getNode();
 void createList(int n);
 void printList();
 void insertBeg();
void insertEnd();
void insertMid();
int countNode(Node *);
void deleteBeg();
void deleteEnd();
void deleteMid();
Node *start=NULL; //pointer to start of List;
using namespace std;

int main(){
	printf("(testing CreateList) Enter number of items to add to the list:\n");
	int n;
	scanf("%d",&n);
	createList(n);
	printf("(testing printList)\n");
	printList();
	/*printf("(testing insertAtBeg)\n");
	insertBeg();
	printList();
	printf("(testing insertAtEnd)\n");
	insertEnd();
	printList();
	printf("(testing countNodes)\n %d\n",countNode(start));*/
	printf("(testing insertAtMiddle)\n");
	insertMid();
	printList();
	/*printf("(testing deleteAtBeg)\n");
	deleteBeg();
	printList();
	printf("(testing deleteAtEnd)\n");
	deleteEnd();
	printList();*/
	printf("(testing deleteAtMid)\n");
	deleteMid();
	printList();


}
	//method to create and return a new item
Node* getNode(){
	Node* newNode;
	newNode=(Node *)malloc(sizeof(Node));
	printf("Enter data\n");
	scanf("%d",&(newNode->data));
	newNode->next=NULL;
	return newNode;
}

//method to add n items to the list
void createList(int n){
	int i;
	Node *newNode;
	Node *temp;
	for(int i=0;i<n;i++){
		newNode=getNode();
		if(start==NULL)
			start=newNode;
		else{
			temp=start;
			
			while(temp->next!=NULL)
				temp=temp->next;
			temp->next=newNode;
		}
	}

}

//method to print values in list
void printList(){
	Node* temp;
	temp=start;
	if(start==NULL){
		printf("List is Empty\n");
		return;
	}
	while(temp->next!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("%d\n", temp->data);
}
 void insertBeg(){
 	Node* newNode;
 	newNode=getNode();
 	if(start==NULL)start=newNode;
 	else {
 		newNode->next=start;
 		start=newNode;
 	}
 }
 //method to insert an item at end
 void insertEnd(){
 	Node* temp, *newNode;
 	newNode=getNode();
 	if(start==NULL)
 		start=newNode;
 	else{
 		temp=start;
 		while(temp->next!=NULL)
 			temp=temp->next;
 		temp->next=newNode;
 	}
 }
 //function to insert a node at given index
 void insertMid(){
 	Node *newNode, *temp, *prev;
 	int pos,ndectr,ctr=1;
 	newNode=getNode();
 	printf("Enter position:\n");
 	scanf("%d",&pos);
 	ndectr=countNode(start); //return number of nodes in list
 	if(pos>1 &&pos<ndectr){
 		temp=start;
 		prev=start;
 		while(ctr<pos){
 			prev=temp;
 			temp=temp->next;
 			ctr++;
 		}
 		prev->next=newNode;
 		newNode->next=temp;
 	}
 	else printf("Not in middle\n");
 }
 //function to count nodes from given node to end
 int countNode(Node * curr){
 	int ctr;
 	if(start==NULL)return 0;
 	else{
 		ctr=1;
 		while(curr->next!=NULL){
 			curr=curr->next;
 			ctr++;
 		}
 		return ctr;

 	}
 }
//function to delete the first element in the list
 void deleteBeg(){
 	Node *temp;
 	if(start==NULL)printf("List is empty\n");
 	else{
 		temp=start;
 		start=start->next;
 		free(temp);

 	}
 }
 //function to delete the last element in the list
 void deleteEnd(){
 	Node *temp, *prev;
 	if(start==NULL)printf("List is empty\n");
 	else{
 		temp=start;
 		prev=temp;
 		while(temp->next!=NULL){
 			prev=temp;
 			temp=temp->next;
 		}
 		prev->next=NULL;
 		free(temp);

 	}
 }

 void deleteMid(){
 	int ctr=1,pos,ndectr;
 	Node *temp,*prev;
 	if(start==NULL)printf("List is empty\n");
 	else{
 		printf("Enter position:\n");
 		scanf("%d",&pos);
 		ndectr=countNode(start);
 		if(pos>1 &&pos<ndectr){
 			temp=start;
 			prev=temp;
 			while(ctr<pos){
 				prev=temp;
 				temp=temp->next;
 				ctr++;
 			}
 			prev->next=temp->next;
 			free(temp);
 		
 		}
 		else printf("Position not in middle\n");

 	}
 }
