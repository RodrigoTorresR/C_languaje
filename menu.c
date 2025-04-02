#include <stdio.h>
char *menu[]=
{
	"--------------------------------",
	"|	++ MENU ++		|",
	"|  (0) Edit Preferences	|",
	"|  (1) Print Change Sheet	|",
	"|  (2) Print Log Sheet		|",
	"|  (3) Calculate Bill		|",
	"|				|",
	"|  (q) Quit			|",
	"|  Pllease enter choice below  |",
	"|				|",
	"--------------------------------"
};
int main()
{
	int line_num;
	for (line_num=0; line_num < 13; line_num++)
	{
		printf("%s\n", menu[line_num]);
	}
	return 0;
}

