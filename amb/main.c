#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM_CLIENTE 2

typedef struct{

    int id;
    char nombre[51];
    char apellido[51];
    int cuit;

}eCliente;

void menu(char menu[][41],int filaMenu,char *eMensaje,int *opcion);
void validarOpcionMenu(int *opcion,char *validar,char *eMensaje);
void inicializarEstructura(eCliente *persona,int tam);

int main()
{
    int opcionMenu = 14;
    int *ptrOpcionMenu;
    char menuMensaje[13][41] = {"\t\tClasificados\n\n",
                                " 1) Alta de cliente\n",
                                " 2) Modificar datos del cliente\n",
                                " 3) Baja del cliente\n",
                                " 4) Publicar\n",
                                " 5) Pausar publicacion\n",
                                " 6) Reanudar publicacion\n",
                                " 7) Imprimir clientes\n",
                                " 8) Imprimir publicacion\n",
                                " 9) Informar clientes\n",
                                "10) Informar punlicaciones\n",
                                "11) salir\n\n",
                                "opcion: "};

    char eMensaje[2][41] = {"ERROR: Ingreso una opcion incorrecta: ",
                            "ERROR: Ingreso un carracter incorrecto: "};

    eCliente persona[TAM_CLIENTE];

    ptrOpcionMenu = &opcionMenu;

    inicializarEstructura(persona,TAM_CLIENTE);

    do{
        menu(menuMensaje,13,eMensaje[0],ptrOpcionMenu);

        switch(*ptrOpcionMenu){

            case 1:
                    system("cls");
                    altaCliente(persona,TAM_CLIENTE,eMensaje[1]);
                break;

            case 2:
                    printf("%s",persona[0].nombre);
                    printf("%s",persona[1].nombre);
                break;

        }

    }while(*ptrOpcionMenu != 11);


    return 0;
}

void menu(char menu[][41],int filaMenu,char *eMensaje,int *opcion){

    int i;
    char validar[51];

    for(i=0; i<filaMenu; i++){

        printf(menu[i]);
    }

    fflush(stdin);
    scanf("%s",validar);

    validarOpcionMenu(opcion,validar,eMensaje);
}


void validarOpcionMenu(int *opcion,char *validar,char *eMensaje){

    int i = 0;
    int rango;
    int todoOk = 0;

    do{

        while(validar[i] != '\0'){

            if(validar[i] < '0' || validar[i] > '9'){

                printf(eMensaje);
                fflush(stdin);
                scanf("%s",validar);
                i=0;
                continue;
            }
            i++;
        }

        rango = atoi(validar);

        if(rango < 1 || rango > 11){

            printf(eMensaje);
            fflush(stdin);
            scanf("%s",validar);
            i=0;
        }else{

        todoOk = 1;

        }

    }while(todoOk != 1);

    *opcion = rango;
}

void inicializarEstructura(eCliente *persona,int tam){

    int i;

    for(i=0; i<tam; i++){

        persona[i].id = 0;
    }

}

void altaCliente(eCliente *persona,int tam,char *eMensaje){

    int indice;
    char nombre[51];
    char apellido[51];

    indice = lugarLibre(persona,tam);

    if(indice != -1){

        persona[indice].id = indice +1;

        printf("Ingrese el nombre: ");
        fflush(stdin);
        gets(nombre);
        validarNombres(persona,tam,nombre,eMensaje);
        strcpy(persona[indice].nombre,nombre);

        printf("Ingrese el apellido: ");
        fflush(stdin);
        gets(apellido);
        validarNombres(persona,tam,apellido,eMensaje);
        strcpy(persona[indice].apellido,apellido);
    }
}

int lugarLibre(eCliente *persona,int tam){

    int i;
    int lugar = -1;

    for(i=0; i<tam; i++){

        if(persona[i].id == 0 && persona[i].id != -1)
        {
            lugar = i;
            break;
        }
    }

    return lugar;
}

void validarNombres(eCliente *persona,int tam,char *palabra,char *eMensaje){

    int i=0;

    strlwr(palabra);

    while(palabra[i] != '\0'){

        if((palabra[i] < 'a' || palabra[i] > 'z') && (palabra[i] != ' ')){

            printf(eMensaje);
            fflush(stdin);
            gets(palabra);
            strlwr(palabra);
            i=0;
            continue;
        }
        i++;
    }

    i=0;

    while(palabra[i] != '\0'){

        if(i == 0){

            palabra[i] = toupper(palabra[i]);

        }else if(palabra[i] == ' '){

            palabra[i+1] = toupper(palabra[i+1]);

        }
        i++;
    }
}
