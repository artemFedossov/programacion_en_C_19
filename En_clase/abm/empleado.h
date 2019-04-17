#ifndef empleado_H_INCLUDED
#define empleado_H_INCLUDED

typedef struct{

    int dia;
    int mes;
    int anio;

}eFecha;

typedef struct{

    int id;
    char descripcion[31];

}sector;

typedef struct{

    int legajo;
    int estado;
    int idSector;
    char nombre[20];
    char sexo;
    float sueldo;
    eFecha fechaNac;

}eEmpleado;

void menu(char menu[][31],int filaMenu,char *eMensaje,char *opcion,char desde,char hasta);
void validarOpcion(char eMensaje[],char validar[],char *opcion,char desde,char hasta);
void inicializarEstado(eEmpleado *emp,int tam);
void mostrarEmpleado(eEmpleado emp);
void mostrarEmpleados(eEmpleado *lista,int tam);
int buscarLibre(eEmpleado *lista,int tam);
int buscarEmpleado(eEmpleado *lista,int tam,int legajo);
void alta(eEmpleado *lista,int tam);

#endif
