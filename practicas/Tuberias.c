#include <stdio.h>
#include <stdlib.h>
int main()
{
	FILE *ps_pipe;
	FILE *grep_pipe;

	int bytes_read;
	int nbytes=100;
	char *my_string;
	/*Abrir dos tuberias*/
	ps_pipe=popen("ps -A", "r");
	grep_pipe=popen("grep init", "w");
	/*Revisar que la tuberia es non-null, antes de abrir*/
	if ((!ps_pipe) || (!grep_pipe))
	{
		fprintf(stderr, "Una o las dos tuberias fallaron en abrirse.\n");
		return EXIT_FAILURE; //exit (0); //para terminar la ejecucion elegantemente
	}
	/*Leer desde la ps_pipe hasta dos lineas*/
	my_string=(char *) malloc(nbytes + 1);
	bytes_read=getdelim(&my_string, &nbytes, "\n\n", ps_pipe);
	/*Cerrar las tuberias*/
	if (pclose(ps_pipe) != 0)
	       fprintf(stderr, "No se pudo corres 'ps', u otro error\n"	);
	/*Enviar salida de 'ps -A' hacia 'grep init', con dos nuevas lineas*/
	fprintf(grep_pipe, "%s\n\n", my_string);
	/*cerrar la tuberia grep_pipe*/
	if (pclose(grep_pipe)!=0)
		fprintf (stderr, "No se pudo ejecutar 'grep', u otro error.\n");
	/*Salir*/
	return 0;
}
			

