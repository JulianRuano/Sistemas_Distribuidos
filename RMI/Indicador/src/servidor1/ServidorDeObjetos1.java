
package servidor1;

import servidor1.utilidades.UtilidadesConsola;
import servidor1.utilidades.UtilidadesRegistroS;
import java.rmi.RemoteException;
import servidor1.sop_rmi.InterfazRemota1Impl;

public class ServidorDeObjetos1 {
    public static void main(String args[]) throws RemoteException {
        int numPuertoNS;
        String direccionIpNS;

        System.out.println("Cual es el la direcciOn ip donde se encuentra  el N_S");
        direccionIpNS = UtilidadesConsola.leerCadena();
        System.out.println("Cual es el número de puerto por el cual escucha el N_S");
        numPuertoNS = UtilidadesConsola.leerEntero();

        InterfazRemota1Impl objRemoto = new InterfazRemota1Impl();
        objRemoto.consultarReferenciaRemota(direccionIpNS, numPuertoNS);

        try {
            UtilidadesRegistroS.RegistrarObjetoRemoto(objRemoto, direccionIpNS, numPuertoNS, "ObjetoRemotoIndicador");
        } catch (Exception e) {
            System.err.println("No fue posible Arrancar el NS o Registrar el objeto remoto" + e.getMessage());
        }
    }
}
