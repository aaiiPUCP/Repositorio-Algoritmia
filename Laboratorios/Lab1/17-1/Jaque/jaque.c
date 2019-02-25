/*
	Pregunta 1: Jaque al Rey
	Laboratorio 1 de Algoritmia (INF263)
	Nombre: Gallardo Callalli Arian Gabriel
	Codigo: 20153227
	Estrategia:
		La cuestion en este problema es revisar si el rey esta
		en jaque dada una configuracion de piezas en el tablero
		de ajedrez. Asi, se procedera a verificar pieza por pieza
		(sea caballo, alfil o torre) si esta en la posibilidad de
		atacar al rey. Aparte de ello, se debera revisar si en esta
		posibilidad de ataque no existen bloqueos(es decir, piezas
		en medio del ataque) para la torre y el alfil. El caballo
		es indiferente de esta restriccion.

		Se usara Fuerza Bruta en O(n^2), siendo n la cantidad de piezas.
	
	2017-1
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 500000
typedef long long ll;

ll posX[MAX], posY[MAX];
char pieza[MAX];
ll n;
ll xrey, yrey;
ll mate;

ll max(ll a, ll b){
	return (a > b ? a : b);
}

ll min(ll a, ll b){
	return (a < b ? a : b);
}

void solveCaballo(ll x, ll y, ll id){
	for(ll dx = -2; dx <= 2; dx++){
		for(ll dy = -2; dy <=2; dy++){
			if(dx*dx + dy*dy != 5) continue; //La distancia diagonal entre el caballo y la posicion debe ser sqrt(5)
			ll r = x+dx, s = y+dy;
			if(r < 0 || s < 0) continue;
			if(r == xrey && s == yrey){ //Si el caballo ataca al rey hay jaque
				mate++; return;
			}
		}
	}
}

void solveTorre(ll x, ll y, ll id){
	ll bloq = 0;
	if(xrey == x){ //Misma columna
		for(ll i = 0; i < n; i++){
			if(i == id) continue;
			ll u = posX[i], v = posY[i];
			if(u != x) continue;
			if(v > min(y,yrey) && v < max(y,yrey)) return; //Esta en medio
		}
		mate++; return;
	}
	else if(yrey == y){ //Misma fila
		for(ll i = 0; i < n; i++){
			if(i == id) continue;
			ll u = posX[i], v = posY[i];
			if(v != y) continue;
			if(u > min(x,xrey) && u < max(x,xrey)) return; //Esta en medio
		}
		mate++; return;
	}
	else return;
}

void solveAlfil(ll x, ll y, ll id){
	if(x == xrey || y == yrey) return; //Estos casos son imposibles para el alfil
	ll dx[4] = {-1,-1,1,1};
	ll dy[4] = {1,-1,1,-1};
	for(ll i = 0; i < 4; i ++){
		ll k = (xrey-x)/dx[i]; //Diferencia en X
		ll r = (yrey-y)/dy[i]; //Diferencia en Y
		if(k != r) continue; //Para que un alfil este en la misma diagonal, las diferencias deben ser iguales
		if(k < 0) continue; //Solo consideramos la direccion positiva actual
		ll flag = 1; //Este flag se desactivara cuando haya un bloqueo
		for(ll j = 0; j < n; j++){
			if(j == id) continue;
			ll u = posX[j], v = posY[j];
			ll k2 = (xrey-u)/dx[i];
			ll r2 = (yrey-v)/dy[i];
			if(k2 != r2) continue;
			if(k2 < 0) continue;
			if(k2 < k){
				flag--;
				break;
			}
		}
		if(flag){ //Si nunca se desactivo, entonces no hay bloqueo, hay jaque
			mate++; return;
		}
	}
}

int main(){
	scanf("%lli",&n);
	scanf("%lli %lli",&xrey,&yrey);
	for(ll i = 0; i < n; i ++){
		getchar(); //Obviamos el salto de linea
		pieza[i] = getchar();
		scanf("%lli %lli",&posX[i], &posY[i]);
	}
	for(ll i = 0; i < n; i ++){
		if(pieza[i] == 'A') solveAlfil(posX[i],posY[i],i);
		else if(pieza[i] == 'T') solveTorre(posX[i],posY[i],i);
		else solveCaballo(posX[i],posY[i],i);
		if(mate) break;
	}
	if(mate) printf("SI\n");
	else printf("NO\n");
	return 0;
}