/*Write a program to create a linked list and perform insertions and deletions of all cases
 * write functions to sort and finally delete the entire lita at once
 */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
//We create a struc to save the Node data
struct node
{
	int data;		//Node data, it could be to another struct
	struct node *next;	//Pointer to chain the nodes
};
struct node *start=NULL; //Heaad Node, this is the begining of the linked list
//---PROTOTIPES OF THE FUNCITIONS			
struct node *create_ll(struct node *);//Function to create the linked list structure returns a node pointer struct
				      //and requires a node pointer struct as parameter
struct node *display(struct node *);//Return a Node Pointer Struct Required a Node Pointer Struct
				   //Show the contents of the List (nodes)
	//Insertion functions				   
struct node *insert_beg(struct node *);//insert a Node at the beginin of the LL
struct node *insert_end(struct node *);//insert a node at the endo of the LL
struct node *insert_before(struct node *);//insert a node at the before the actual node of the LL
struct node *insert_after(struct node *);//insert a node at the after the actual node of the LL
	//Deletion functions
struct node *delete_beg(struct node *);//delete a node at the begin of the LL
struct node *delete_end(struct node *);//delete a node at the end of the LL
struct node *delete_node(struct node *);//delete the actual node 
struct node *delete_before(struct node *);//delete a node before the actual node
struct node *delete_after(struct node *);//delete a node after the actual node
struct node *delete_list(struct node *);//deletes all the nodes
struct node *sort_list(struct node *);//sort the nodes on the LL
				      
