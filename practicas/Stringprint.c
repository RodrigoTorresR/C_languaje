//-D_GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
int main()
{
	char *my_string;
	/*my_string es una variable char **, asi usamos:
	 *  asprintf(&char **, "String a copiar %d (caracteres de escape)", variables o constantes )
	 *  note que puede ser util para escribir una cadena en una variable cadena que no ha sido
	 *  previamente inicializada
	 *  NOTA LA FUNCION ASPRINTF NO ESTA DISPONIBLE EN WINDOWS
	 */
	asprintf(&my_string, "being %d is cool, but being free is best of all", 4);
	puts(my_string);
	return 0;
}
