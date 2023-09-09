/*Declaracion de datos a transferir entre el cliente y el servidor*/

/*Declaracion de constantes*/
const MAXNOM = 30;
const MAXFECHA = 10;

/*Declaracion de la estructura que permite almacenar los datos de un anteproyecto*/
struct nodo_anteproyecto{
	char titulo[MAXNOM];
	char estudiante[MAXNOM];
	char director[MAXNOM];
	char fechaPresentacion[MAXFECHA];
	int codigo;
};

/*Definicion de las operaciones que se pueden realizar*/
program gestion_anteproyectos{
	version gestion_anteproyectos_version{
		bool registrarAnteproyectoSistema(nodo_anteproyecto objAnteproyecto)=1;
		nodo_anteproyecto consultarAnteproyecto(string nombreAnteproyecto)=2;
	}=1;
}=0x20000001;
