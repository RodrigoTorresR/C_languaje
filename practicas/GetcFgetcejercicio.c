#include <stdio.h>
int main()
{
	int input_char;
	FILE *my_stream;
	char my_filename[] = "GetcFgetcejercicio";
	long position;
	int eof_status, error_status, close_error;
	my_stream=fopen(my_filename, "w");
	fprintf(my_stream, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	/*Cerrar el archivo*/
	if(fclose(my_stream)!=0)
		puts("Error al cerrar archivo");
	else
		puts("Archivo cerrado correctamente");

	printf("Abriendo el archvio...\n");
	my_stream=fopen(my_filename,"r");
	position=ftell(my_stream);
	input_char=getc(my_stream);
	printf("Caracter en la posicion %d = '%c'.\n\n", position, input_char);
	printf("Seeking position 25...\n");
	fseek(my_stream, 25, SEEK_SET);
	position=ftell(my_stream);
	input_char=getc(my_stream);
	printf("Caracter en la posicion %d = '%c',\n\n", position, input_char);
	printf("Intentando leer otra vez...\n");
	input_char=getc(my_stream);
	eof_status=feof(my_stream);
	printf("FEOF regresa %d. \n\n", eof_status);
	error_status=ferror(my_stream);
	printf("FERROR regresa %d.\n", error_status);
	printf("Intentando escribir en Archivo Solo-lectura...\n");
	putc('!', my_stream);
	error_status=ferror(my_stream);
	printf("FERROR regreso %d.\n\n", error_status);

	printf("Rebobinando..\n");
	position = ftell (my_stream);
	input_char=getc(my_stream);
	printf("Character at position %d = '%c'.\n", position, input_char);
	close_error=fclose(my_stream);
	/*Manejador de errores para fclose*/
	if (close_error != 0)
		printf("File could not be closed.\n");
	else
		printf("File closed.\n");
	return 0;
}

