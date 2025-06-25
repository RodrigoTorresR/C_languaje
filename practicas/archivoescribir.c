#include <stdio.h>

int main()
{
	FILE *my_stream;
	char my_filename[]="Test2";
	int close_error;

	my_stream = fopen(my_filename, "w"); //se usa wx para no sobreescribir un archivo
	fprintf(my_stream, "Solo hola desde fprintf\n");
	
	close_error=fclose(my_stream);	//guardamos el valor devuelto al cerrar el archivo
	if (close_error !=0)
	{
		printf("Archivo  no pudo ser cerrado\n");
	}
	else
	{
		printf("Archivo cerrado con exito\n");
	}
	return 0;	
}
