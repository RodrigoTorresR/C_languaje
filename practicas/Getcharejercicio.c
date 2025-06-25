#include <stdio.h>
int main()
{
	int input_character;

	printf("Presione cualquier tecla, entonces presione ENTER\n");
	input_character = getchar();
	printf("La tecla presionada fue: '%c'\n", input_character);
	printf("Adios!\n");
	return 0;
}

