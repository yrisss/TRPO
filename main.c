#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXNUMOFEMPLOYEES 100 
#define MAXNUMOFCHILDREN 10
#define MAXNUMOFUSERS 50
#define BASICAMOUNT 100.0

struct Employees {
	char employeeSurname[20];
	char employeeName[20];
	char employeePatronymic[20];

	int n_children;
	float benefit;


} a[MAXNUMOFEMPLOYEES];

struct Children {
	char childSurname[20];
	char childName[20];
	char childPatronymic[20];

	int day;
	int month;
	int year;
} b[MAXNUMOFEMPLOYEES][MAXNUMOFCHILDREN];

struct users
{
    char login[30];
    char password[30];
    int role;
} a1[MAXNUMOFUSERS] = {"admin", "admin", 1, "user", "user", 2};

int UserID = 2, EmployeeID = 0, userNum = 0;

void authorization(int *);
void userPanel();
void adminPanel();
void addNewEmployee ();
void benefitCalculation(int);
void outputInformationAboutEmployeesForUser();
void outputInformationAboutEmployeesForAdmin();
void editInformationAboutEmployees();
void editeInformationAboutChildren(int);
void outputChildren(int);
void editeInformationAboutCurrentChildren(int);
void addNewChild(int);
void deleteChild(int);
void deleteEmployee();
void outputUsers();
void addNewUser();
void array_nulling();
void editUsers();
void deleteUser();

int main()
{
   int n1 = 0, stopmain=0;
   while(stopmain == 0) {
   	printf("1 - Log in\n0 - Close programm\n");
   	scanf("%d", &n1);
            switch (n1)
            {
            	case 1: authorization(&stopmain); break;
            	case 0: 
                stopmain=1;
                break;
            default:
                printf("\nWrong number, please try again\n");
                system("pause");
                break;
			}
   }
}


void authorization(int *stopmain) {
	int n = 0;
	int stop = 0, stop1 = 0;
	int flag = 0;
	char login[30];
	char password[30];
	int maxNumofLetters = 30;
	        array_nulling(login, &maxNumofLetters);
            array_nulling(password, &maxNumofLetters);
	system("cls");  
	while (stop == 0)   {
	printf("Login: ");
	scanf("%s", &login);
	printf("Password: ");
	scanf("%s", &password);
	for(int i = 0; i < UserID; i++) {
	if (strcmp(login, a1[i].login) == 0 && strcmp(password, a1[i].password) == 0) {
			if(a1[0+i].role == 1) {
				adminPanel();
				return; }
			else
				userPanel();
				return;
			 }
	else
	flag = 1; }
  if (flag == 1) {
  	  while (stop1 == 0) {
    printf ("Wrong login or password!\n1 - Try again\n0 - Exit\n");
    scanf("%d", &n);
    switch(n) {
  	case 1:
    authorization(stopmain); break;
  	case 0:
	stop = 1; stop1=1; flag = 0; *stopmain = 1; break;
  	default: printf("\nWrong number, please try again\n");
  }
  }
}
}
}

 void array_nulling(char *array, int *size)
{
    for (int i = 0; i < *size; i++)
    {
        *(array + i) = '\000';
    }
}



void userPanel () {
	int stop=0, n;
    while (stop==0)
    {
    	system("cls");
        printf("1 - Display information about employees\n0 - Log out\n");
        scanf("%d", &n);
        switch(n)
        {
            case 1:
            	system("cls");
                outputInformationAboutEmployeesForUser();
                system("pause");
                break;
            case 0:
            	system("cls");
            	return;
                stop=1;
                break;
            default:
                printf("Wrong number! Try again\n");
                break;
        }
    }    
}

void adminPanel() {
	int stop=0, n;
    while (stop==0)
    {
    	system("cls");
        printf("1 - Display information about employees\n2 - Add new employee\n3 - Edit information about employees\n");
		printf("4 - Delete employee\n5 - Display all users\n6 - Add new user\n7 - Edit users\n8 - Delete user\n0 - Log out\n");
        scanf("%d", &n);
        switch(n)
        {
            case 1:
            	system("cls");
                outputInformationAboutEmployeesForAdmin();
                break;
            case 2:
            	system("cls");
                addNewEmployee(); break;
           case 3:
           	system("cls");
              editInformationAboutEmployees();
            break;
            case 4:
            	system("cls");
               deleteEmployee();
               break;
            case 5:
            	system("cls");
                outputUsers();
                system("pause");
                break;
            case 6:
            	system("cls");
               addNewUser();
               break;
            case 7:
            	system("cls");
               editUsers();
               break;
            case 8:
            	system("cls");
            deleteUser();
            break;
            case 0:
            	system("cls");
                return;
                stop=1;
                break;
            default:
            	system("cls");
                printf("\nWrong number! Try again\n");
                system("pause");
                break;
        }
    }
	
}

