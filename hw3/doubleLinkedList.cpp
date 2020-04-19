/*doubly linked list with main function for adding to begining and deleting from end
*/
#include <iostream>
typedef struct doubleLinkedList{
	int data;
	struct doubleLinkedList *next;
	struct doubleLinkedList *prev;
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
	printf("(testing insertAtBeg)\n");
	insertBeg();
	printList();
	/*printf("(testing insertAtEnd)\n");
	insertEnd();
	printList();
	printf("(testing countNodes)\n %d\n",countNode(start));
	printf("(testing insertAtMiddle)\n");
	insertMid();
	printList();
	printf("(testing deleteAtBeg)\n");
	deleteBeg();
	printList();*/
	printf("(testing deleteAtEnd)\n");
	deleteEnd();
	printList();
	/*printf("(testing deleteAtMid)\n");
	deleteMid();
	printList();*/


}
	//method to create and return a new item
Node* getNode(){
	Node* newNode;
	newNode=(Node *)malloc(sizeof(Node));
	printf("Enter data\n");
	scanf("%d",&(newNode->data));
	newNode->next=NULL;
	newNode->prev=NULL;
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
			newNode->prev=temp;
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
 		start->prev=newNode;
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
 		newNode->prev=temp;
 	}
 }
 //function to insert a node at given index
 void insertMid(){
 	Node *newNode, *temp;
 	int pos,ndectr,ctr=1;
 	newNode=getNode();
 	printf("Enter position:\n");
 	scanf("%d",&pos);
 	ndectr=countNode(start); //return number of nodes in list
 	if(pos>1 &&pos<ndectr){
 		temp=start;
 		while(ctr<pos){
 			temp=temp->next;
 			ctr++;
 		}
 		newNode->next=temp;
 		newNode->prev=temp->prev;
 		temp->prev->next=newNode;
 		temp->prev=newNode;
 		
 		
 		
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
 		start->next->prev=NULL;
 		start=start->next;
 		free(temp);

 	}
 }
 //function to delete the last element in the list
 void deleteEnd(){
 	Node *temp;
 	if(start==NULL)printf("List is empty\n");
 	else{
 		temp=start;
 		
 		while(temp->next!=NULL){
 			temp=temp->next;
 		}
 		temp->prev->next=NULL;
 		free(temp);

 	}
 }

 void deleteMid(){
 	int ctr=1,pos,ndectr;
 	Node *temp;
 	if(start==NULL)printf("List is empty\n");
 	else{
 		printf("Enter position:\n");
 		scanf("%d",&pos);
 		ndectr=countNode(start);
 		if(pos>1 &&pos<ndectr){
 			temp=start;
 			
 			while(ctr<pos){
 				temp=temp->next;
 				ctr++;
 			}
 			temp->prev->next=temp->next;
 			temp->next->prev=temp->prev;
 			free(temp);
 		
 		}
 		else printf("Position not in middle\n");

 	}
 }
