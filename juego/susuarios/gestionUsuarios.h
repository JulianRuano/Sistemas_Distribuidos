/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _GESTIONUSUARIOS_H_RPCGEN
#define _GESTIONUSUARIOS_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif

#define MAXNOM 30
#define MAXDAT 12

struct datos_sesion {
	int id;
	char usuario[MAXDAT];
	char clave[MAXDAT];
};
typedef struct datos_sesion datos_sesion;

struct datos_usuario {
	int id;
	char nombreCompleto[MAXNOM];
	int edad;
	char usuario[MAXDAT];
	char clave[MAXDAT];
};
typedef struct datos_usuario datos_usuario;

#define gestion_usuarios 0x30000013
#define gestion_usuarios_version 1

#if defined(__STDC__) || defined(__cplusplus)
#define abrirSesion 1
extern  datos_usuario * abrirsesion_1(datos_sesion *, CLIENT *);
extern  datos_usuario * abrirsesion_1_svc(datos_sesion *, struct svc_req *);
#define registrarUsuarios 2
extern  bool_t * registrarusuarios_1(datos_usuario *, CLIENT *);
extern  bool_t * registrarusuarios_1_svc(datos_usuario *, struct svc_req *);
#define consultarUsuario 3
extern  datos_usuario * consultarusuario_1(int *, CLIENT *);
extern  datos_usuario * consultarusuario_1_svc(int *, struct svc_req *);
extern int gestion_usuarios_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define abrirSesion 1
extern  datos_usuario * abrirsesion_1();
extern  datos_usuario * abrirsesion_1_svc();
#define registrarUsuarios 2
extern  bool_t * registrarusuarios_1();
extern  bool_t * registrarusuarios_1_svc();
#define consultarUsuario 3
extern  datos_usuario * consultarusuario_1();
extern  datos_usuario * consultarusuario_1_svc();
extern int gestion_usuarios_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_datos_sesion (XDR *, datos_sesion*);
extern  bool_t xdr_datos_usuario (XDR *, datos_usuario*);

#else /* K&R C */
extern bool_t xdr_datos_sesion ();
extern bool_t xdr_datos_usuario ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_GESTIONUSUARIOS_H_RPCGEN */
