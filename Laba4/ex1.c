#include <stdio.h>

int main() {
	int x=0,i,k=0,f=0;
	while (x<=0)
	{
		printf("Enter the size of array\n");
		scanf("%d", &x);
	}

	
	int a[x], b[x];
	for(i=0; i<x; i++) {
		printf("Enter [%d] - ", i);
		scanf("%d", &a[i]);
		b[i]=a[i];
	}
	int min=abs(a[0]);
	for(i=0; i<x; i++) {
		if(abs(a[i])<min) {
			min = a[i];
		}
		printf("%d ", a[i]);
	}
	printf("\n %d\n ", min);
	for(i=0; i<x; i++) {
		if(i%2==0) {
			a[k]=b[i];
			k++;
		} else {
			a[f]=b[i];
			f++;
		}
	}
	for(i=0; i<x; i++) {
		printf("%d ", a[i]);
	}
	return 0;
}
