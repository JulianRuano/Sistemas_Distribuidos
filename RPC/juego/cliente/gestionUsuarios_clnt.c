/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include <memory.h> /* for memset */
#include "gestionUsuarios.h"

/* Default timeout can be changed using clnt_control() */
static struct timeval TIMEOUT = { 25, 0 };

datos_usuario *
abrirsesion_1(datos_sesion *argp, CLIENT *clnt)
{
	static datos_usuario clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, abrirSesion,
		(xdrproc_t) xdr_datos_sesion, (caddr_t) argp,
		(xdrproc_t) xdr_datos_usuario, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

bool_t *
registrarusuarios_1(datos_usuario *argp, CLIENT *clnt)
{
	static bool_t clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, registrarUsuarios,
		(xdrproc_t) xdr_datos_usuario, (caddr_t) argp,
		(xdrproc_t) xdr_bool, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

datos_usuario *
consultarusuario_1(int *argp, CLIENT *clnt)
{
	static datos_usuario clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, consultarUsuario,
		(xdrproc_t) xdr_int, (caddr_t) argp,
		(xdrproc_t) xdr_datos_usuario, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}
