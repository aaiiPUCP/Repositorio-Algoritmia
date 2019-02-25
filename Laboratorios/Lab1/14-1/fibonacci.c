#include <stdio.h>
#include <stdlib.h>

long unsigned fibo1(long unsigned n);
long unsigned fibo2(long unsigned n);
long unsigned fibo3(long unsigned n);

int main(int narg, char *argv[]){
	long unsigned a1,a2,a3,n;
	
	n = atoi(argv[1]);
	a1 = fibo1(n);
	printf("El Fibonacci de %ld hallado por fibo1 es:%ld\n",n,a1);
	fflush(stdout);
	a2 = fibo2(n);
	printf("El Fibonacci de %ld hallado por fibo2 es:%ld\n",n,a2); 
	fflush(stdout);
	a3 = fibo3(n);
	printf("El Fibonacci de %ld hallado por fibo3 es:%ld\n",n,a3);   
	fflush(stdout);
	return 0;
}	

long unsigned fibo1(long unsigned n) {
	long unsigned x,k;
	long unsigned y=1,t;
	
	x=k=0;
	while(k != n) {
		t = x;
		x = y;
		y = t + y;
		k++;
	}
         return x;
}

long unsigned fibo2(long unsigned n){
	if(n == 0) return 0;
	if(n == 1) return 1;
	if (n > 1) return (fibo2(n - 1) + fibo2(n - 2));
}

long unsigned  fibo3(long unsigned n){
	long unsigned  a,x,b,y,t,k;
	
	a=x=0;b=y=1;k=n;
	while(k != 0)
		if((k % 2) == 0) {
			t = a;
			a = a*a + b*b;
			b = 2*t*b + b*b;
			k = k / 2;
		} else {
                        t = x;
                        x = a*x + b*y;
                        y = b*t + a*y + b*y;
                        k = k - 1;
                }
        return x;
}		
      			
		