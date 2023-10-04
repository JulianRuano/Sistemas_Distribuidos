/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "registroJuego.h"
//#include ofstream
//#include <std>
//#include FILENAME;
//#include <stdin>
#include <unistd.h>

struct datos_juego matriz[100];

void *
enviarnotificacion_1_svc(struct datos_juego *argp, struct svc_req *rqstp)
{
	static char * result;

	printf("*** Jugador con Id: %d y Jugador con Id: %d inician juego con Id:  %d ***", argp->id_jugador1, argp->id_jugador2, argp->id_juego );

	FILE *archivo;

	archivo = fopen("datos_juego.txt", "w");

	fprintf(archivo, "%d %s %d %d %d\n", argp->id_juego, argp->fecha, argp->id_jugador1, argp->id_jugador2, argp->ganador);

	fclose(archivo);

	return (void *) &result;
}

datos_juego *
historial_1_svc(int *argp, struct svc_req *rqstp)
{
	static datos_juego  result;

	FILE *archivo;
	int i = 1;
	int aux = 0;
	int bandera = 0;

	int id_jugador = *argp;

	archivo = fopen("datos_juego.txt", "r");

	while (fscanf(archivo, "%d %s %d %d %d\n", &matriz[i].id_juego, &matriz[i].fecha, &matriz[i].id_jugador1, &matriz[i].id_jugador2, &matriz[i].ganador) != EOF){
		i++;
	}

	fclose(archivo);

	for(i = 0; i < 100; i++){
		if(matriz[i].id_jugador1 == id_jugador || matriz[i].id_jugador2 == id_jugador){
			aux = i;
			bandera = 1;
			break;
		}
	}
	if (bandera == 0)
	{
		matriz[0].id_juego = -1;
		result = matriz[0];
	}
	else
	{
		result = matriz[aux];
	}
	
	return &result;
}
