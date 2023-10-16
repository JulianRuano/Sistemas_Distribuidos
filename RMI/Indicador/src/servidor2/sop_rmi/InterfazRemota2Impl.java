package servidor2.sop_rmi;

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import servidor2.dto.ClaseDTO2;

public class InterfazRemota2Impl extends UnicastRemoteObject implements InterfazRemota2{

    public InterfazRemota2Impl() throws RemoteException{
        super();
    }

    @Override
    public void enviarNotificacion(ClaseDTO2 objDTO2) throws RemoteException{
      System.out.println("");
	    System.out.println("** Desde enviarNotificacion() ... ");
      System.out.println("** El indicardor " + objDTO2.getAlerta());
	    System.out.println("** esta fuera de rango");
      System.out.println("** Saliendo de notificarRegistro() ... ");
     }
}
