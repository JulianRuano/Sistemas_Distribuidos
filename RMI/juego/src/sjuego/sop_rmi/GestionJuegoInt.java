package sjuego.sop_rmi;
import java.rmi.Remote;
import java.rmi.RemoteException;

public interface GestionJuegoInt  extends Remote{
    public void iniciarJuego(int identificacion) throws RemoteException;
}