int main()
{
	int option;
	do
	{
		printf("\n\n****MAIN MENU****");
		printf("\n 1: Create a List");
		printf("\n 2: Display the list");
		printf("\n 3: Add a node at the begining");
		printf("\n 4: Add a node at the end");
		printf("\n 5: Add a node before a given node");
		printf("\n 6: Add a node after a given node");
		printf("\n 7: Delete a node from the beginning");
		printf("\n 8: Delete a node from the end");
		printf("\n 9: Delete a given node");
		printf("\n 10: Delete a node after a given node");
		printf("\n 11: Delete the entire list");
		printf("\n 12: Sort the list");
		printf("\n 13: EXIT");
		printf("\n \n Enter your option : ");
		scanf("%d", &option);
		switch(option)
		{
		case 1: start = create_ll(start);
			printf("\n LINKED LIST CREATED");
			break;
		case 2: start = display(start);

			break;
		case 3: start = insert_beg(start);
			break;
		case 4: start = insert_end(start);
			break;
		case 5: start = insert_before(start);
			break;
		case 6: start = insert_after(start);
			break;
		case 7: start = delete_beg(start);
			break;
		case 8: start = delete_end(start);
			break;
		case 9: start = delete_node(start);
			break;
		case 10: start = delete_after(start);
			 break;
		case 11: start = delete_list(start);
			 printf("'n LINKED LIST DELETED");
			 break;
		case 12: start = sort_list(start);
			 break;
		}
	}while (option !=13);
	getch();
	return 0;
}
//DEFINITIONS OF THE FUNCTIONS
struct node *create_ll(struct node *start)
{
	struct node *new_node, *ptr;
	int num;
	printf("\n Enter -1 to end");
	printf("\n enter the data : ");
	scanf("%d", &num);
	while(num!=-1)
	{
		new_node=(struct node*)malloc(sizeof(struct node));
		new_node->data=num;
		if(start==NULL)
		{
			new_node->next=NULL;
			start=new_node;
		}
		else
		{
			ptr=start;
			while(ptr->next!=NULL)
				ptr=ptr->next;
			ptr->next=new_node;
			new_node->next=NULL;
		}
		printf("\n Enter the data");
		scanf("%d", &num);
	}
	return start;
}
struct node *display(struct node *start)
{
	struct node *ptr;
	ptr=start;
	while(ptr!=NULL)
	{
		printf("\t %d", ptr -> data);
		ptr=ptr->next; //next es una variable apuntador a una estructura de tipo nodo		
	}
	return start;
}
struct node *insert_beg(struct node *start)
{
	struct node *new_node;
	int num;
	printf("\n Enter the data");
	scanf("%d", &num);
	new_node=(struct node *)malloc(sizeof(struct node));
	new_node-> data=num;
	new_node->next=start;
	start=new_node;
	return start;
}
struct node *insert_end(struct node *start)
{
	struct node *ptr, *new_node;
	int num;
	printf("\n Enter the data: ");
	scanf("%d", &num);
	new_node=(struct node *)malloc(sizeof(struct node));
	new_node->data=num;
	new_node->next=NULL;
	ptr=start;
	while(ptr->next != NULL)
		ptr=ptr->next;
	ptr->next=new_node;
	return start;
}
struct node *insert_before(struct node *start)
{
	struct node *new_node, *ptr, *preptr;
	int num, val;
	printf("\n Enter the data : ");
	scanf("%d", &num);
	printf("\n Enter the value before wich the data has to be inserted : ");
	scanf("%d", &val);
	new_node=(struct node *)malloc(sizeof(struct node));
	new_node->data=num;
	ptr=start;
	while(ptr->data != val) //&& ptr->next != NULL
	{//what happend if we reach the end of the list and we can´t find the value?
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr ->next =new_node;
	new_node-> next=ptr;
	return start;
}
struct node *insert_after(struct node *start)
{
	struct node *new_node, *ptr, *preptr;
	int num,val;
	printf("\n Enter the data : ");
	scanf("%d", &num);
	printf("\n Enter the value after wich the data has to be inserted : ");
	scanf("%d", &val);
	new_node=(struct node *)malloc(sizeof(struct node));
	new_node->data=num;
	ptr=start;
	preptr=ptr;
	while (preptr -> data != val)
	{//what happend if we reach the end of the list and we can´t find the value?
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=new_node;
	new_node ->next=ptr;
	return start;
}
struct node *delete_beg(struct node *start)
{
	struct node *ptr;
	ptr = start;
	start=start ->next;
	free(ptr); //we have to erase each node in the list
	return start;
}
struct node *delete_end(struct node *start)
{
	struct node *ptr, *preptr;
	ptr=start;
	while(ptr->next != NULL)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=NULL;
	free(ptr);
	return start;
}
struct node *delete_node(struct node *start)
{
	struct node *ptr, *preptr;
	int val;
	printf("\n Enter the value of the node wich has to be deleted : ");
	scanf("%d", &val);
	ptr=start;
	if (ptr->data == val)
	{
		start = delete_beg(start);
		return start;
	}
	else
	{
		while(ptr-> data !=val)
		{
			preptr=ptr;
			ptr=ptr->next;
		}
		preptr->next=ptr->next;
		free(ptr);
		return start;
	}
}
struct node *delete_after(struct node *start)
{
	struct node *ptr, *preptr;
	int val;
	printf("\n Enter the value after wich the node has to deleted : ");
	scanf("%d", &val);
	ptr=start;
	preptr=ptr;
	while(preptr->data!=val)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=ptr->next;
	free(ptr);
	return start;
}
struct node *delete_list(struct node *start)
{
	struct node *ptr; //lines 252-254 were mofified from orignial code to fix unresponsiveness in ouput window
	if(start!=NULL){
		ptr=start;
		ptr=start;
		while(ptr!=NULL)
		{
			printf("\n %d is to be deleted next", ptr->data);
			start=delete_beg(ptr);
			ptr=start;
		}
	}
	return start;
}
struct node *sort_list(struct node *start)
{
	struct node *ptr1, *ptr2;
	int temp;
	ptr1=start;
	while(ptr1->next != NULL)
	{
		ptr2=ptr1->next;
		while(ptr2 != NULL)
		{
			if (ptr1->data > ptr2->data)
			{
				temp =ptr1->data;
				ptr1->data=ptr2->data;
				ptr2->data=temp;
			}
			ptr2=ptr1->next;
		}
	}
	return start; //had to be added
}
