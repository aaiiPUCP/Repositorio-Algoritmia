/* 
 * File:   main.c
 * Author: feralvam
 *
 * Created on 31 August 2014, 18:10
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 15

void fill_moves(int MOV[8][2]) {
    MOV[0][0] = -1;
    MOV[0][1] = 0;
    MOV[1][0] = -1;
    MOV[1][1] = 1;
    MOV[2][0] = 0;
    MOV[2][1] = 1;
    MOV[3][0] = 1;
    MOV[3][1] = 1;
    MOV[4][0] = 1;
    MOV[4][1] = 0;
    MOV[5][0] = 1;
    MOV[5][1] = -1;
    MOV[6][0] = 0;
    MOV[6][1] = -1;
    MOV[7][0] = -1;
    MOV[7][1] = -1;
}

void fill_table(char A[MAX][MAX]){
    int i, j;
    for (i=0; i<MAX; i++){
        getchar();
        for (j=0; j<MAX; j++)
            A[i][j] = getchar();
    }
}

int cluster_length(char A[MAX][MAX], int dir, int x, int y, int MOV[8][2]){
    //printf("x = %d, y = %d, dir = %d\n", x, y, dir);
    if (x<0 || x>=MAX || y<0 || y>=MAX) // Fuera de los límites
        return INT_MIN;
    
    if (A[x][y] == 'X')
        return cluster_length(A, dir, x + MOV[dir][0], y + MOV[dir][1], MOV) + 1;
    
    return 0;
}

void mark_path(char A[MAX][MAX], int dir, int *x, int *y, int MOV[8][2]){
    *x += MOV[dir][0];
    *y += MOV[dir][1];
    while (A[*x][*y] == 'X'){
        A[*x][*y] = '+';
        *x += MOV[dir][0];
        *y += MOV[dir][1];
    }
    A[*x][*y] = 'D';
}

void find_path(char A[MAX][MAX], int x, int y, int MOV[8][2]){
    int dir, length, max_dir;
    int max_length;
    do{
        max_length = 0;
        for (dir = 0; dir <= 7; dir++){
            length = cluster_length(A, dir, x + MOV[dir][0], y + MOV[dir][1], MOV);
            //printf("dir = %d, length = %d\n", dir, length);
            if (length >  max_length){
                max_length = length;
                max_dir = dir;
            }
        }
        if (max_length != 0)
            mark_path(A, max_dir, &x, &y, MOV);
        //printf("max_length = %d, min_dir = %d, x = %d, y = %d\n", max_length, max_dir, x, y);
    } while (max_length != 0);
}

void print_table(char A[MAX][MAX]){
    int i, j;
    for (i=0; i<MAX; i++){
        for (j=0; j<MAX; j++)
            printf("%c", A[i][j]);
        printf("\n");
    } 
}

int main(int argc, char** argv) {
    char A[MAX][MAX];
    int MOV[8][2];
    int n, x, y;
    
    fill_moves(MOV);
    scanf("%d %d", &x, &y);
    fill_table(A);
    find_path(A, x, y, MOV);
    print_table(A);

    return (EXIT_SUCCESS);
}