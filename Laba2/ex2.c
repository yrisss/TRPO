#include <stdio.h>
#include <locale.h>

int main() {
	
	setlocale (LC_ALL, "");
	int x;
	
	printf("Введите возраст от 20 до 69: ");
	
	scanf("%d", &x);
	
	if((x<20) || (x>69)) 
	printf("Ошибка! Указан неверный возраст.");

	else {
		switch(x%10) {
		
		
		case 1: printf("%d год", x); break;
		
		case 2:
		case 3:
		case 4: printf("%d года", x); break;
		
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 0: printf("%d лет", x); break;
	}
		 
	}
	
	return 0;
}
