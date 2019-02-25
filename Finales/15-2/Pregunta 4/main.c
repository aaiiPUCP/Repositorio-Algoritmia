/* 
 * File:   main.c
 * Author: alulab14
 *
 * Created on 5 de diciembre de 2015, 12:55 PM
 */

#include <stdio.h>
#include <stdlib.h>

#include "Trees.h"

/*
 * Vemos que los "Nodos no Internos"
 * son simplemente las hojas del arbol y el primer nodo
 * ya que cualquier cosa luego del primer nodo (si no es una hoja directamente)
 * ya es un nodo interno y si no es hoja entonces se debe terminar mas abajo en 
 * una hoja y todos los que vinieron antes no seran impresos
 * 
 * Haremos una funcion que imprima en pos orden el arbol de la derecha y la izquierda
 * sin procesar el primero ( para mantener la homogeneidad) y cuando se termina
 * esta llamada recursiva imprimimos el primer nodo del arbol
 * 
 */
int main(int argc, char** argv) {
    
    t_tree tL;
    create_Leaf(&tL,'L');
    
    t_tree tM;
    create_Leaf(&tM,'M');
    
    t_tree tK;
    plantar(&tK,'K',&tL,&tM);
    
    t_tree tI;
    plantar(&tI,'I',NULL,&tK);
    
    t_tree tJ;
    create_Leaf(&tJ,'J');
    
    t_tree tH;
    plantar(&tH,'H',&tI,&tJ);
    
    t_tree tB;
    plantar(&tB,'B',&tH,NULL);
    
    //Aun no hacemos A porque debemos tener toda la otra rama
    
    t_tree tF;
    create_Leaf(&tF,'F');
    
    t_tree tG;
    create_Leaf(&tG,'G');
    
    t_tree tE;
    plantar(&tE,'E',&tF,&tG);

    t_tree tD;
    plantar(&tD,'D',NULL,&tE);
    
    t_tree tC;
    plantar(&tC,'C',NULL,&tD);
    
    t_tree tA;
    plantar(&tA,'A',&tB,&tC);       //Finalmente la raiz TA


    print_noInt(&tA);

    return (EXIT_SUCCESS);
}

