/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _GESTIONJUEGO_H_RPCGEN
#define _GESTIONJUEGO_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif

#define JMAXDAT 12

struct info_color {
	char color1[JMAXDAT];
	char color2[JMAXDAT];
	char color3[JMAXDAT];
	char color4[JMAXDAT];
	char color5[JMAXDAT];
	int generacion;
};
typedef struct info_color info_color;

struct info_espiga {
	char espiga1[JMAXDAT];
	char espiga2[JMAXDAT];
	char espiga3[JMAXDAT];
	char espiga4[JMAXDAT];
	char espiga5[JMAXDAT];
	int generacion;
};
typedef struct info_espiga info_espiga;

struct config_juego {
	int id_partida;
	int rol;
	int repetirColor;
	int estado;
};
typedef struct config_juego config_juego;

struct fin_juego {
	int id_partida;
	int id_ganador;
	int puntaje1;
	int puntaje2;
};
typedef struct fin_juego fin_juego;

struct data_juego {
	int id_juego;
	char fecha[JMAXDAT];
	int id_jugador1;
	int id_jugador2;
	int ganador;
};
typedef struct data_juego data_juego;

#define gestion_juego 0x30000014
#define gestion_juego_version 1

#if defined(__STDC__) || defined(__cplusplus)
#define iniciarJuego 1
extern  int * iniciarjuego_1(int *, CLIENT *);
extern  int * iniciarjuego_1_svc(int *, struct svc_req *);
#define enviarconfiguracion 2
extern  void * enviarconfiguracion_1(config_juego *, CLIENT *);
extern  void * enviarconfiguracion_1_svc(config_juego *, struct svc_req *);
#define configuracion 3
extern  config_juego * configuracion_1(void *, CLIENT *);
extern  config_juego * configuracion_1_svc(void *, struct svc_req *);
#define enviarColores 4
extern  bool_t * enviarcolores_1(info_color *, CLIENT *);
extern  bool_t * enviarcolores_1_svc(info_color *, struct svc_req *);
#define actualizarTableroColor 5
extern  info_color * actualizartablerocolor_1(int *, CLIENT *);
extern  info_color * actualizartablerocolor_1_svc(int *, struct svc_req *);
#define enviarEspigas 6
extern  bool_t * enviarespigas_1(info_espiga *, CLIENT *);
extern  bool_t * enviarespigas_1_svc(info_espiga *, struct svc_req *);
#define actualizarTableroEspiga 7
extern  info_espiga * actualizartableroespiga_1(int *, CLIENT *);
extern  info_espiga * actualizartableroespiga_1_svc(int *, struct svc_req *);
#define puntuacion 8
extern  fin_juego * puntuacion_1(int *, CLIENT *);
extern  fin_juego * puntuacion_1_svc(int *, struct svc_req *);
#define enviarConfirmacion 9
extern  void * enviarconfirmacion_1(int *, CLIENT *);
extern  void * enviarconfirmacion_1_svc(int *, struct svc_req *);
#define estadoJuego 10
extern  int * estadojuego_1(void *, CLIENT *);
extern  int * estadojuego_1_svc(void *, struct svc_req *);
#define consulta 11
extern  data_juego * consulta_1(int *, CLIENT *);
extern  data_juego * consulta_1_svc(int *, struct svc_req *);
extern int gestion_juego_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define iniciarJuego 1
extern  int * iniciarjuego_1();
extern  int * iniciarjuego_1_svc();
#define enviarconfiguracion 2
extern  void * enviarconfiguracion_1();
extern  void * enviarconfiguracion_1_svc();
#define configuracion 3
extern  config_juego * configuracion_1();
extern  config_juego * configuracion_1_svc();
#define enviarColores 4
extern  bool_t * enviarcolores_1();
extern  bool_t * enviarcolores_1_svc();
#define actualizarTableroColor 5
extern  info_color * actualizartablerocolor_1();
extern  info_color * actualizartablerocolor_1_svc();
#define enviarEspigas 6
extern  bool_t * enviarespigas_1();
extern  bool_t * enviarespigas_1_svc();
#define actualizarTableroEspiga 7
extern  info_espiga * actualizartableroespiga_1();
extern  info_espiga * actualizartableroespiga_1_svc();
#define puntuacion 8
extern  fin_juego * puntuacion_1();
extern  fin_juego * puntuacion_1_svc();
#define enviarConfirmacion 9
extern  void * enviarconfirmacion_1();
extern  void * enviarconfirmacion_1_svc();
#define estadoJuego 10
extern  int * estadojuego_1();
extern  int * estadojuego_1_svc();
#define consulta 11
extern  data_juego * consulta_1();
extern  data_juego * consulta_1_svc();
extern int gestion_juego_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_info_color (XDR *, info_color*);
extern  bool_t xdr_info_espiga (XDR *, info_espiga*);
extern  bool_t xdr_config_juego (XDR *, config_juego*);
extern  bool_t xdr_fin_juego (XDR *, fin_juego*);
extern  bool_t xdr_data_juego (XDR *, data_juego*);

#else /* K&R C */
extern bool_t xdr_info_color ();
extern bool_t xdr_info_espiga ();
extern bool_t xdr_config_juego ();
extern bool_t xdr_fin_juego ();
extern bool_t xdr_data_juego ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_GESTIONJUEGO_H_RPCGEN */
