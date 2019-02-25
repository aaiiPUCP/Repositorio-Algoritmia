#include <stdio.h>
#define T 1
#define F 0

int opciones[]={T,F};
char conjunto[]={'A','B','C'};

void imprime(int *letras, int n) {
	int k;
	printf("{");
	for(k=0;k<3;k++) 
		if(letras[k]==T) printf(" %c",conjunto[k]);
	printf(" }\n");		
}	

void backtracking(int *letras, int n) {
	int k;
    for(k=0;k<2;k++){
		letras[n]=opciones[k];
		if(n<2) backtracking(letras, n+1);
		else {
			imprime(letras,n);
		}	
	}	 	
}	
int main(void) {
	int letras[3];
	
	backtracking(letras,0);
    return 0; 	
}
