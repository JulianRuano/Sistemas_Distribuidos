package cliente;

import cliente.utilidades.UtilidadesRegistroC;
import java.rmi.RemoteException;
import servidor1.dto.ClaseDTO1;
import servidor1.sop_rmi.InterfazRemota1;
import cliente.utilidades.UtilidadesConsola;

public class ClienteDeObjetos {
	private static InterfazRemota1 objRemoto;
	private static int id = -1;

	public static void main(String[] args) {

		int numPuertoNS = 0;
		String direccionIpNS = "";

		System.out.println("Cual es el la direcciOn ip donde se encuentra  el N_S");
		direccionIpNS = UtilidadesConsola.leerCadena();
		System.out.println("Cual es el nUmero de puerto por el cual escucha el N_S");
		numPuertoNS = UtilidadesConsola.leerEntero();

		objRemoto = (InterfazRemota1) UtilidadesRegistroC.obtenerObjRemoto(direccionIpNS, numPuertoNS,
				"ObjetoRemotoIndicador");
		MenuPrincipal();
	}

	private static void MenuPrincipal() {
		int indicador = 0, opcion = 0;
		try {

			do {
				System.out.println("============Indicadores===========");
				System.out.println("Ingrese un indicador(0-100): ");
				indicador = UtilidadesConsola.leerEntero();
				System.out.println("** Invocando enviarIndicador()...");
				if (id == -1)
					id = 1;
				else
					id = id + 1;
				ClaseDTO1 obj = new ClaseDTO1(id, indicador);
				objRemoto.enviarIndicador(obj);
				System.out.println("Desea salir?(Si=1, No=0):");
				opcion = UtilidadesConsola.leerEntero();
			} while (opcion != 1);
		} catch (RemoteException e) {
			System.out.println("La operacion no se pudo completar, intente nuevamente...");
			System.out.println(e.getMessage());
		}
	}

}
