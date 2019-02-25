/* 
 * File:   h-sequence
 * Author: Fernando Alva Manchego
 *
 */

#include <stdio.h>
#include <stdlib.h>

int is_hsequence(int A[], int ini, int fin){
    if (ini == fin) // Solo hay un elemento
        return A[ini] == 0;
    
    if (A[ini] == 1){ //Si hay más de un elemento, el primero debe ser 1
        int k;
        for (k = 1; k <= fin-ini-1; k++)
            if (is_hsequence(A, ini+1, ini+k) && is_hsequence(A, ini+k+1, fin))
                return 1;
    }
    return 0;        
}

int main(int argc, char** argv) {
    int A[] = {1, 1, 0};
    printf("%d\n", is_hsequence(A, 0, 2));
    
    return (EXIT_SUCCESS);
}

