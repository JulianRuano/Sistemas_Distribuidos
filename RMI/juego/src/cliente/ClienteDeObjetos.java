package cliente;

import cliente.utilidades.UtilidadesRegistroC;
import susuario.dto.UsuarioDTO;
import susuario.dto.DatosSesionDTO;
import cliente.utilidades.UtilidadesConsola;
import java.rmi.RemoteException;
import susuario.sop_rmi.GestorUsuariosInt;
import sjuego.sop_rmi.GestionJuegoInt;

public class ClienteDeObjetos
{

    private static GestorUsuariosInt objRemoto;
    private static GestionJuegoInt objRemotoJuego;

    public static void main(String[] args)
    {
        int numPuertoRMIRegistry = 0;
        String direccionIpRMIRegistry = "";        

        System.out.println("Cual es el la dirección ip donde se encuentra  el rmiregistry ");
        direccionIpRMIRegistry = cliente.utilidades.UtilidadesConsola.leerCadena();
        System.out.println("Cual es el número de puerto por el cual escucha el rmiregistry ");
        numPuertoRMIRegistry = cliente.utilidades.UtilidadesConsola.leerEntero(); 

        objRemoto = (GestorUsuariosInt) UtilidadesRegistroC.obtenerObjRemoto(direccionIpRMIRegistry,numPuertoRMIRegistry, "gestionUsuarios");
        objRemotoJuego = (GestionJuegoInt) UtilidadesRegistroC.obtenerObjRemoto(direccionIpRMIRegistry,numPuertoRMIRegistry, "ObjetoRemotoJuego");
        MenuPrincipal();

    }


    private static void MenuPrincipal()
    {
        int opcion = 0;  
        System.out.println("==Menu sesion==");
        System.out.println("1. Abrir sesion");
        System.out.println("2. Salir");
        opcion = UtilidadesConsola.leerEntero();
        
        switch(opcion){
            case 1:
                try
                {
                    DatosSesionDTO objSesion = new DatosSesionDTO();
                    System.out.println("Ingrese la identificacion");
                    objSesion.setID(UtilidadesConsola.leerEntero()); 
                    System.out.println("Ingrese la contraseña");
                    objSesion.setClave(UtilidadesConsola.leerCadena());
                    UsuarioDTO objUsuario = new UsuarioDTO();
                    objUsuario = objRemoto.iniciarSesion(objSesion);

                    if(objUsuario.getID() == 0){
                        MenuAdmin();
                    }else if(objUsuario.getID() >= 1){
                        MenuJugador(objUsuario.getID());
                    }else{
                        System.out.println("Usuario no encontrado");
                    }                
                }
                catch(RemoteException e)
                {
                    System.out.println("La operacion no se pudo completar, intente nuevamente..."+e);
                }   
                break;
            case 2:
                System.out.println("Salir...");
                break;
            default:
                System.out.println("Opción incorrecta");
        }

            
    }

    public static void MenuJugador(int identificacion){
        int opcion = 0;
        do
        {
            System.out.println("==Menu== "+identificacion);
            System.out.println("1. Jugar");
            System.out.println("2. Consultar Juego");			
            System.out.println("3. Salir");

            opcion = UtilidadesConsola.leerEntero();

            switch(opcion)
            {
                case 1:
                        Opcion1Jugador(identificacion);
                        break;
                case 2:
                        Opcion2Jugador(identificacion);
                        break;	
                case 3:
                        System.out.println("Salir...");
                        break;
                default:
                        System.out.println("Opción incorrecta");
            }
        }while(opcion != 3);               
    }


    public static void MenuAdmin(){
        int opcion = 0;
        do
            {
                System.out.println("==Menu==");
                System.out.println("1. Registrar Usuario");			
                System.out.println("2. Consultar Cantidad de Usuarios");
                System.out.println("3. Consultar usuario");
                System.out.println("4. Eliminar usuario");
                System.out.println("5. Actualizar usuario");
                System.out.println("6. Salir");

                opcion = UtilidadesConsola.leerEntero();

                switch(opcion)
                {
                    case 1:
                            Opcion1();
                            break;
                    case 2:
                            Opcion2();
                            break;	
                    case 3:
                            Opcion3();
                            break;
                    case 4:
                            Opcion4();
                            break;
                    case 5:
                            Opcion5();
                            break;             
                    case 6:
                            System.out.println("Salir...");
                            break;
                    default:
                            System.out.println("Opción incorrecta");
                }

            }while(opcion != 6);
    }

