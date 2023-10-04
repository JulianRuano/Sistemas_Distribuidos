const JMAXDAT = 12;

/*Declaración de la estructura que permite almacenar la informacion de los colores */

struct info_color{
    char color1[JMAXDAT];
    char color2[JMAXDAT];
    char color3[JMAXDAT];
    char color4[JMAXDAT];
    char color5[JMAXDAT];
    int generacion;
};

/*Declaración de la estructura que permite almacenar la informacion de las espigas */

struct info_espiga{
    char espiga1[JMAXDAT];
    char espiga2[JMAXDAT];
    char espiga3[JMAXDAT];
    char espiga4[JMAXDAT];
    char espiga5[JMAXDAT];
    int generacion;
};

/*Declaración de la estructura que permite almacenar la informacion de la configuracion inical */
/* 
 ** estado 1,2,3 el numero del juego actual 
 ** estado 0 fin del juego
 ** estado -1 error en la partida 
*/ 

struct config_juego{
    int id_partida;
    int rol;
    int repetirColor;
    int estado;
};

/*Declaración de la estructura que permite almacenar la informacion para el fin del juego */

struct fin_juego{
    int id_partida;
    int id_ganador;
    int puntaje1;
    int puntaje2;
};

struct data_juego{
    int id_juego;
    char fecha[JMAXDAT];
    int id_jugador1;
    int id_jugador2;
    int ganador;
};


/*Definicion de las operaciones que se pueden realizar*/
program gestion_juego{
    version gestion_juego_version{
        int iniciarJuego(int id_jugador)=1;
        void enviarconfiguracion(config_juego objConfig)=2; 
        config_juego configuracion()=3; 
        bool enviarColores(info_color objColor)=4; 
        info_color actualizarTableroColor(int generacion)=5;
        bool enviarEspigas(info_espiga objEspiga)=6;
        info_espiga actualizarTableroEspiga(int generacion)=7;
        fin_juego puntuacion(int id_partida)=8; 
        void enviarConfirmacion(int objConfirmacion)=9;
        int estadoJuego()=10;
        data_juego consulta(int id_juego)=11;
    }=1;
}=0x30000014;
