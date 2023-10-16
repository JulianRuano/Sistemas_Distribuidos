# Sistemas_Distribuidos


## Herramientas

- Debian 10.13
- RPCGEN.
- GCC Compiler.


```bash
sudo apt-get update
sudo apt-get install build-essential
sudo apt-get install rpcbind
sudo apt-get install rpcgen
```


## función de shell de Unix/Linux 
Para agilizar el trabajo, utilizamos la siguiente función de shell que ejecuta varios comandos de consola para crear dos carpetas, Cliente y Servidor, junto con sus respectivos archivos.

Ejecutamos los siguientes comandos para guardar los siguientes alias en la bash:
```bash
nano ~/.bashrc
```

Copiamos y pegamos al final del archivo

```bash
alias rpce='c_rpce'
c_rpce() {
    # GitHub: https://github.com/JulianRuano/Sistemas_Distribuidoso
    if [ $# -eq 0 ]; then
        echo "Uso: rpce <nombre.x>"
        return 1
    fi
    nombre="$1"

    # Ejecutar rpcgen
    rpcgen "$nombre" 
    echo "Creando los archivos: $nombre"

    # Crear carpetas client y server
    mkdir -p client server
    nombre_sin_extension="${nombre%.x}"

    # Mover archivos a las carpetas correspondientes
    cp "${nombre_sin_extension}_clnt.c" "${nombre_sin_extension}_xdr.c" "${nombre_sin_extension}.h" "${nombre_sin_extension}.x" client/
    cp "${nombre_sin_extension}_svc.c" "${nombre_sin_extension}_xdr.c" "${nombre_sin_extension}.h" "${nombre_sin_extension}.x" server/
    
    # Eliminar archivos innecesarios
    rm -f *.c *.h

    # Crear los archivos client.c y server.c
    rpcgen -Sc "$nombre" > client/client.c
    rpcgen -Ss "$nombre" > server/server.c

    # Crear los archivos Makefile
    cd client
    rpcgen -Sm "$nombre" > makeC
    cd ../server
    rpcgen -Sm "$nombre" > makeS
    cd ..
}

alias Mc='make -f makeC'
alias Ms='make -f makeS'
```

### Alias
Crea el sistema de carpetas con sus archivos necesarios.
```bash  
rpce <nombreInterfaz.x>
```
Ejecutar el make del cliente
```bash
Mc
```
Ejecutar el make del del servidor 
```bash
Ms
```

# Ejemplo
Para el ejemplo, vamos a usar la interfaz 'calculadora.x'
```bash
struct numbers {
    float a;
    float b;
};

program calculadora {
    version calculadora_version {
        float suma(numbers) = 1;
        float resta(numbers) = 2;
        float multiplicacion(numbers) = 3;
        float division(numbers) = 4;
    } = 1;
} = 0x20000001;
```
codigo:[calculadora](./caluladora)

Creamos un archivo llamado 'calculadora.x', copiamos el código anterior y ejecutamos el alias guardado.

```bash
rpce calculadora.x
```

> [!NOTE]
> Una vez ejecutado el comando, solo necesitaremos implementar el código del cliente y servidor, además de configurar los archivos make."

Esto generará automáticamente lo siguiente:

![Client/Server](/img/image.png)

```bash
client
   ├── calculadora_clnt.c
   ├── calculadora.h
   ├── calculadora.x
   ├── calculadora_xdr.c
   ├── client.c
   └── makeC
```
```bash
server
    ├── calculadora.h
    ├── calculadora_svc.c
    ├── calculadora.x
    ├── calculadora_xdr.c
    ├── makeS
    └── server.c
```

**calculadora_clnt.c:** Contiene el código cliente generado para invocar procedimientos remotos en el servidor RPC.

**calculadora.h:** Contiene las declaraciones de funciones RPC y estructuras de datos necesarias para la comunicación entre el cliente y el servidor.

**calculadora.x:** Es el archivo de especificación de RPC que define funciones RPC, tipos de datos y procedimientos remotos.

**calculadora_xdr.c:** Contiene código para la serialización y deserialización de datos en formato XDR para la comunicación entre el cliente y el servidor.

**client.c:** Contiene el código del cliente que utiliza las funciones generadas en calculadora_clnt.c para interactuar con el servidor RPC.

**server.c:** Contiene el código del servidor RPC, incluyendo las implementaciones de las funciones RPC y la lógica para manejar solicitudes de clientes.

**calculadora_svc.c:** Este archivo contiene el código del servidor RPC. En particular, se encarga de recibir las solicitudes de los clientes RPC, enrutarlas a las funciones RPC adecuadas definidas en la especificación, y luego enviar las respuestas de vuelta a los clientes.

**makeC:** Es un archivo de instrucciones de compilación para compilar el código del cliente y enlazarlo con las bibliotecas RPC necesarias.

**makeS:** Es un archivo de instrucciones de compilación para compilar el código del servidor y enlazarlo con las bibliotecas RPC necesarias.

### implementación del cliente

Para el cliente, vamos a agregar el código en el archivo**client.c**

[codigo del cliente](./calculadora/client/client.c)


#### MakeC

Solo modificamos esta parte, no tocamos nada del resto de la configuración.

```bash
CLIENT = calculadora_client
SERVER = 

SOURCES_CLNT.c = client.c
SOURCES_CLNT.h = calculadora.h
SOURCES_SVC.c = 
SOURCES_SVC.h = 
SOURCES.x = calculadora.x

TARGETS_SVC.c =     calculadora_xdr.c 
TARGETS_CLNT.c = calculadora_clnt.c   calculadora_xdr.c 
TARGETS = calculadora.h calculadora_xdr.c calculadora_clnt.c 

```

### implementación del servidor
Para el servidor, vamos a agregar el código en el archivo **server.c**.
[codigo del cliente](./calculadora/server/server.c)

#### MakeS

Solo modificamos esta parte, no tocamos nada del resto de la configuración.

```bash
CLIENT = 
SERVER = calculadora_server

SOURCES_CLNT.c = 
SOURCES_CLNT.h = 
SOURCES_SVC.c = server.c
SOURCES_SVC.h = calculadora.h
SOURCES.x = calculadora.x

TARGETS_SVC.c = calculadora_svc.c   calculadora_xdr.c 
TARGETS_CLNT.c =     calculadora_xdr.c 
TARGETS = calculadora.h calculadora_xdr.c   calculadora_svc.c    
```

### Compilación y Ejecución
Abrimos una terminal en la ubicación del servidor y ejecutamos.

```bash
Ms
```
Generará un archivo llamado **calculadora_server**, que fue el nombre que definimos en el archivo 

MakeS: *SERVER = calculadora_server*

Para ejecutar el servidor, utiliza el siguiente comando:
```bash
./calculadora_server
```

Realizamos lo mismo para el cliente.

MakeC: *CLIENT = calculadora_client*
> [!NOTE]
> Para evitar errores, es necesario lanzar primero el servidor.

```bash
Mc
```
Ejecuta el cliente
```bash
./calculadora_clien
```
