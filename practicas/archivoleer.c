#include <stdio.h>

int main()
{
	FILE *my_stream;

	my_stream = fopen ("Test", "r");
	if (my_stream == NULL)
	{
		printf("Archivo no puede ser abierto\n");
	}
	else
	{
		printf("Archivo abierto!, Cerrandolo a hora...\n");
		/*Cerrar el stream; evadiendo la revision-errores para brevidad del ejemplo*/
		printf("Valor devuelto por fclose %d \n", fclose(my_stream));
	}
	return 0;
}

