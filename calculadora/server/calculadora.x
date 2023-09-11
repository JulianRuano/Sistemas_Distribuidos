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
