package servidor1.sop_rmi;

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import servidor2.dto.ClaseDTO2;
import servidor2.sop_rmi.InterfazRemota2;
import servidor1.dto.ClaseDTO1;
import servidor1.utilidades.UtilidadesRegistroC;

public class InterfazRemota1Impl extends UnicastRemoteObject implements InterfazRemota1 {
  private InterfazRemota2 objReferenciaRemota;
  int idAlerta = -1;

  public InterfazRemota1Impl() throws RemoteException {
    super(); // invoca al constructor de la clase base
  }

  @Override
  public void enviarIndicador(ClaseDTO1 objDTO1) throws RemoteException {

    System.out.println(" ");
    System.out.println("** Desde enviarIndicador() ...");

    if ((objDTO1.getIndicador() >= 0) && (objDTO1.getIndicador() <= 49)) {
      System.out.println("** El indicador " + objDTO1.getIndicador() + " ");
      System.out.println("** esta dentro del rango normal ..");
    } else {
      if (idAlerta == -1)
        idAlerta = 1;
      else
        idAlerta = idAlerta + 1;
      ClaseDTO2 obj = new ClaseDTO2(idAlerta, objDTO1.getIndicador());
      objReferenciaRemota.enviarNotificacion(obj);
      System.out.println("** Enviando notificación ..");
    }
    System.out.println("** Saliendo de enviarIndicador() ...");
  }

  public void consultarReferenciaRemota(String direccionIpRMIRegistry, int numPuertoRMIRegistry) {
    System.out.println(" ");
    System.out.println("Desde consultarReferenciaRemotaDeNotificacion()...");
    this.objReferenciaRemota = (InterfazRemota2) UtilidadesRegistroC.obtenerObjRemoto(direccionIpRMIRegistry,
        numPuertoRMIRegistry, "ObjetoRemotoAlerta");
  }

}
