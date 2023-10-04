/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "gestionJuego.h"

bool_t
xdr_info_color (XDR *xdrs, info_color *objp)
{
	register int32_t *buf;

	int i;
	 if (!xdr_vector (xdrs, (char *)objp->color1, JMAXDAT,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->color2, JMAXDAT,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->color3, JMAXDAT,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->color4, JMAXDAT,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->color5, JMAXDAT,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->generacion))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_info_espiga (XDR *xdrs, info_espiga *objp)
{
	register int32_t *buf;

	int i;
	 if (!xdr_vector (xdrs, (char *)objp->espiga1, JMAXDAT,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->espiga2, JMAXDAT,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->espiga3, JMAXDAT,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->espiga4, JMAXDAT,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->espiga5, JMAXDAT,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->generacion))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_config_juego (XDR *xdrs, config_juego *objp)
{
	register int32_t *buf;


	if (xdrs->x_op == XDR_ENCODE) {
		buf = XDR_INLINE (xdrs, 4 * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_int (xdrs, &objp->id_partida))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->rol))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->repetirColor))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->estado))
				 return FALSE;
		} else {
			IXDR_PUT_LONG(buf, objp->id_partida);
			IXDR_PUT_LONG(buf, objp->rol);
			IXDR_PUT_LONG(buf, objp->repetirColor);
			IXDR_PUT_LONG(buf, objp->estado);
		}
		return TRUE;
	} else if (xdrs->x_op == XDR_DECODE) {
		buf = XDR_INLINE (xdrs, 4 * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_int (xdrs, &objp->id_partida))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->rol))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->repetirColor))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->estado))
				 return FALSE;
		} else {
			objp->id_partida = IXDR_GET_LONG(buf);
			objp->rol = IXDR_GET_LONG(buf);
			objp->repetirColor = IXDR_GET_LONG(buf);
			objp->estado = IXDR_GET_LONG(buf);
		}
	 return TRUE;
	}

	 if (!xdr_int (xdrs, &objp->id_partida))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->rol))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->repetirColor))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->estado))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_fin_juego (XDR *xdrs, fin_juego *objp)
{
	register int32_t *buf;


	if (xdrs->x_op == XDR_ENCODE) {
		buf = XDR_INLINE (xdrs, 4 * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_int (xdrs, &objp->id_partida))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->id_ganador))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->puntaje1))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->puntaje2))
				 return FALSE;
		} else {
			IXDR_PUT_LONG(buf, objp->id_partida);
			IXDR_PUT_LONG(buf, objp->id_ganador);
			IXDR_PUT_LONG(buf, objp->puntaje1);
			IXDR_PUT_LONG(buf, objp->puntaje2);
		}
		return TRUE;
	} else if (xdrs->x_op == XDR_DECODE) {
		buf = XDR_INLINE (xdrs, 4 * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_int (xdrs, &objp->id_partida))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->id_ganador))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->puntaje1))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->puntaje2))
				 return FALSE;
		} else {
			objp->id_partida = IXDR_GET_LONG(buf);
			objp->id_ganador = IXDR_GET_LONG(buf);
			objp->puntaje1 = IXDR_GET_LONG(buf);
			objp->puntaje2 = IXDR_GET_LONG(buf);
		}
	 return TRUE;
	}

	 if (!xdr_int (xdrs, &objp->id_partida))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->id_ganador))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->puntaje1))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->puntaje2))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_data_juego (XDR *xdrs, data_juego *objp)
{
	register int32_t *buf;

	int i;
	 if (!xdr_int (xdrs, &objp->id_juego))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->fecha, JMAXDAT,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->id_jugador1))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->id_jugador2))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->ganador))
		 return FALSE;
	return TRUE;
}
