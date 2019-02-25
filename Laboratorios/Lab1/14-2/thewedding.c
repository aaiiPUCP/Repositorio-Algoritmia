/* 
 * File:   The Wedding
 * Author: Fernando Alva Manchego
 *
 * Created on 31 August 2014, 12:26
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 20

void fill_table(int A[MAX], int AB[MAX][MAX], int nA, int nB){
    int i, j;
    for (i=0; i<nA; i++){
        scanf("%d", &A[i]);
        for (j=0; j<nB; j++){
            scanf("%d", &AB[i][j]);
        }
    }
}

void find_min_comb(int T[MAX], int nT, int R[MAX], int nR, int H[MAX], int nH, int TR[MAX][MAX], int RH[MAX][MAX], int HT[MAX][MAX], 
                    int *minT, int *minR, int *minH, int *minP){
    int i, j, k;
    *minP = INT_MAX;
    for (i=0; i<nT; i++){
        for (j=0; j<nR; j++){
            for (k=0; k<nH; k++){
                if (!RH[j][k] && !HT[k][i] &&  !TR[i][j] && (T[i] + R[j] + H[k] < *minP)){
                    *minP = T[i] + R[j] + H[k];
                    *minT = i;
                    *minR = j;
                    *minH = k;
                }
            }
        }
    }
}

int main(int argc, char** argv) {
    int nT, nR, nH, minT, minR, minH, minP;
    int TR[MAX][MAX], RH[MAX][MAX], HT[MAX][MAX];
    int T[MAX], R[MAX], H[MAX];
    while (scanf("%d %d %d", &nT, &nR, &nH) == 3){
        
        fill_table(T, TR, nT, nR);
        fill_table(R, RH, nR, nH);
        fill_table(H, HT, nH, nT);
        
        find_min_comb(T, nT, R, nR, H, nH, TR, RH, HT, &minT, &minR, &minH, &minP);
        
        if (minP!=INT_MAX)
            printf("%d %d %d:%d\n", minT, minR, minH, minP);
        else
            printf("Don't get married!\n");
    }
       
    return (EXIT_SUCCESS);
}

