#include "Fecha.h"
#include <stdio.h>

Fecha initFecha(int dia, int mes, int ano) {
    Fecha fecha;
    fecha.dia = dia;
    fecha.mes = mes;
    fecha.ano = ano;
    
    return fecha;
}

// devuelve -1 si f1 es mayor que f2
// devuelve 1 si f2 es mayor que f1
// devuelve 0 si f1 es igual a f2
int Fecha_Cmp(Fecha f1, Fecha f2) {
    if (f1.ano < f2.ano) return 1;
    else
    if (f1.ano > f2.ano) return -1;
    else {
        if (f1.mes < f2.mes) return 1;
        else
        if (f1.mes > f2.mes) return -1;
        else {
            if (f1.dia < f2.dia) return 1;
            else
            if (f1.dia > f2.dia) return -1;
            else
                return 0;
        }
    }    
}

void Fecha_Print(Fecha fecha) {
    printf("%d/%d/%d", fecha.dia, fecha.mes, fecha.ano);
}