void outputInformationAboutEmployeesForUser () {
	for (int i = 0; i < EmployeeID; i++) {
	printf("%d. | FIO: %s %s %s |",  1+i, a[i].employeeSurname, a[i].employeeName, a[i].employeePatronymic);
	printf(" Number of children: %d | Benefit: %.2f\n", a[i].n_children, a[i].benefit); }
}

void outputInformationAboutEmployeesForAdmin () {
	int n, sel;
	outputInformationAboutEmployeesForUser();
printf("1 - View information about children\n0-Exit\n");
scanf("%d", &n);
switch(n) {
case 0: break;
case 1: system("cls");
        outputInformationAboutEmployeesForUser();
        printf("\nSelect number of employee for view information about children (0 - Exit): ");
        scanf("%d", &sel);
        system("cls");
        outputChildren(sel);
        system("pause");
		break;
default: printf("Wrong number! Try again"); break;
}
}

void addNewEmployee () {

	printf("Enter FIO: ");
    scanf("%s %s %s", &(a + EmployeeID)->employeeSurname, &(a + EmployeeID)->employeeName, &(a + EmployeeID)->employeePatronymic);
    printf("Enter number of children: "); 
	scanf("%d", &(a + EmployeeID)->n_children);
	system("cls");	
	if (a[0 + EmployeeID].n_children == 0) 
	printf("New Employee was added!");
	else {		
	for(int tmp = 0; tmp < a[0+EmployeeID].n_children; tmp++) {
	printf("Enter FIO of child: ");
    scanf("%s %s %s", &b[0 + EmployeeID][0 + tmp].childSurname, &b[0 + EmployeeID][0 + tmp].childName, &b[0 + EmployeeID][0 + tmp].childPatronymic);
	printf("\nEnter date of birthday:\nDay: ");
    scanf("%d", &b[0 + EmployeeID][0 + tmp].day);
    printf("Month: ");
    scanf("%d", &b[0 + EmployeeID][0 + tmp].month);
    printf("Year: ");
    scanf("%d", &b[0 + EmployeeID][0 + tmp].year);
    system("cls");
}
    printf("New Employee was added!\n");   
}
    benefitCalculation(EmployeeID);
    EmployeeID++;
	system("pause"); 
}

void benefitCalculation(int n) {
	int tmp1 = 0;
float tmpbenefit = 0.00;
   if (a[0+n].n_children == 0)
   tmpbenefit = 0.00;
   else {
   	for (int tmp = 0; tmp < a[0+n].n_children; tmp++) {
   		if ((b[0+n][0+tmp].year == 2019 && b[0+n][0+tmp].month == 12) || (b[0+n][0+tmp].year > 2019)) {
   			tmp1++;
   		switch(tmp1) {
   		case 1: tmpbenefit = tmpbenefit + BASICAMOUNT; break;
   		case 2: tmpbenefit = tmpbenefit + 1.25*BASICAMOUNT; break;
   		default: tmpbenefit = tmpbenefit + 1.5*BASICAMOUNT; break;
   	}
   	}
   		else 
   		tmpbenefit = tmpbenefit + 0;
   		
	   }
   } 
   a[0+n].benefit = tmpbenefit;
   }

void editInformationAboutEmployees()
{
    int stop = 0, n, stop1 = 0, n1 = 0;
    while (stop == 0)
    {
        outputInformationAboutEmployeesForUser();
        printf("Enter number of employee for edit(0-Exit): ");
        scanf("%d", &n);
        if ((n < 0) || (n > EmployeeID))
            printf("Wrong number, please try again\n");
        else if (n == 0)
            stop = 1;
        else
            while (stop1 == 0)
            {   system("cls");
                printf("1 - Edit surname\n2 - Edit name\n3 - Edit patronymic\n4 - Edit information about children: \n0 - Exit\n");
                scanf("%d", &n1);
                switch (n1)
                {
                case 1:
                    system("cls");
                    fflush(stdin);
                    printf("Enter new surname: ");
                    scanf("%s", &(a + n - 1)->employeeSurname);
                    printf("Surname has been changed\n");
                    system("pause"); break;
                case 2:
                    system("cls");
                    fflush(stdin);
                    printf("Enter new name: ");
                    scanf("%s", &(a + n - 1)->employeeName);
                    printf("Name has been changed\n");
                    system("pause"); break;
                case 3:
                    system("cls");
                    fflush(stdin);
                    printf("Enter new patronymic: ");
                    scanf("%s", &(a + n - 1)->employeePatronymic);
                    printf("Patronymic has been changed\n");
                    system("pause"); break;
                case 4: 
                    editeInformationAboutChildren(n);
                case 0:
                    stop1 = 1; break;
                default:
                    system("cls");
                    fflush(stdin);
                    printf("Wrong number, please try again\n");
                    system("pause"); break;
                }
            }         
    }  
}

