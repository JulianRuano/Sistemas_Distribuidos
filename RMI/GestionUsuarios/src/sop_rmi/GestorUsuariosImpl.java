package sop_rmi;

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.util.ArrayList;

/*
Clase que implementa la interface remota GestorUsuariosInt
*/

public class GestorUsuariosImpl extends UnicastRemoteObject implements GestorUsuariosInt {
    private ArrayList<UsuarioDTO> misUsuarios;

    public GestorUsuariosImpl() throws RemoteException {
        super(); // invoca al constructor de la clase base //asigna un puerto de escucha al OR
        this.misUsuarios = new ArrayList();
    }

    @Override
    public boolean registrarUsuario(UsuarioDTO objUsuario) throws RemoteException {
        System.out.println("Entrando a registrar usuario");
        boolean bandera = false;

        if (misUsuarios.size() < 5) {
            bandera = misUsuarios.add(objUsuario);
            System.out.println("Usuario registrado: identificación: " + objUsuario.getID() + ", nombres: "
                    + objUsuario.getNombres() + ", apellidos. " + objUsuario.getApellidos());
        }
        return bandera;
    }

    @Override
    public int consultarCantidadUsuarios() throws RemoteException {
        System.out.println("Entrando a Cantidad");
        return misUsuarios.size();
    }

    @Override
    public UsuarioDTO consultarUsuario(int identificacion) throws RemoteException {

        System.out.println("Entrando a consultar usuario");
        UsuarioDTO objUsuario = null;

        for (int i = 0; i < this.misUsuarios.size(); i++) {
            if (this.misUsuarios.get(i).getID() == identificacion) {
                objUsuario = this.misUsuarios.get(i);
                break;
            }
        }
        return objUsuario;
    }

    @Override
    public boolean eliminarUsuario(int identificacion) throws RemoteException {
        System.out.println("Entrando a eliminar usuario");
        boolean bandera = false;

        for (int i = 0; i < this.misUsuarios.size(); i++) {
            if (this.misUsuarios.get(i).getID() == identificacion) {
                this.misUsuarios.remove(i);
                bandera = true;
                break;
            }
        }
        return bandera;
    }

    @Override
    public boolean actualizarUsuario(UsuarioDTO objUsuario) throws RemoteException {
        System.out.println("Entrando a actualizar usuario");
        boolean bandera = false;

        for (int i = 0; i < this.misUsuarios.size(); i++) {
            if (this.misUsuarios.get(i).getID() == objUsuario.getID()) {
                this.misUsuarios.set(i, objUsuario);
                bandera = true;
                break;
            }
        }
        return bandera;
    }

}
