/*Declaracion de la estructura que permite guardar los numeros a operar */  
struct numbers {
    float a;
    float b;
};

/*Declaracion de la estructura que permite almacenar el estado y el resultado de las oepraciones*/
struct calculator_result {
    float result;
    bool state;  
};

program calculadora {
    version calculadora_version {
        calculator_result suma(numbers) = 1;
        calculator_result resta(numbers) = 2;
        calculator_result multiplicacion(numbers) = 3;
        calculator_result division(numbers) = 4;
    } = 1;
} = 0x20000001;
