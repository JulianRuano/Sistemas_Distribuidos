package servidor2.sop_rmi;

import java.rmi.Remote;
import java.rmi.RemoteException;
import servidor2.dto.ClaseDTO2;

public interface InterfazRemota2 extends Remote{
  void enviarNotificacion(ClaseDTO2 objDTO2) throws RemoteException;
};
