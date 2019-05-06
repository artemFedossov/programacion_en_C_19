#include <stdio.h>
#include <stdlib.h>

#define TAM_AUTORES 5
#define TAM_LIBROS 10
#define TAM_SOCIOS 5
#define TAM_PRESTAMOS 5

typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct{
    int id;
    char nombre[31];
    char apellido[31];
}eAutores;

typedef struct{
    int id;
    int idAutor;
    char titulo[51];
}eLibros;

typedef struct{
    int id;
    char nombre[31];
    char apellido[31];
    char telefono[16];
    char eMail[31];
    char sexo;
    eFecha fechaAsociado;
}eSocios;

typedef struct{
    int id;
    int idLibro;
    int idSocio;
    eFecha fechaPrestamo;
}ePrestamos;

int main()
{
    int opcionMenu;
    int i;
    int *ptrOpcionMenu;
    char menuMensaje[10][41] = {"\t\BIBLIOTECA\n\n",
                                " 1) Alta de Socio\n",
                                " 2) Modificar datos del Socio\n",
                                " 3) Baja del Socio\n",
                                " 4) Listar\n",
                                " 5) Listar Libros\n",
                                " 6) Listar Autores\n",
                                " 7) Prestammos\n",
                                " 8) Salir\n",
                                "opcion: "};

    char eMensaje[2][41] = {"ERROR: Ingreso una opcion incorrecta: ",
                            "ERROR: Ingreso un carracter incorrecto: "};

    char mensaje[2][41] = {"opcion: "};

    eAutores autor[TAM_AUTORES];
    eLibros libro[TAM_LIBROS];
    eSocios socio[TAM_SOCIOS];
    ePrestamos prestamo[TAM_PRESTAMOS];

    ptrOpcionMenu = &opcionMenu;

    inicializarEstructura(socio,TAM_SOCIOS);

    do{
        menu(menuMensaje,9,eMensaje[0],mensaje[0],ptrOpcionMenu);

        switch(*ptrOpcionMenu){

            case 1:
                    system("cls");
                    altas(socio,TAM_SOCIOS);
                break;

            case 2:

                break;

        }

    }while(*ptrOpcionMenu != 8);


    return 0;
}

void inicializarEstructura(eSocios *per,int tam){

    int i;

    for(i=0; i<tam; i++){

        per[i].id = -1;
    }

}

void menu(char menu[][41],int filaMenu,char *eMensaje,char *mensaje,int *opcion){

    int i;
    char validar[51];
    int r;

    for(i=0; i<filaMenu; i++){

        printf(menu[i]);
    }

    do{

        r = getInt(opcion,mensaje,eMensaje,1,8);

    }while(r == -1);

}

int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{

    int i=0;
    char validar[100];
    int rango;
    int todoOk = -1;

    printf(message);
    fflush(stdin);
    gets(validar);

    esNumero(validar,eMessage);

    rango = atoi(validar);

    while(rango < lowLimit || rango > hiLimit){

        printf(eMessage);
        fflush(stdin);
        scanf("%s",validar);
        esNumero(validar,eMessage);
        rango = atoi(validar);
    }

    *input = rango;
    todoOk = 0;

    return todoOk;
}

void esNumero(char *validar,char *eMessage){

    int i=0;

    while(validar[i] != '\0'){

        if(validar[i] < '0' || validar[i] > '9'){

            printf(eMessage);
            fflush(stdin);
            gets(validar);
            i=0;
            continue;
        }
        i++;
    }

}

void altas(eSocios array[],int tam)
{
    char buffer[100];
    int numero;
    int indice;
    char mensaje[3][51] = {"Ingrese nombre: ","Ingrese Apellido: ","Ingrese Telefono: "};
    indice = lugarLibre(array,tam);
    if(indice != -1)
    {
        ingresoAlfabetico(buffer,mensaje[0]);
        strcpy(array[indice].nombre,buffer);

        ingresoAlfabetico(buffer,mensaje[1]);
        strcpy(array[indice].apellido,buffer);

        ingresoTelefono(buffer,mensaje[2]);
        strcpy(array[indice].telefono,buffer);

    }
    else
    {
        printf("No queda mas espacio para seguir ingresando\n\n");
        system("pause");
    }

    system("cls");
}

int lugarLibre(eSocios array[],int tam)
{
    int i;
    int indiceLibre = -1;

    for(i=0; i<tam; i++)
    {
        if(array[i].id == -1)
        {
            indiceLibre = i;
            break;
        }
    }

    return indiceLibre;
}

void ingresoAlfabetico(char buffer[], char mensaje[])
{
    printf(mensaje);
    fflush(stdin);
    fgets(buffer,100,stdin);

    validarAlfabetico(buffer);
}

void validarAlfabetico(char validar[])
{
    int i = 0;
    while(validar[i] != '\n')
    {
        if((validar[i] < 'a' || validar[i] > 'z') && (validar[i] < 'A' || validar[i] > 'Z') && (validar[i] != ' '))
        {
            printf("Error: Reingrese: ");
            fflush(stdin);
            fgets(validar,100,stdin);
            i=0;
            continue;
        }
        i++;
    }
    i=0;
    while(validar[i] != '\n')
    {
        if(i == 0)
        {
            validar[i] = toupper(validar[i]);
        }
        else
        {
            if(validar[i] == ' ')
            {
                i++;
                validar[i] = toupper(validar[i]);
            }
            else
            {
                validar[i] = tolower(validar[i]);
            }
        }

        i++;
    }
}

void ingresoTelefono(char buffer[], char mensaje[]){

    printf(mensaje);
    fflush(stdin);
    fgets(buffer,100,stdin);

    validarTelefono(buffer);
}

void validarTelefono(char validar[]){
    int i = 0;
    int tam;

    tam = strlen(validar);

    while(validar[i] != '\n')
    {
        if(tam != 11){
            if(validar[0] != 0){
                if(validar[1] != 1 && validar[2] != 1){
                    if(validar[i] < '0' || validar[i] > '9'){
                        printf("Error: Reingrese el telefono con el 011: ");
                        fflush(stdin);
                        fgets(validar,100,stdin);
                        i=0;
                        continue;
                    }
                }
            }
        }
        i++;
    }
}
