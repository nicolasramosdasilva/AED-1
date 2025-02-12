//Nicolas Ramos da Silva 178197

#include <stdio.h>
 
int main(){
    
    double pi = 3.14159, raio, A;
	
	scanf("%lf", &raio);
	
	A = pi * (raio * raio);
	
	printf("A=%.4lf\n", A);
 
    return 0;
}
