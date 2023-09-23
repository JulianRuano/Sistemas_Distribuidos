/*Definición de las operaciones que se pueden realizar*/
/*Declaración de constantes*/
const MAXNOM = 30;
const MAXDAT = 12;
/*Declaración de la estructura que permite almacenar los datos para una sesion*/
struct datos_juego{
    int id_juego;
    int id_jugador1;
    int id_jugador2;
};
program registro_juego{
    version registro_juego_version{
        void enviarNotificacion(struct datos_juego juego)=1;
    }=1;
}=0x30000015;