void editeInformationAboutChildren(int n)
{
	int n1=0, stop4=0;
system("cls");
fflush(stdin);
while (stop4 == 0) {
    outputChildren(n);
	printf("1 - Change information about current children\n2 - Add new child\n3 - Delete child\n0 - Exit\n");
    scanf("%d", &n1);
    switch(n1) {
    case 1:
        system("cls");
        editeInformationAboutCurrentChildren(n); break;
    case 2:
		system("cls");  
	 	addNewChild(n); break;
    case 3: 
        system("cls");
        deleteChild (n); break;
    case 0:
        system("cls");
        stop4 = 1; break;
    default:
        system("cls");
        fflush(stdin);
        printf("Wrong number, please try again\n");
        system("pause");
        break;
    }     
benefitCalculation(n-1); }	
}

 void outputChildren(int n) 
 {
    for (int i = 0; i < a[n-1].n_children; i++) {
    printf("%d. | FIO: %s %s %s |", i+1, b[n -1][0+i].childSurname, b[n-1][0+i].childName, b[n-1][0+i].childPatronymic);
	printf(" Date of birthday: %d.%d.%d\n", b[n-1][0+i].day, b[n-1][0+i].month, b[n-1][0+i].year);
}
                     	           	
 }

 void editeInformationAboutCurrentChildren(int n) {
 	int stop3 = 0, sel, n2;
 	system("cls");
    outputChildren(n);
	printf("Select number of children: ");
    scanf("%d", &sel);
    while (stop3 == 0) {   
	system("cls");
    printf("1 - Edit surname\n2 - Edit name\n3 - Edit patronymic\n4 - Edit date of birthday: \n0 - Exit\n");
    scanf("%d", &n2);
    switch (n2) {
        case 1:
            system("cls");
            fflush(stdin);
            printf("Enter new surname: ");
            scanf("%s", &b[n-1][sel-1].childSurname);
            printf("Surname has been changed\n");
            system("pause"); break;
        case 2:
            system("cls");
            fflush(stdin);
            printf("Enter new name: ");
            scanf("%s", &b[n-1][sel-1].childName);
            printf("Name has been changed\n");
            system("pause"); break;
        case 3:
            system("cls");
            fflush(stdin);
            printf("Enter new patronymic: ");
            scanf("%s", &b[n-1][sel-1].childPatronymic);
            printf("Patronymic has been changed\n");
            system("pause"); break;
        case 4: 
            system("cls");
            fflush(stdin);
            printf("Day: ");
            scanf("%d", &b[n-1][sel-1].day);
            printf("Month: ");
            scanf("%d", &b[n-1][sel-1].month);
            printf("Year: ");
            scanf("%d", &b[n-1][sel-1].year);
            printf("Day of birthday has been changed\n");
            system("pause"); break;
        case 0:
            system("cls"); stop3 = 1; break;
        default:
            system("cls");
            fflush(stdin);
            printf("Wrong number, please try again\n");
            system("pause"); break;
	    }    
    }         	
}
 
 void addNewChild(int n)
 {
 	printf("Enter FIO of child: ");
    scanf("%s %s %s", &b[n-1][a[n-1].n_children].childSurname, &b[n-1][a[n-1].n_children].childName, &b[n-1][a[n-1].n_children].childPatronymic);
	printf("\nEnter date of birthday:\nDay: ");
    scanf("%d", &b[n-1][a[n-1].n_children].day);
    printf("Month: ");
    scanf("%d", &b[n-1][a[n-1].n_children].month);
    printf("Year: ");
    scanf("%d", &b[n-1][a[n-1].n_children].year);
    system("cls"); 
    a[n-1].n_children++;
 }
 
 void deleteChild(int n) {
 int stop5 = 0, sel1;
    while (stop5 == 0) {
    	system("cls");
        outputChildren(n);
		printf("Select number of children(0 - Exit): ");
		scanf("%d", &sel1);
		if (sel1 == 0)
        stop5 = 1;
        else
        {
        for (int i1 = sel1 - 1; i1 < a[n-1].n_children; i1++)
        {
         strcpy(b[n-1][i1].childSurname, b[n-1][i1+1].childSurname);
         strcpy(b[n-1][i1].childName, b[n-1][i1+1].childName);
         strcpy(b[n-1][i1].childPatronymic, b[n-1][i1+1].childPatronymic);
         b[n-1][i1].day = b[n-1][i1+1].day;
         b[n-1][i1].month = b[n-1][i1+1].month;
         b[n-1][i1].year = b[n-1][i1+1].year;
        }
         a[n-1].n_children--;
         benefitCalculation(n);
         printf("Delete child successfully\n");
         system("pause");
        }
        }	
 }

