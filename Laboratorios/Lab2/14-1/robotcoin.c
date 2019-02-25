#include <stdio.h>

#define MAX(x,y)  (((x) > (y)) ? (x) : (y))
#define MAXSIZE   100

int C[MAXSIZE+1][MAXSIZE];

int main(void) {
	int F[MAXSIZE+1][MAXSIZE+1];
	int n,m,i,j;
	
	printf("Ingrese dos valores para la dimensión del tablero (n,m):");
	scanf("%d %d",&n, &m);
	printf("Ingrese la posición de las monedas (-1 para terminar):\n");
	for(;;) {
		scanf("%d %d",&i,&j);
		if(i <0 || j < 0) break;
		C[i][j] = 1;
	}	 
	F[1][1] = C[1][1];
	for(j=2; j <= m; j++) F[1][j] = F[1][j-1] + C[1][j];
	for(i=2; i <= n; i++) {
		F[i][1] = F[i-1][1] + C[i][1];
		for(j=2; j <= m; j++) 			
			F[i][j] = MAX(F[i-1][j],F[i][j-1]) + C[i][j] ;
    } 
    printf("La cantidad máxima de monedas que se recolectan es %d\n",F[n][m]);
    return 0;	
} 
