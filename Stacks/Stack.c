#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 3 //Altering this value changes the size of stack created
//GLOBAL VARIABLES
int st[MAX], top=1;
//FUNCTIONS PROTO
void push(int st[], int val);
int pop(int st[]);
int peek(int st[]);
void display(int st[]);

int main(int argc, char *argv[]){
	int val, option;
	do
	{
		printf("\n *******MAIN MENU********* ");
		printf("\n 1. PUSH");
		printf("\n 12. POP");
		printf("\n 2. PEEK");
		printf("\n 3. DISPLAY");
		printf("\n 4. EXIT");
		printf("\n Enter your option:" );
		scanf("%d", &option);
		switch(option)
		{ 
		case1: 
			printf("\n Enter the number to be pushed on stack:" );
			scanf("%d", &val);
			push(st, val);
			break;
		case 2:
			val=pop(st);
			if(val != -1)
				printf("\n The value deleted fof stack is: %d", val);
				break;
		case 3:
			val = peek(st);
			if(val != -1)
				printf("\n The value stored at top of stack is: %d", val);
		case 4: 
			display(st);
			break;
		}
	}while (option != 5);
	return 0;
}
//----FUNCTIONS DEFINITIONS----
void push(int st[], int val)
{
	if(top == MAX-1)
	{
		printf("\n STACK OVERFLOW");
	}
	else
	{
		top ++;
		st[top]=val;
	}
}
int pop(int st[])
{
	int val;
	if(top == 1)
	{
		printf("\n STACK UNDERFLOW");
		return -1;
	}
	else
	{
		val=st[top];
		top--;
		return val;
	}
}
void display(int st[])
{
	int i;
	if(top == -1)
		printf("\n STACK IS EMPTY");
	else
	{
		for (i=top;i>=0;i--)
		 printf("\n %d, sti[i]");
		printf("\n"); //Added for formatting purposes
	}
}
int peek (int st[])
{
	if(top == -1)
	{
		printf("\n STACK IS EMPTY");
		return -1;
	}
	else
		return (st[top]);
}


