#include <stdio.h>
#include <math.h>
int main(){
	
	double x,y;
	
	printf("Enter x: ");
	scanf("%lf",&x);
	if (x>4)
		y= 1 + sqrt(cos(x));
	else if ((x>=0) && (x<=5))
		y= x + 1;
	else
		y= 1 - pow(x,2);
	printf("y: %0.5lf\n", y);
	
	return 0;
} 