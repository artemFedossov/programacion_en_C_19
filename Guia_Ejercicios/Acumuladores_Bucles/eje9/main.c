#include <stdio.h>
#include <stdlib.h>

/* Escribir un programa que realice lea por teclado 20 caracteres. Luego de la lectura indicar cuantas "a" se
   ingresaron, cuantas "e, i, o, u" */

int main()
{
    char letra[20];
    int i;
    int contadorA = 0;
    int contadorE = 0;
    int contadorI = 0;
    int contadorO = 0;
    int contadorU = 0;

    for(i=0; i<20; i++){

        printf("Ingrese %d letras: ",20-i);
        fflush(stdin);
        scanf("%c",&letra[i]);

        if(letra[i] == 'a'){
            contadorA ++;
        }else if(letra[i] == 'e'){
            contadorE ++;
        }else if(letra[i] == 'i'){
            contadorI ++;
        }else if(letra[i] == 'o'){
            contadorO ++;
        }else if(letra[i] == 'u'){
            contadorU ++;
        }
    }

    printf("\nhay %d A ingresadas\n",contadorA);
    printf("hay %d E ingresadas\n",contadorE);
    printf("hay %d I ingresadas\n",contadorI);
    printf("hay %d O ingresadas\n",contadorO);
    printf("hay %d U ingresadas\n",contadorU);

    return 0;
}
