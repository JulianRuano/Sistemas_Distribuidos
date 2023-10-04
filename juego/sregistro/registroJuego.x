/*Definición de las operaciones que se pueden realizar*/
/*Declaración de constantes*/
const RMAXDAT = 20;

/*Declaración de la estructura que permite almacenar los datos para una partida*/

struct datos_juego{
    int id_juego;
    char fecha[RMAXDAT];
    int id_jugador1;
    int id_jugador2;
    int ganador;
};

program registro_juego{
    version registro_juego_version{
        void enviarNotificacion(struct datos_juego juego)=1;
        datos_juego historial(int id_jugador)=2;
    }=1;
}=0x30000015;