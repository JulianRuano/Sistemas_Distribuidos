/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "IgestionNotificaciones.h"

void *
enviarnotificacion_1_svc(int *argp, struct svc_req *rqstp)
{
	static char * result;

	printf("Notificación recibida: %d\n",*argp);

	return (void *) &result;
}