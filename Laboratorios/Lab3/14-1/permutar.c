#include <stdio.h>
#define T 1
#define F 0

int auxiliar[]={F,F,F};
char conjunto[]={'A','B','C'};

void backtracking(char *letras, int n) {
	int k;
    for(k=0;k<3;k++){
		if(auxiliar[k]==F){
		  letras[n]=conjunto[k];
		  auxiliar[k]=T;
		  if(n<2) backtracking(letras, n+1);
		  else {
			letras[3]='\0';
			printf("%s\n",letras);
		  }
		  auxiliar[k]=F;
		}  	
	}	 	
}	
int main(void) {
	char letras[4];
	
	backtracking(letras,0);
    return 0; 	
}
