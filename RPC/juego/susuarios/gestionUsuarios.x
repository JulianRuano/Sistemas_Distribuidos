/*Declaración de datos a transferir entre el cliente y el servidor*/
/*Declaración de constantes*/
const UMAXNOM = 64;
const UMAXDAT = 20;

/*Declaración de la estructura que permite almacenar los datos para una sesion*/

struct datos_sesion{
    int id;
    char usuario[UMAXDAT];
    char clave[UMAXDAT];
};

/*Declaración de la estructura que permite almacenar los datos de un usuario*/

struct datos_usuario{
    int id;
    char nombreCompleto[UMAXNOM];
    int edad;
    char usuario[UMAXDAT];
    char clave[UMAXDAT];
};

/*Definición de las operaciones que se pueden realizar*/

program gestion_usuarios{
    version gestion_usuarios_version{
        datos_usuario abrirSesion(datos_sesion objSesion)=1;
        bool registrarUsuarios(datos_usuario objUsuario)=2;
        datos_usuario consultarUsuario(int id)=3;
    }=1;
}=0x30000013;