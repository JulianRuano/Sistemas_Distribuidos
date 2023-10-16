/*Declaración de datos a transferir entre el cliente y el servidor*/

/*Declaración de constantes*/

const MAXNOM = 30;
const MAXDAT = 12;

/*Declaración de la estructura que permite almacenar los datos para una sesion*/

struct datos_sesion{
    int id;
    char usuario[MAXDAT];
    char clave[MAXDAT];
};

/*Declaración de la estructura que permite almacenar los datos de un usuario*/

struct datos_usuario{
    int id;
    char nombreCompleto[MAXNOM];
    int edad;
    char usuario[MAXDAT];
    char clave[MAXDAT];
};

/*Definición de las operaciones que se pueden realizar*/

program gestion_usuarios{
    version gestion_usuarios_version{
        datos_usuario abrirSesion(datos_sesion objSesion)=1;
        bool registrarUsuarios(datos_usuario objUsuario)=2;
        datos_usuario consultarusuario(int id)=3;
    }=1;
}=0x30000013;