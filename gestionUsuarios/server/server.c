/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "gestionUsuarios.h"


datos_usuario vectorUsuarios[5]; 
datos_usuario *
abrirsesion_1_svc(datos_sesion *argp, struct svc_req *rqstp)
{
	static datos_usuario  result;

	vectorUsuarios[0].id = 0;
    strcpy(vectorUsuarios[0].nombreCompleto, "Julian Ruano");
    vectorUsuarios[0].edad = 30;
    strcpy(vectorUsuarios[0].usuario, "admin");
    strcpy(vectorUsuarios[0].clave, "1234");

	printf("\n ** abrir sesion **\n");

	if (strcmp(argp->usuario, vectorUsuarios[0].usuario) == 0 && strcmp(argp->clave, vectorUsuarios[0].clave) == 0) {
		result = vectorUsuarios[0];
		printf("\n ** Sesion iniciada con exito **\n");
	} else {
		printf("\n ** Error al iniciar sesion **\n");		
	}

	return &result;
}

bool_t *
registrarusuarios_1_svc(datos_usuario *argp, struct svc_req *rqstp)
{
	static bool_t  result;

	/*
	 * insert server code here
	 */

	return &result;
}

datos_usuario *
consultarusuario_1_svc(int *argp, struct svc_req *rqstp)
{
	static datos_usuario  result;

	/*
	 * insert server code here
	 */

	return &result;
}