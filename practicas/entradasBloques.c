#include <stdio.h>
int main()
{
	int row, column;
	FILE *my_stream;
	int close_error;
	char my_filename[]="mis_numeros.dat";
	size_t object_size= sizeof(int);
	size_t object_count=25;
	size_t op_return;
	int my_array[5][5]=
	{
		2,   4,  6,  8, 10,
		12, 14, 16, 18, 20,
		22, 24, 26, 28, 30,
		32, 34, 36, 38, 40,
		42, 44, 44, 48, 50
	};
	printf("Initial values of array:\n");
	for (row=0; row <=4; row++)
	{
		for(column=0;column <=4; column++)
		{
			printf("%d  ", my_array[row][column]);
		}
		printf("\n");
	}
	my_stream =fopen(my_filename, "w");
	op_return =fwrite(&my_array, object_size, object_count, my_stream);
	if(op_return != object_count)
	{
		printf("Error escribiendo los datos al archivo.\n");
	}
	else
	{
		printf("Exitosamente escritos los datos al archivo\n");
	}
	/*Cerrar el flujo; evadiendo revision-errores para brevedad del ejemplo*/
	fclose(my_stream);
	printf("Arreglo a Zero default...\n");
	for (row=0; row <=4; row++)
	{
		for(column=0;column <=4; column++)
		{
			my_array[row][column]=0;
			printf("%d  ", my_array[row][column]);
			
		}
		printf("\n");
	}
	printf("Ahora leyendo los datos de regreso...\n");
	my_stream = fopen (my_filename, "r");
	op_return =fread(&my_array, object_size, object_count, my_stream); //sin evadir revision-errores
	if (op_return != object_count)
	{
		printf("Error leyendo información de archivo.\n");
	}
	else
	{
		printf("Exitosa lectura de la información del archivo.\n");
	}
	for (row=0; row <=4; row++)
	{
		for(column=0; column <=4; column++)
		{
			printf("%d   ", my_array[row][column]);
		}
		printf("\n");
	}
	/*Cerrando el flujo, con manejo de errrores*/
	if (fclose(my_stream) != 0)
		printf("Error al cerrrar el archivo...\n");
	else
		printf("Archivo cerrado exitosamente...\n");
	return 0;
}	
