#include <stdio.h>

int main()
{
	FILE *my_stream;
	char my_filename[]="FuncionFputs";
	int flush_status;

	my_stream=fopen(my_filename, "w");
	fputs ("Si noes muy tarde... prepara una hamburguesa\n", my_stream); //necesitamos agregar el caracter de fin de linea
	/*Desde que stream es cumplemante-bufferada por default, no linea-buffereada, 
	 * es necesaria para ser flushed(vaciada) peridocamente. Nosotros la flushearemos aqui para
	 * propositos de demostración, aun que nosotros estamos por cerrar el flujo.
	*/
	flush_status = fflush(my_stream);
	if (flush_status != 0 )
		puts ("Error al flushear el flujo!");
	else
		puts("Flujo a sido \"fluseado\" ");
	/*Cerramos el stream, con revision de errores*/
	if (fclose(my_stream) != 0)
		puts("Error al cerrar el archivo"); //no requiere \n ya que la instruccion la agrega
	else
		puts("El archivo fue cerrado correctamente");//nuevamente enfatizamos que no es necesario agregar \n
	puts("pust() no require que coloquemos \n (salto de linea)");							     		
	return 0;
}

