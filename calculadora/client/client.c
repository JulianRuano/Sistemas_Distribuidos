/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "calculadora.h"


void
calculadora_1(char *host)
{
	CLIENT *clnt;
	float  *result_1;
	numbers  suma_1_arg;
	float  *result_2;
	numbers  resta_1_arg;
	float  *result_3;
	numbers  multiplicacion_1_arg;
	float  *result_4;
	numbers  division_1_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, calculadora, calculadora_version, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */


	int opcion;
	do
	{
		printf("\n================ Menu ==================");
		printf("\n 1. Suma ");
		printf("\n 2. Resta ");
		printf("\n 3. Multiplicacion ");
		printf("\n 4. Division ");
		printf("\n 5. Salir ");
		printf("\n=======================================");
		printf("\n Digite opcion: ");
		scanf("%d",&opcion);
		switch(opcion)
		{    
			case 1:
				printf("Digite el primer numero: ");
				scanf("%f", &suma_1_arg.a);
				printf("Digite el segundo numero: ");
				scanf("%f", &suma_1_arg.b);

				result_1 = suma_1(&suma_1_arg, clnt);
				if (result_1 == (float *) NULL) {
					clnt_perror (clnt, "call failed");
				}
				else
				{
				  printf("\nSuma: %f\n",(*result_1));
				}
				
				break;

			case 2:
				printf("Digite el primer numero: ");
				scanf("%f",&resta_1_arg.a);
				printf("Digite el segundo numero: ");
				scanf("%f",&resta_1_arg.b);

				result_2 = resta_1(&resta_1_arg, clnt);
				if (result_2 == (float *) NULL) {
					clnt_perror (clnt, "call failed");
				}
				else
				{
				  printf("\nResta: %f\n",(*result_2));
				}
				break;
			
			case 3:
				printf("Digite el primer numero: ");
				scanf("%f",&multiplicacion_1_arg.a);
				printf("Digite el segundo numero: ");
				scanf("%f",&multiplicacion_1_arg.b);

				result_3 = multiplicacion_1(&multiplicacion_1_arg, clnt);
				if (result_3 == (float *) NULL) {
					clnt_perror (clnt, "call failed");
				}
				else
				{
				  printf("\nMultiplicacion: %f\n",(*result_3));
				}
				break;

			case 5:
				exit(1);
				break;
		
			default:
				printf("Opcion invalida\n");
				break;				
		}
	}while(opcion < 5);

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
	calculadora_1 (host);
exit (0);
}
