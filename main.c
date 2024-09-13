#include <stdio.h>
#include <math.h> //Incluyo este header para usar pow

float calcula_imc(float,float); //Prototipo de la función

int main(int argc, char const *argv[])
{
    //Este es un comentario

    float estatura, peso, imc;
    char Nombre[30];


    printf("Ingrese su nombre: \n");
    fgets(Nombre, 30, stdin); //Lee texto de un archivo

    printf("Ingrese su peso: \n");
    scanf("%f",&peso); //Lee del teclado y lo convierte al formato
    printf("Ingrese su estatura: \n");
    scanf("%f",&estatura);

    
    imc = calcula_imc(peso,estatura); //Llamar a la función


    printf("%s su IMC = %f\n",Nombre,imc);


    
    printf("Sistemas Computacionales 2024\n");
    return 0;
}

float calcula_imc(float peso,float estatura) //no lleva ;
{
    float IMC;
    //IMC = PESO / ESTATURA^2
    IMC = peso / pow(estatura, 2);
    return IMC;
}