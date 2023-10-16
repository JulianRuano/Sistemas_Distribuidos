/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "gestionAnteproyectos.h"


void
gestion_anteproyectos_1(char *host)
{
	CLIENT *clnt;
	bool_t  *result_1;
//  nodo_anteproyecto  registraranteproyectosistema_1_arg;
	nodo_anteproyecto objAnteproyecto;
	nodo_anteproyecto  *result_2;
	char * titulo;

#ifndef	DEBUG
	clnt = clnt_create (host, gestion_anteproyectos, gestion_anteproyectos_version, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

	int opcion;
	do
	{
		printf("\n================ Menu ==================");
		printf("\n 1. Registrar anteproyecto ");
		printf("\n 2. Consultar anteproyecto ");
		printf("\n 3. Salir ");
		printf("\n=======================================");
		printf("\n Digite opcion: ");
		scanf("%d",&opcion);
		switch(opcion)
		{    
			case 1:
				printf("Digite el titulo: ");
				scanf("%s",objAnteproyecto.titulo);
				printf("Digite el nombre del estudiante: ");
				scanf("%s",objAnteproyecto.estudiante);
				printf("\n Digite el codigo inicial del anteproyecto: ");				
				scanf("%d",&objAnteproyecto.codigo);
	
				result_1=registraranteproyectosistema_1(&objAnteproyecto,clnt);
				if(result_1 == (bool_t *)NULL)
				{
				  clnt_perror(clnt,"call failed");
				}
				else if(*result_1==TRUE)
				{
				  printf("Anteproyecto registrado exitosamente\n");
				}
				else
				{
				  printf("\n Anteproyecto no registrado");
				}
				break;

			case 2:
				printf("\n Consultar Anteproyecto");
				titulo=(char*)malloc(sizeof(char)*20);
				printf("\nDigite el titulo del anteproyecto:");
				scanf("%s",titulo);
				result_2=consultaranteproyecto_1(&titulo,clnt);
				if ((*result_2).codigo == -1) 
				{	
				  printf("\nNo existe anteproyecto");
				}
				else
				{
				  printf("\nTitulo: %s",(*result_2).titulo);
				  printf("\nNombre estudiante: %s",(*result_2).estudiante);
				  printf("\nCodigo del proyecto: %d",(*result_2).codigo);
				}
				break;

			case 3:
				exit(1);
				break;
		
			default:
				printf("Opcion invalida\n");
				break;				
		}
	}while(opcion < 3);


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
	gestion_anteproyectos_1 (host);
exit (0);
}