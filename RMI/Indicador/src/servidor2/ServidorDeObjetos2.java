
package servidor2;

import java.rmi.RemoteException;
import servidor2.utilidades.UtilidadesConsola;
import servidor2.utilidades.UtilidadesRegistroS;
import servidor2.sop_rmi.InterfazRemota2Impl;

public class ServidorDeObjetos2{
    public static void main(String args[]) throws RemoteException{
        int numPuertoNS = 0;
        String direccionNS = "";

        System.out.println("Cual es el la dirección ip donde se encuentra  el n_s");
        direccionNS = UtilidadesConsola.leerCadena();
        System.out.println("Cual es el número de puerto por el cual escucha el n_s");
        numPuertoNS = UtilidadesConsola.leerEntero();

        InterfazRemota2Impl objRemoto = new InterfazRemota2Impl();

        try
        {
           UtilidadesRegistroS.arrancarNS(direccionNS,numPuertoNS);
           UtilidadesRegistroS.RegistrarObjetoRemoto(objRemoto, direccionNS, numPuertoNS, "ObjetoRemotoAlerta");
        } catch (Exception e)
        {
            System.err.println("No fue posible Arrancar el NS o Registrar el objeto remoto" +  e.getMessage());
        }
    }
}