void deleteEmployee()
{
    int stop = 0, n, i;
    while (stop == 0)
    {
        outputInformationAboutEmployeesForUser();
        if (EmployeeID > 0)
        {
            printf("Enter the employee's number(0-Exit): ");
            scanf("%d", &n);
            if (n == 0)
                stop = 1;
            else
            {
                for (i = n - 1; i < EmployeeID - 1; i++)
                {
                    strcpy((a + i)->employeeSurname, (a + i + 1)->employeeSurname);
                    strcpy((a + i)->employeeName, (a + i + 1)->employeeName);
                    strcpy((a + i)->employeePatronymic, (a + i + 1)->employeePatronymic);
                    (a + i)->n_children = (a+i+1)->n_children;
                    (a + i)->benefit = (a+i+1)->benefit;
                    for (int k = 0; k < (a+i+1)->n_children; k++)
                    b[0+i][0+k] = b[0+i+1][0+k]; 
                }
                EmployeeID--;
                printf("Delete employee successfully\n");
            }
        }
        else
        {
            stop = 1;
            system("pause");
        }
    }
}

void outputUsers()
{
    system("cls");
    fflush(stdin);
    printf("A list of users:\n");
    for (int i = 0; i < UserID; i++)
        printf("%d. Login: %s  Password: %s  Role: %d\n", i + 1, (a1 + i)->login, (a1 + i)->password, (a1 + i)->role);
        
}

void addNewUser()
{
    int i, stop = 0;
    while (stop == 0)
    {
        system("cls");
        fflush(stdin);
        printf("Enter login: ");
        scanf("%s", &((a1 + UserID)->login));
        printf("Enter Password: ");
        scanf("%s", &((a1 + UserID)->password));
        printf("Enter Role(1-admin or 2-user): ");
            scanf("%d", &((a1 + UserID)->role));
            if ((a1 + UserID)->role == 1 || (a1 + UserID)->role == 2)
            {
                printf("New user was added\n");
                UserID++;
                stop = 1;
                system("pause");
            }
            else
            {
                printf("Wrong number of role, please try again\n");
                system("pause");
            }
        }
    }
    
void editUsers() {
    int stop = 0, n, stop1 = 0, n1, stop2 = 0;
    while (stop == 0) {
        outputUsers();
        printf("Enter number of user for edit(0-Exit): ");
        scanf("%d", &n);
        if ((n < 0) || (n > UserID))
            printf("Wrong number, please try again\n");
        else if (n == 0)
            stop = 1;
        else
            while (stop1 == 0) {   
			    system("cls");
                printf("1 - Edit login\n2 - Edit password\n3 - Edit role\n0 - Exit\n");
                scanf("%d", &n1);
                switch (n1)
                {
                case 1: 
				    system("cls");
                    printf("Enter new login: ");
                    scanf("%s", &(a1 + n - 1)->login);
                    printf("Login has been changed\n");
                    system("pause"); break;
                case 2:
                    system("cls");
                    printf("Enter new password: ");
                    scanf("%s", &(a1 + n - 1)->password);
                    printf("Password has been changed\n");
                    system("pause"); break;
                case 3:
                    while (stop2 == 0) {
                        system("cls");
                        printf("Enter new role(1-admin or 2-user): ");
                        scanf("%d", &(a1 + n - 1)->role);
                        if ((a1 + n - 1)->role == 1 || (a1 + n - 1)->role == 2)
                            stop2 = 1;
                        else
                            printf("Wrong number, please try again\n");
                    }
                    printf("Role has been changed\n");
                    system("pause"); break;
                case 0:
                    stop1 = 1; break;
                default:
                    system("cls");
                    printf("Wrong number, please try again\n");
                    system("pause"); break;
                }
            }
    }
}

void deleteUser()
{
    int stop = 0, n, i;
    while (stop == 0)
    {
        outputUsers();
        if (UserID >= 1)
        {
            printf("Enter the user's number(0-Exit): ");
            scanf("%d", &n);
            if (n == 0)
                stop = 1;
            else
            {
                for (i = n - 1; i < UserID - 1; i++)
                {
                    strcpy((a1 + i)->login, (a1 + i + 1)->login);
                    strcpy((a1 + i)->password, (a1 + i + 1)->password);
                    (a1 + i)->role = (a1+i+1)->role; 
                }
                UserID--;
                printf("Delete user successfully\n");
                system("pause");
            }
        }
        else
        {
            stop = 1;
            system("pause");
        }
    }
}