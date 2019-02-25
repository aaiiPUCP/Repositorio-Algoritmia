/* 
 * File:   Fecha.h
 * Author: junior
 *
 * Created on November 3, 2014, 12:58 AM
 */

#ifndef FECHA_H
#define	FECHA_H

#include "RedSocial.h"

struct Fecha {
    int dia;
    int mes;
    int ano;
};

Fecha initFecha(int dia, int mes, int ano);
int Fecha_Cmp(Fecha f1, Fecha f2);
void Fecha_Print(Fecha fecha);

#endif	/* FECHA_H */

