/*Declaracion de constantes*/
const MAXNOM = 30;

struct numbers{
    float a;
    float b;
};

/*Declaracion de la estructura que permite almacenar el estado y los resultados de las operaciones*/

struct nodo_multioperaciones{
    char estado[MAXNOM];
    char resultado[MAXNOM];
};

program multioperaciones{
    version multioperaciones_version{
        nodo_multioperaciones operar(numbers)=1;
    }=1;
}=0x20000001;
