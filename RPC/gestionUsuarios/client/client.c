/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "gestionUsuarios.h"


void
gestion_usuarios_1(char *host)
{
	CLIENT *clnt;
	datos_usuario  *result_1;
	datos_sesion  abrirsesion_1_arg;
	bool_t  *result_2;
	datos_usuario  registrarusuarios_1_arg;
	datos_usuario  *result_3;
	int  consultarusuario_1_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, gestion_usuarios, gestion_usuarios_version, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

	int opcion;
	int opcion_admin;
	do{
		printf("\n================ Menu sesion ==================");
		printf("\n1. Abrir sesion");
		printf("\n2. Salir");
		printf("\n================ Menu sesion ==================");
		printf("\nDigite una opcion: ");
		scanf(" %d", &opcion);

		switch (opcion)
		{
		case 1:
			printf("\nDigite usuario: ");
			scanf(" %s", abrirsesion_1_arg.usuario);
			printf("\nDigite su contrasena: ");
			scanf(" %s", abrirsesion_1_arg.clave);

			result_1 = abrirsesion_1(&abrirsesion_1_arg, clnt);
			if (result_1 == (datos_usuario *) NULL) {
				clnt_perror (clnt, "call failed");
			}
			else if (strcmp(result_1->usuario, abrirsesion_1_arg.usuario) == 0)
			{

				printf("\n================ Bienvenido ==================");
				printf("\n|%s|", result_1->nombreCompleto);

				do
				{
					printf("\n================ Menu Admin ==================");
					printf("\n1. Registrar usuarios");
					printf("\n2. Consultar usuario");
					printf("\n3. Salir");
					printf("\n==============================================");

					printf("\nDigite una opcion: ");
					scanf("%d", &opcion_admin);

					switch (opcion_admin)
					{
						case 1:
							printf("\nDigite la identificacion: ");
							scanf(" %d", &registrarusuarios_1_arg.id);
							printf("\nDigite el nombre completo: ");
							scanf(" %s", registrarusuarios_1_arg.nombreCompleto);
							printf("\nEdad: ");
							scanf(" %d", &registrarusuarios_1_arg.edad);
							printf("\nDigite usuario: ");
							scanf(" %s", registrarusuarios_1_arg.usuario);
							printf("\nDigite la contrasena: ");
							scanf(" %s", registrarusuarios_1_arg.clave);
							
							result_2 = registrarusuarios_1(&registrarusuarios_1_arg, clnt);
							if (result_2 == (bool_t *) NULL) {
								clnt_perror (clnt, "call failed");
							}
							else if (*result_2 == TRUE)
							{
								printf("\n** Usuario registrado exitosamente **");
							}
							else
							{
								printf("\n** Usuario NO registrado, se alcanzo la cantidad maxima de usuarios a registrar **");
							}
							break;
						
						case 2:
							printf("\nDigite la identificacion: ");
							scanf(" %d", &consultarusuario_1_arg);

							result_3 = consultarusuario_1(&consultarusuario_1_arg, clnt);
							if (result_3 == (datos_usuario *) NULL) {
								clnt_perror (clnt, "call failed");
							}
							else if (result_3->id >= 0)
							{
								printf("\n================ Usuario ==================");
								printf("\nIdentificacion: %d", result_3->id);
								printf("\nNombre completo: %s", result_3->nombreCompleto);
								printf("\nUsuario: %s", result_3->usuario);
								printf("\n===========================================");
							}
							else
							{
								printf("\n** Usuario NO encontrado **");
							}
							break;

					}
				} while (opcion_admin != 3);			
			break;
		case 2: 
			printf("\n================ Hasta luego ==================");
			break;
		
		default:
			break;
		}

		}
	}while(opcion != 2);


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
	gestion_usuarios_1 (host);
exit (0);
}
