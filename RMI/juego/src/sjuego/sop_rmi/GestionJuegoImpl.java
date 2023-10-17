package sjuego.sop_rmi;

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import sregistro.dto.RegistroDTO;
import sregistro.sop_rmi.RegistroJuegoInt;
import sjuego.utilidades.UtilidadesRegistroC;

public class GestionJuegoImpl extends UnicastRemoteObject implements GestionJuegoInt {

    private RegistroJuegoInt objReferenciaRemota;
    int idJuego = 0;
    int idJugador1 = 0;
    int idJugador2 = 0;

    public GestionJuegoImpl() throws RemoteException {
        super(); // invoca al constructor de la clase base
    }

    public void iniciarJuego(int identificacion){
        System.out.println("El jugador con identificacion " + identificacion + " ha iniciado el juego");

        if(idJugador1 == 0){
            System.out.println("Entre al if");
            idJugador1 = identificacion;
        }else{
            try {
                System.out.println("Entre al else: "+idJugador1);
                idJugador2 = identificacion;
                RegistroDTO obj = new RegistroDTO(idJuego, idJugador1, idJugador2);
                objReferenciaRemota.enviarNotificacion(obj);
            } catch (RemoteException e) {
                System.out.println("Error al enviar la notificacion");
            }
        }

    }
    public void consultarReferenciaRemota(String direccionIpRMIRegistry, int numPuertoRMIRegistry){
        System.out.println(" ");
        System.out.println("Desde consultarReferenciaRemotaDeNotificacion()...");
        this.objReferenciaRemota = (RegistroJuegoInt) UtilidadesRegistroC.obtenerObjRemoto(direccionIpRMIRegistry,
                numPuertoRMIRegistry, "registroJuego");
    }
}
