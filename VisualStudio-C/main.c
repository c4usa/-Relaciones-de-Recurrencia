/*
Tomás González
Grupo:535
Realizar un menu que permita al usuario seleccionar tres opciones:
Opción 1: Invertir una cadena ingresada por el usuario. 
Opción 2: Calcular el factorial de un número entero positivo ingresado por el usuario.
Opción 3: Generar la sucesión de Fibonacci hasta un número dado ingresado por el usuario.
*/

#include <stdio.h>
/*La usamos porque es la más común y utilizada, al permitirnos realizar operaciones de entrada y salida.
Usamos las funciones: main, void,printf, scanf, fgets y getchar*/

#include <string.h>
/*La usamos porque nos puede proporcionar funciones que modifiquen cadenas de caracteres.
Usamos las funciones strlen y strcspn*/

#include "funciones.h"

// Declaración de funciones
void invertirCad(char cadena[], int inicio, int fin);
int factorial(int n);
void fibonacci(int n, int a, int b);

int main()
{
    int opcion;
    do
    {
        // Mostrar menú al usuario
        printf("\n--------Menú--------\n");
        printf("1. Invertir una cadena\n");
        printf("2. Calcular el factorial de un numero entero\n");
        printf("3. Generar la sucesión de Fibonacci\n");
        printf("4. Salir\n");
        printf("Seleccione una opción\n");
        scanf("%d", &opcion);
        getchar();

        /* Opciones del menú
           Opcion 1*/
        if (opcion == 1)
        {
            char cadena[100];
            printf("Ingrese lo que deese: ");//Mensaje al usuario para que ingrese una cadena de caracteres
            fgets(cadena, sizeof(cadena), stdin);//Leer la cadena ingresada por el usuario
            cadena[strcspn(cadena, "\n")] ='\0';
            invertirCad(cadena, 0, strlen(cadena) - 1);
            printf("Cadena invertida: %s\n", cadena);//Imprimir la cadena ingresada el usuario de manera invertida
        }
        //Opcion 2
        else if (opcion == 2)
        {
            int numero;
            printf("Ingrese un número entero positivo: ");//Mensaje al usuario para que ingrese solo números enteros positivos
            scanf("%d", &numero);//Leer el número ingresado por el usuario
            if (numero < 0)
            {
                printf("El número debe ser un entero positivo\n");//Mensaje al usuario si el número ingresado es negativo
            }
            else
            {
                printf("El factorial de %d es: %d\n", numero, factorial(numero));//Imprimir el factorial del número ingresado por el usuario
            }
        }
        //Opcion 3
        else if (opcion == 3)
        {
            int limite;
            printf("Ingrese el número de elementos de Fibonacci: ");//Mensaje al usuario para que ingrese el número de elementos a generar
            scanf("%d", &limite);//Leer el número ingresado por el usuario
            if (limite <= 0)
            {
                printf("El número debe ser mayor a 0\n");//Mensaje al usuario si el numero es menor a 0
            }
            else
            {
                printf("Sucesión de Fibonacci: ");
                fibonacci(limite, 0, 1);
                printf("\n");//Imprimir la sucesión de Fibonacci en base al número ingresado por el usuario 
            }
        }
        else if (opcion == 4)
        {
            printf("Programa finalizado\n");//Mensaje al usuario si eligio la opción 4 del menu
        }
        else
        {
            printf("Opción inválida. Ingrese una opción nuevamente\n");//Mensaje al usuario si ingreso un opción incorrecta en el menú
        }
    } while (opcion != 4);

    return 0;
}
