/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "IgestionIndicadores.h"


void
ges1program_1(char *host)
{
	CLIENT *clnt;
	void  *result_1;
	int  enviarindicador_1_arg;
	int op;

#ifndef	DEBUG
	clnt = clnt_create (host, GES1PROGRAM, GES1VER, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

	do{	
		printf("Ingrese indicador:");
		scanf("%d",& enviarindicador_1_arg);
		result_1 = enviarindicador_1(&enviarindicador_1_arg, clnt);
		if (result_1 == (void *) NULL) {
			clnt_perror (clnt, "call failed");
		}
		printf("Desea salir? ingrese Si=1, No=0: ");
		scanf("%d",&op);
		printf("\n");	
	}while(op==0);
	printf("Saliendo...\n");
	
	

	result_1 = enviarindicador_1(&enviarindicador_1_arg, clnt);
	if (result_1 == (void *) NULL) {
		clnt_perror (clnt, "call failed");
	}
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	ges1program_1 (host);
exit (0);
}
