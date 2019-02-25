#include <stdio.h>

char cadena[]={'A','B','C'};

void backtracking(char *letras, int n) {
	int k;
    for(k=0;k<3;k++){
		letras[n]=cadena[k];
		if(n<1) backtracking(letras, n+1);
		else {
			letras[2]='\0';
			printf("%s\n",letras);
		}	
	}	 	
}	
int main(void) {
	char letras[3];
	
	backtracking(letras,0);
    return 0; 	
}
