/*Estrategia: se imprimen a caracteres
 * Se llama a recursividad con a+1
 * y se terminan de imprimir otra vez los a caracteres
 * el caso base es cuando a>b ahi retorna
 */


#include <stdio.h>
#include <stdlib.h>

//Recive a que es la cantidad de veces que se quiere imprimir el caracter c
void imprimircaracter(int a, char c){
    int i;
    for(i=0; i<a; i++)
        printf("%c",c);
    printf("\n");
}

void triangulo(int a, int b){
    int i,j;
    
    if(a>b)
        return;
    else{
        imprimircaracter(a,'*');
        
        //Lamada Recursiva
        triangulo(a+1,b);     
        
        imprimircaracter(a,'*');
    }
}

int main(int argc, char** argv) {
    int a,b;
    
    scanf("%d %d",&a,&b);
    
    triangulo(a,b);
    
    return (EXIT_SUCCESS);
}

