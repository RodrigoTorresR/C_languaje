#include <stdio.h>
#include <errno.h> //solo para sistemas GNU
int main()
{
	int my_integer = -42;
	unsigned int my_ui=23;
	float my_float=2.56;
	double my_double=424242.1717;
	char my_char='w';
	char my_string[]="Perdon, puedo tomar su nariz prestada?";

	FILE *my_stream;
	char my_filename[]="Fprintejemplo";
	my_stream = fopen(my_filename, "w");

	fprintf(my_stream, "Integer: %d\n", my_integer);
	fprintf(my_stream, "Usigned integer: %u\n", my_ui);
	fprintf(my_stream, "The same, as hexadecimal:  %#x %#x", my_integer, my_ui);
	fprintf(my_stream, "Floating-point: %f\n", my_float );
	fprintf(my_stream, "Double, exponential notation: %17.11e\n", my_double);
	fprintf(my_stream, "Single character: %c\n", my_char);
	fprintf(my_stream, "String: %s\n", my_string );
	/*Close stream; skip error-checking for brevety of example*/
	fclose(my_stream);
	return 0;
}

