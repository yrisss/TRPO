#include <stdio.h>
#include <locale.h>

int main() {
	
	setlocale (LC_ALL, "");
	int x;
	
	printf("������� ������� �� 20 �� 69: ");
	
	scanf("%d", &x);
	
	if((x<20) || (x>69)) 
	printf("������! ������ �������� �������.");

	else {
		switch(x%10) {
		
		
		case 1: printf("%d ���", x); break;
		
		case 2:
		case 3:
		case 4: printf("%d ����", x); break;
		
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 0: printf("%d ���", x); break;
	}
		 
	}
	
	return 0;
}