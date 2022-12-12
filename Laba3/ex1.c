#include <stdio.h>
#include <stdlib.h>
int main(){
    double a, b, c, xn, xk, dx, F, x;
    
    printf("Enter a: ");
    scanf("%lf", &a);
    
    printf("Enter b: ");
    scanf("%lf", &b);
    
    printf("Enter c: ");
    scanf("%lf", &c);
    
    printf("Enter xn: ");
    scanf("%lf", &xn);
    
    printf("Enter xk: ");
    scanf("%lf", &xk);
    
    printf("Enter dx: ");
    scanf("%lf", &dx);
    
    if (xn==xk) 
	printf ("Input error\n");
	
    printf ("|   x   |   F   |\n");
    for (x=xn; x<=xk; x=x+dx){
        if ((a<0) && (x!=0)) 
            F= a*x*x + b*b*x;
        else if ((a>0) && (x=0)) 
            F= x - (a/(x-c));
        else 
            F= 1 + (x/c);
        printf ("| %5.2lf | %5.2lf |\n", x, F);
    }

    return 0;
}