#include <stdio.h>
#include <conio.h>
#include <malloc.h>
struct node
{
	int data;	//for this case is only a single value but it could be a struct data too
	struct node *next;//pointer to the next struct node 
};
struct node *start = NULL;//the first node of the singl circular linked list

struct node *create_cll(struct node *); //function to create the list, returns the pointer to a node
					//requires as parameter a pointer to struct type node
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_after(struct node *);
struct node *delete_list(struct node *);

void menu()
{
	int Maxim=10;
	int line_num=0;
	char *Menu[]={
		"++++MAIN MENU++++",
		"\n 1: Create a list",
		"\n 2: Display the list",
		"\n 3: Add a node at the begining",
		"\n 4: Add a node at the end",
		"\n 5: Delete a node from the beginning",
		"\n 6: Delete a node from the end",
		"\n 7: Delete a node after a given node",
		"\n 8: Delete the entire list",
		"\n 9: EXIT"
	};
	for (line_num; line_num < Maxim; line_num++)
	{
		printf("%s", Menu[line_num]);
	}	
}

int main()
{
	int option;
	//clrscr();
	do
	{

		menu();	//to better readbility we use a function to print the menu
		printf("\n\n Enter your option :");
		scanf("%d", &option);
		switch(option)
		{//start is a pointer to sctruct type node
			case 1: start = create_cll(start);
				printf("\n CIRCULAR LINKED LIST CREATED");
				break;
			case 2: start = display(start);
				break;
			case 3: start = insert_beg(start);
				break;
			case 4: start = insert_end(start);
				break;
			case 5: start = delete_beg(start);
				break;
			case 6: start = delete_end(start);
				break;
			case 7: start = delete_after(start);
				break;
			case 8: start = delete_list(start);
				break;		
			default: printf("\n ");
		}

	}while (option !=9);
	getch();
	return 0;
}
struct node *create_cll(struct node *start)
{
	struct node *new_node, *ptr;
	int num;
	printf("\n Enter -1 to end");
	printf("\n Enter the data : ");
	scanf("%d", &num);
	while (num!=-1)
	{
		new_node = (struct node*)malloc(sizeof(struct node));
		new_node -> data = num;
		if (start == NULL) //calling the function with an empty list creates a new list
		{
			new_node -> next = new_node;
			start = new_node;
		}
		else //calling the function with elements in the list add new element before to the final node
		{
			ptr = start;
			while (ptr -> next != start)	//this requires walktrought all the list we stop one node before start node
				ptr = ptr -> next;
			ptr -> next = new_node;
			new_node -> next = start;
		}
		printf("\n Enter the data : "); //as we stop one node before start node, we have to show the content of the node
		scanf("%d", &num);
	}
	return start;
			
}
struct node *display(struct node *start)
{
	struct node *ptr;
	ptr = start;
	while(ptr -> next != start)
	{
		printf("\t %d", ptr -> data);
		ptr = ptr -> next;
	}
	printf("\t %d", ptr -> data);
	return start;
}
struct node *insert_beg(struct node *start)
{
	struct node *new_node, *ptr;
	int num;
	printf("\n Enter the data : ");
	scanf("%d", &num);
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node -> data = num;
	ptr = start;
	while(ptr -> next != start)
		ptr = ptr -> next;
	ptr -> next = new_node;
	new_node -> next = start;
	start = new_node;
	return start;
}
struct node *insert_end(struct node *start)
{
	struct node *ptr, *new_node;
	int num;
	printf("\n Enter the data : ");
	scanf("%d", &num);
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node -> data = num;
	ptr = start;
	while(ptr -> next != start)
		ptr = ptr -> next;
	ptr -> next = new_node;
	new_node -> next = start;
	return start;
}
struct node *delete_beg(struct node *start)
{
	struct node *ptr;
	ptr = start;
	while(ptr -> next != start)
		ptr = ptr -> next;
	ptr -> next = start -> next;
	free(start);			//IMPORTANT we have to free the memory to avoid memory leaks problems
	start = ptr -> next;
	return start;
}
struct node *delete_end(struct node *start)
{
	struct node *ptr, *preptr;
	ptr = start;
	while(ptr -> next != start)
	{
		preptr = ptr;
		ptr = ptr -> next;
	}
	preptr -> next = ptr -> next;
	free (ptr);		//IMPORTANT we have free the memory of ptr this erase the pointer
	return start;
}
struct node *delete_after(struct node *start)
{
	struct node *ptr, *preptr;
	int val;
	printf("\n Enter the value after wich the node has to deleted : ");
	scanf("%d", &val);
	ptr = start;
	preptr = ptr;
	while(preptr -> data != val) //NOTE: the loop don´t take the case if there is not find the node
	{
		preptr = ptr;
		ptr = ptr -> next;
	}
	preptr -> next = ptr -> next;
	if (ptr == start)
		start = preptr -> next;
	free(ptr);
	return start;
}
struct node *delete_list(struct node *start)
{
	struct node *ptr;
	ptr = start;
	while(ptr -> next != start)
		start = delete_end(start);
	free(start);
	return start;
}

