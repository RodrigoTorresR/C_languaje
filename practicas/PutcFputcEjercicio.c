#include <stdio.h>
int main()
{
	int i;
	FILE *my_stream;
	char my_filename[]="PutcFputc";
	
	my_stream=fopen(my_filename,"w");

	putc('X', my_stream);
	putc(' ', my_stream);
	for(i=1; i<= 10; i++)
		putc('!', my_stream);
	putc('\n', my_stream);
	/*Cerrar el archivo*/
	if (fclose(my_stream) != 0)
		puts("Error al cerrar el archivo");
	else
		puts("Archivos cerrado correctamente");
	return 0;
}



