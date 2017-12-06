#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};
void print_list(struct node *travel);
struct node* insert_node_position(struct node *travel,int new_data);


struct node* insert_node_front(struct node *travel,int new_data){
	
	struct node *new_node = (struct node*)malloc(sizeof(struct node));
	
	new_node->data = new_data;
	new_node->next = travel;
	travel= new_node;
	return travel;
	
	
	
}
struct node* insert_node_position(struct node *travel,int new_data){
	int position = 0,i=1;
	struct node *temp = travel;
	print_list(temp);
	printf("\nEnter the position: ");
	scanf("%d",&position);
	if(position == 1){
		return insert_node_front(temp,new_data);
	}
	while(i<(position-1)){
		temp = temp->next;
		++i;
	}
	struct node *new_node = (struct node*)malloc(sizeof(struct node));
	new_node->next = temp->next;
	temp->next = new_node;
	new_node->data = new_data;
	return travel;
	
	
	
}

struct node* insert_at_end(struct node *travel,int new_data){
	
	struct node *temp = travel;
	while(temp->next != NULL){
		temp = temp->next;
	}
	struct node *new_node = (struct node*)malloc(sizeof(struct node));
	temp->next = new_node;
	new_node->data = new_data;
	new_node->next = NULL;
	return travel;
	
	
	
	
	
}
void print_list(struct node *travel){
	struct node *temp = travel;
	while(temp != NULL){
		printf("\nThe data is :%d",temp->data);
		temp = temp->next;
	}
	printf("\n---------------------------");
}
int main(){
	
	struct node *head = NULL;
	
	
	print_list(head);
	printf("\nEnter your choice\n1.Insert at head\n2.Insert at position\n3.Insert at end\n4.Delete at front\n5.Delete at position\n6.Delete at end\n7.Display");
	head = insert_node_front(head,4);
	head = insert_node_front(head,5);
	head = insert_node_front(head,6);
	head = insert_node_position(head,100);
	head = insert_at_end(head,500);
	
	print_list(head);
	
	
	
	
	
	
	
	return 0;
}