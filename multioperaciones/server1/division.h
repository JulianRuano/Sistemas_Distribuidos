/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _DIVISION_H_RPCGEN
#define _DIVISION_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


struct num {
	float a;
	float b;
};
typedef struct num num;

#define division 0x30000002
#define division_version 1

#if defined(__STDC__) || defined(__cplusplus)
#define operar_division 1
extern  float * operar_division_1(num *, CLIENT *);
extern  float * operar_division_1_svc(num *, struct svc_req *);
extern int division_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define operar_division 1
extern  float * operar_division_1();
extern  float * operar_division_1_svc();
extern int division_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_num (XDR *, num*);

#else /* K&R C */
extern bool_t xdr_num ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_DIVISION_H_RPCGEN */
