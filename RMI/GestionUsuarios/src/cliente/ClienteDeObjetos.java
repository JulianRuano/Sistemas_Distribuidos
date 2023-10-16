package cliente;

import cliente.utilidades.UtilidadesRegistroC;
import cliente.utilidades.UtilidadesConsola;
import java.rmi.RemoteException;
import sop_rmi.GestorUsuariosInt;
import sop_rmi.UsuarioDTO;

public class ClienteDeObjetos
{

    private static GestorUsuariosInt objRemoto;

    public static void main(String[] args)
    {
        int numPuertoRMIRegistry = 0;
        String direccionIpRMIRegistry = "";        

        System.out.println("Cual es el la dirección ip donde se encuentra  el rmiregistry ");
        direccionIpRMIRegistry = cliente.utilidades.UtilidadesConsola.leerCadena();
        System.out.println("Cual es el número de puerto por el cual escucha el rmiregistry ");
        numPuertoRMIRegistry = cliente.utilidades.UtilidadesConsola.leerEntero(); 

        objRemoto = (GestorUsuariosInt) UtilidadesRegistroC.obtenerObjRemoto(direccionIpRMIRegistry,numPuertoRMIRegistry, "gestionUsuarios");
        MenuPrincipal();

    }


    private static void MenuPrincipal()
    {
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
            System.out.println("Ingrese los apellidos ");
            String apellidos = UtilidadesConsola.leerCadena();
            UsuarioDTO objUsuario= new UsuarioDTO(id, nombres, apellidos);

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
                    System.out.println("Nombres: " + objUsuario.getNombres());
                    System.out.println("Apellidos: " + objUsuario.getApellidos());
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
            System.out.println("Ingrese los apellidos ");
            String apellidos = UtilidadesConsola.leerCadena();
            UsuarioDTO objUsuario = new UsuarioDTO(id, nombres, apellidos);

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
}

