package servidor1.sop_rmi;

import java.rmi.Remote;
import java.rmi.RemoteException;
import servidor1.dto.ClaseDTO1;

public interface InterfazRemota1 extends Remote{
  void enviarIndicador(ClaseDTO1 objDTO1) throws RemoteException;
};