    private static void Opcion1() 
    {

        try
        {
            System.out.println("==Registro del Cliente==");
            System.out.println("Ingrese la identificacion");
            int id = UtilidadesConsola.leerEntero();
            System.out.println("Ingrese el nombre completo ");
            String nombres = UtilidadesConsola.leerCadena();
            System.out.println("Ingrese usuario ");
            String usuario = UtilidadesConsola.leerCadena();
            System.out.println("Ingrese la contraseña ");
            String clave = UtilidadesConsola.leerCadena();
            UsuarioDTO objUsuario= new UsuarioDTO(id, nombres, usuario,clave);

            boolean valor = objRemoto.registrarUsuario(objUsuario);//invocación al método remoto
            if(valor)
                    System.out.println("Registro realizado satisfactoriamente...");
            else
                    System.out.println("no se pudo realizar el registro...");
        }
        catch(RemoteException e)
        {
            System.out.println("La operacion no se pudo completar, intente nuevamente...");
        }
    }

    private static void Opcion2()
    {	
        try
        {
            System.out.println("==Numero de usuarios==");
            int tamanio  = objRemoto.consultarCantidadUsuarios();
            System.out.println("El numero de usuarios registrados es de: "+ tamanio);
        }
        catch(RemoteException e)
        {
            System.out.println("La operación no se pudo completar, intente nuevamente...");
            System.out.println("Excepcion generada: " + e.getMessage());
        }	
    }

    private static void Opcion3() 
    {
        try
        {
            System.out.println("==Consulta de un Cliente==");
            System.out.println("Ingrese la identificacion");
            int id = UtilidadesConsola.leerEntero();			

            UsuarioDTO objUsuario= objRemoto.consultarUsuario(id);
            if(objUsuario!=null)
            {
                    System.out.println("Identificacion: " + objUsuario.getID());
                    System.out.println("Nombres: " + objUsuario.getNombres());
                    System.out.println("Usuario: " + objUsuario.getNombreUsuario());                   
            }
            else
                    System.out.println("Usuario no encontrado");
        }
        catch(RemoteException e)
        {
            System.out.println("La operacion no se pudo completar, intente nuevamente...");
        }
    }
    private static void Opcion4()
    {
        try {
            System.out.println("==Eliminar un Cliente==");
            System.out.println("Ingrese la identificacion");
            int id = UtilidadesConsola.leerEntero();

            boolean valor = objRemoto.eliminarUsuario(id);
            if (valor) {
                System.out.println("Usuario eliminado satisfactoriamente...");
            } else {
                System.out.println("Usuario no encontrado");
            }
        } catch (RemoteException e) {
            System.out.println("La operacion no se pudo completar, intente nuevamente...");
        }
    }

    private static void Opcion5()
    {
        try {
            System.out.println("==Actualizar un Cliente==");

            System.out.println("Ingrese la identificacion");
            int id = UtilidadesConsola.leerEntero();
            System.out.println("Ingrese el nombre completo ");
            String nombres = UtilidadesConsola.leerCadena();
            System.out.println("Ingrese usuario ");
            String usuario = UtilidadesConsola.leerCadena();
            System.out.println("Ingrese nueva contraseña ");
            String clave = UtilidadesConsola.leerCadena();


            UsuarioDTO objUsuario = new UsuarioDTO(id, nombres, usuario,clave);

            boolean valor = objRemoto.actualizarUsuario(objUsuario);
            if (valor) {
                System.out.println("Usuario actualizado satisfactoriamente...");
            } else {
                System.out.println("Usuario no encontrado");
            }
          
        } catch (Exception e) {
            System.out.println("La operacion no se pudo completar, intente nuevamente...");       
        }
    }

    public static void Opcion1Jugador(int identificacion){
        System.out.println("==Jugar==");    
        try {
            objRemotoJuego.iniciarJuego(identificacion);
            System.out.println("El jugador con identificacion " + identificacion + " ha iniciado el juego");
        } catch (RemoteException e) {
            System.out.println("La operacion no se pudo completar, intente nuevamente...");      
        }
        
    }

    public static void Opcion2Jugador(int identificacion){
        System.out.println("==Consultar Juego==");
        System.out.println("== Proximamente... ==");
    }
}

