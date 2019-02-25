/*Nombre: Manuel Alberto Bezerra Brandao Corrales
  Código: 20161811
  Estrategia a usar: La estrategía que se realizará para la solución de este
  problema, será la implementación de un algortimo basado en BackTracking el cual
  encontrará la solución a el Sudoku probando todas las opciones posibles, regresando
  un paso hacia atrás cuando la opción evaluada no es correcta 

  Nota: Para realizar pruebas en este código hay múltiples lineas de print que han sido comentadas
  luego de ser usadas.
  */

#include <stdio.h>
#include <stdlib.h>
#define N 9 //número de filas, columnas de la matriz que guardará el sudoku, es una constante


void print_tablero(int T[N][N]){
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			printf("%d ",T[i][j]); //imprimirá uno a uno los números de la matriz
		}
		printf("\n"); //imprimirá un salto de línea luego de 9 números
	}
}

int hayPosicionesDisponibles(int A[N][N],int*x,int*y){ //x e y son parametros por referencia puesto que devolverán la posición del lugar vacío en el Sudoku
	//printf("Analizando si hay posiciones disponibles en el sudoku:\n");
	//print_tablero(A);
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			//printf("analizando posicion i=%d j=%d\n",i,j);
			if (A[i][j]==0){
				*x=i;
				*y=j;
				return 1; //Si se encuentra un valor 0 hay espacios disponibles
			}
		}
	}
	//printf("No hay posición disponible en el Sudoku\n");
	return 0; //Si termina la iterativa, quiere decir que el Sudoku ya está lleno
}

int validacion(int A[N][N], int fil, int col, int val){
	int i,j;
	//printf("fil=%d,col=%d\n",fil,col);
	//Se deberá ver que el número asignado encaje en su fila
	for(i=0; i<9; i++){
		if(A[fil][i]==val){
			return 0; //Si el número ya se encuentra en esa fila, no es correcto lo asumido
		}
	}
	//printf("Es válido en su fila\n");
	//Se deberá ver que el número asignado encaje en su columna
	for(i=0; i<9; i++){
		if(A[i][col]==val){
			return 0; //Si el número ya se encuentra en esa columna, no es correcto lo asumido
		}
	}
	//printf("Es válido en su columna\n");
	//Se deberá analizar el bloque de 3*3 encaje el número asignado
	int bloqueX= fil/3; //Para saber a que bloque pertenece, se hace una división entera de su posición
	int bloqueY= col/3; 
	//El bloque será el X,Y
	//printf("analizando el bloque X=%d Y=%d para el valor %d\n",bloqueX, bloqueY, val);
	//printf("Quiere ser ubicado en la posicion fila=%d, columna=%d\n",fil,col);
	//print_tablero(A);

	for(i=3*bloqueX; i<3+3*bloqueX; i++){
		for(j=3*bloqueY; j<3+3*bloqueY; j++){
			//printf("es i= %d ,j= %d igual a el valor= %d ? \n",i,j,val);
			if(A[i][j]==val){
				return 0; //El número asumido no pertenece al bloque de 3*3
			}
		}
	}
	//printf("Es válido en su Bloque 3*3\n");
	//Si el número no falla en ninguna validacion, es correcto
	return 1;
}

int sudoku(int A[N][N]){ //A es el Sudoku
	//printf("Empezando a analizar el sudoku: \n");
	//print_tablero(A);
	//printf("\n");
	int x,y; //Guardaŕan las coordenadas de la matriz en las que haya posición disponible
	if(hayPosicionesDisponibles(A,&x,&y)==0){
		return 1; //Si el Sudoku ya está lleno, el Sudoku se resolvió
	}
	//Si aún hay espacios disponibles:
	int i;
	//printf("Posicion a analizar: x=%d,y=%d\n",x,y);
	for(i=1; i<=9; i++){ //i será el número que puede ser añadido al Sudoku en la posición x,y
		if(validacion(A,x,y,i)){
			A[x][y]=i;
			//printf("Asignando el valor %d\n",i);
			//print_tablero(A);
			//printf("\n");
			if (sudoku(A)==1){ //si se puede seguir resolviendo, en otras palabras, si es que lo asumido es correcto
				return 1;
			}
			//printf("Fue incorrecto el valor\n");
			A[x][y]=0; //Si no fue correcto, entonces se debe borrar lo que se asumió anteriormente		
		}
	}
	return 0; //Si sale de la iterativa quiere decir que lo asumido un paso anterior al actual o antes es incorrecto
}
//Módulo principal
int main(){
	int T[N][N]; //Será la matriz que guardará el Sudoku
	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++){
			scanf("%d", &T[i][j]); //se lee todo el Sudoku sin resolver y se guarda en el arreglo de 9 x 9
		}
	}

	/*Se asume que el sudoku será como el siguiente:
		0 2 0 0 0 0 0 9 0
		3 0 1 9 0 6 5 0 2
		0 0 0 8 0 4 0 0 0
		0 9 0 0 0 0 0 5 0
		5 0 0 2 0 3 0 0 6
		0 7 0 0 0 0 0 2 0
		0 0 0 4 0 7 0 0 0
		8 0 2 5 0 1 7 0 3
		0 5 0 0 0 0 0 8 0
	En donde el número 0 representa un espacio en blanco en el Sudoku*/

	if (sudoku(T)){
		print_tablero(T); //Si se resolvió el sudoku, se imprimirá
	}
	else{
		printf("No existe solución.\n"); //Si no se logró resolver, se mandará un mensaje
	}
	return 0;
}