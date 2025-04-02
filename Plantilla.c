#include <stdio.h>
#include <conio.h>
#include <malloc.h>
struct node
{
	int data;	//for this case is only a single value but it could be a struct data too
	struct node *next;//pointer to the next struct node 
};
struct node *start = NULL;//the first node of the singl circular linked list
/*
struct node *create_cll(struct node *); //function to create the list, returns the pointer to a node
					//requires as parameter a pointer to struct type node
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_after(struct node *);
struct node *delete_list(struct node *);
*/
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
	menu();	//to better readbility we use a function to print the menu
	printf("\n\n Enter your option :");
	scanf("%d", &option);
	switch(option)
	{
		case 1: printf("\n Case 1");
			break;
		default: printf("\n No existe esa opción intente nuevamente");
	}

	
	return 0;
}

