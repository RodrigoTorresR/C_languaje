#include <stdio.h>
#include <errno.h>
int main()
{
	int my_integer=-42;
	unsigned int my_ui=23;
	float my_float=3.56;
	double my_double=424242.171717;
	char my_char='w';
	char my_string[]="Perdoneme, puedo tomar prestada su nariz?";

	printf("Entero: %d\n", my_integer);
	printf("EnterroNoSigno: %u\n", my_ui);

	printf("Lo mismo, como hexadecimal: %#x %#x\n", my_integer, my_ui);

	printf("Punto-Flotante: %f\n", my_float);
	printf("Doble, Notación exponencial: %17.11\n", my_double);

	printf("Single characterr: %c\n", my_char);
	printf("String: %s\n", my_string);

	errno = EACCES;
	printf("errno string (EACCES): %m\n"); //Unicamente para sitemas GNU
	
	return 0;
}
