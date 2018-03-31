#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

// s = Book code, s1 = book name, s2 = unit price, s3 = quantity

void istolower(char name[]){
	for (int i = 0; i < 30; i++){
		name[i] = tolower(name[i]);
	}
}

void defaultBook(char s[][MAX], char s1[][MAX], double s2[], int s3[]){
	strcpy(s[0], "A00001");
	strcpy(s[1], "A00002");
	strcpy(s[2], "A00003");
	strcpy(s[3], "A00004");
	strcpy(s1[0], "The Lord of The Rings");
	strcpy(s1[1], "Harry Porter");
	strcpy(s1[2], "Forest Gump");
	strcpy(s1[3], "Ice and Fire");
	s2[0] = 300;
	s2[1] = 200;
	s2[2] = 100;
	s2[3] = 150;
	s3[0] = 2;
	s3[1] = 1;
	s3[2] = 4;
	s3[3] = 2; 
}

void display(char s[][MAX], char s1[][MAX], double s2[], int s3[], int n){
	char name[4][100] = {"Book Code", "Book Name", "Unit Price", "Quantity"};
	for (int i = 0; i < 4; i++){
		printf ("%-30s", name[i]);
	}
	printf ("\n");
	for (int j = 0; j < n; j++){
		printf ("%-30s", s[j]);
		printf ("%-30s", s1[j]);
		printf ("%-30.2f", s2[j]);
		printf ("%-30d", s3[j]);
		printf ("\n");
	}
}

void addBook(char s[][MAX], char s1[][MAX], double s2[], int s3[], int &n){
	int check = 0;
	int check1 = 0;
	int check2 = 0;
	int check3 = 0;
	int check4 = 0;
	int check5 = 0;
	int m;
	int l;

	printf ("How many books do you want to add: ");
	scanf ("%d", &m);
	printf ("-----\n\n");
	printf ("You have to enter the code in the following form CDDDDD such C is an uppercase character, D are number and the code must contains 6 letters (E.x: A00001)\n\n");
	printf ("-----\n");
	
	for (int i = 4; i < m+4; i++){
		printf ("Book %d: \n", i+1);
		do{
			
			printf ("Enter Book Code: ");
			scanf ("%s", s[i]);
			fflush(stdin);
			
			if (strlen(s[i]) < 6 || strlen(s[i]) > 6)
				check1 = 1;
			else check1 = 0;
			
			for (int k = 1; k < 6;k++){
				if (s[i][k] < 48 || s[i][k] > 57){
					check2 = 1;
					break;
				}
				else if (s[i][k] >= 48 && s[i][k] <= 57)
					check2 = 0;
			} 
			
			
			if (s[i][0] < 65 || s[i][0] > 90){
				check3 = 1;
			}
			else if (s[i][0] >= 65 && s[i][0] <= 90)
				check3 = 0;
			
			if (check1 == 1 ){
				printf ("[**ERROR**]\n");
				printf ("Your code must contains 6 characters!\n");
				printf ("PLease re-enter\n\n");
			}
			
			if (check2 == 1 ){
				printf ("[**ERROR**]\n");
				printf ("Your code must contains 5 numbers!\n");
				printf ("PLease re-enter\n\n");
			}
			if (check3 == 1 ){
				printf ("[**ERROR**]\n");
				printf ("Your first letter must be a Uppercase letter!\n");
				printf ("PLease re-enter\n\n");
			}
			
			
			for (int j = 0; j < i; j++){
				if (strcmp(s[j],s[i]) == 0){
					check = 1;
					printf ("[**ERROR**]\n");
					printf ("The code is already exist, enter another code!\n\n");
					
					break;
				} else{
					 check = 0;
					
				}
			}
		} while (check == 1 || check1 == 1 || check2 == 1 || check3 == 1);
		do{
		printf ("Enter Book Name: ");
		scanf ("%[^\n]", s1[i]);
		fflush(stdin);
		l = strlen(s1[i]);
		if (l > 30){
			check4 == 1;
			printf ("[**ERROR**]\n");
			printf ("Your book name contains no more than 30 characters\n");
			printf ("Please re-enter!\n\n");
			
		}
		else if ( l < 30)
			check4 == 0;
		
		} while (check4 == 1);
		
		do{	
			
		printf ("Enter Price: ");
		scanf ("%lf", &s2[i]);
		if (s2[i] > 0 && s2[i] < 1000)		 	
		 		check5 = 0;		 					
		else{
			check5 = 1;
			printf ("[**ERROR**]\n");
			printf ("Your book price must be positive and less than 1000$\n");
			printf ("Please re-enter!\n\n");			
			}				
		} while (check5 == 1 );
		printf ("Enter Quantity: ");
		scanf ("%d", &s3[i]);
	}
	n = n + m;
}

void deleteBook(char s[][MAX], char s1[][MAX], double s2[], int s3[], int &n){

	char name[30];
	int idelete;
	int check = 0;
	char s1cp[30];
	char namecp[30];
	printf("Enter the name of the book that you want to delete: ");
	fflush(stdin);
	scanf("%[^\n]", name);
	

	
	for (int i = 0; i < n; i++){
		strcpy(s1cp,s1[i]);
		strcpy(namecp,name);
		istolower(s1cp);
		istolower(namecp);
		if (strcmp(s1cp,namecp) == 0){
			idelete = i;
			check = 1;
			break;
		} else {
			check = 0;
		}
	}
	
	if (check == 1)
		n = n - 1;

	if ( check == 1){
		for (int j = idelete; j < n; j++){
			strcpy(s[j],s[j+1]);
			strcpy(s1[j],s1[j+1]);
			s2[j] = s2[j+1];
			s3[j] = s3[j+1];
		
		}
	} 
	else if (check == 0) {
		printf ("---");
		printf ("\n  --->The book you want to delete does not exist\n");
		printf ("---\n");
	}
	printf ("-------------------------------------------------------------------------------------------------------------------------------------------\n");
}

int searchBook(char s[][MAX], char s1[][MAX], double s2[], int s3[],char name[], int n){
	int check;
	int isearch;
	char s1cp[30];
	char namecp[30];
	
	
	for (int i = 0; i < n; i++){
		strcpy(s1cp,s1[i]);
		strcpy(namecp,name);
		istolower(s1cp);
		istolower(namecp);
		if (strcmp(s1cp,namecp) == 0){
			isearch = i;
			check = 1;
			break;
		} 
		else {
			check = 0;
		}
	}
	
	if (check == 1){
		printf ("---------------------------------------------------------------------------------------------------------------------------------------\n");
		char name1[4][100] = {"Book Code", "Book Name", "Unit Price", "Quantity"};
		for (int i = 0; i < 4; i++){
			printf ("%-30s", name1[i]);
		}
		printf ("\n");
		printf ("%-30s", s[isearch]);
		printf ("%-30s", s1[isearch]);
		printf ("%-30.2f", s2[isearch]);
		printf ("%-30d", s3[isearch]);
		printf ("\n");
		printf ("---------------------------------------------------------------------------------------------------------------------------------------\n");
	}
	
	else if (check == 0){
		printf ("----\n\n\n");
		printf ("---> The book you want to find does not exist!\n\n\n");
		printf ("----\n");
	}
	return isearch;
}

void sortBook(char s[][MAX], char s1[][MAX], double s2[], int s3[], int n){
	int a;
	int i, j;
	char sw[n][MAX];
	char sw1[n][MAX];
	double sw2[n];
	int sw3[n];
	
	for (j = n-1; j >= 0; j--){
		for (i = 0; i < n-1; i++){
			a = strcmp(s1[i], s1[i+1]);
			if (a > 0) {
				strcpy(sw[i], s[i+1]);
				strcpy(s[i+1], s[i]);
				strcpy (s[i], sw[i]);
				strcpy(sw1[i], s1[i+1]);
				strcpy(s1[i+1], s1[i]);
				strcpy (s1[i], sw1[i]);
				sw2[i] = s2[i+1];
				s2[i+1] = s2[i];
				s2[i] = sw2[i];
				sw3[i] = s3[i+1];
				s3[i+1] = s3[i];
				s3[i] = sw3[i];			
			}
		}
	}
	display(s,s1,s2,s3,n);
}

void chooseToBuy(char s[][MAX], char s1[][MAX], double s2[], int s3[], int n, double &total){
	int a;
	int b;
	int c;
	char d;
	char name[30];
	int out = 0;
	while (out == 0){
	printf ("Enter the book you want to buy: ");
	fflush(stdin);
	scanf("%[^\n]", name);
	a = searchBook(s,s1,s2,s3,name,n);
	
	printf ("a = %d\n", a);
	
	
	
	do{
	
	printf ("Quantity: ");
	scanf ("%d", &b);
	if (b > s3[a])
		printf ("Insufficent quantity, pleaes re-enter!\n");
	} while (b > s3[a]);
	total = total + s2[a]*b;
	s3[a] = s3[a] - b; 
	
	printf ("1. Buy more\n");
	printf ("2. Check out\n");
	scanf ("%d%c",&c,&d);
	if (c == 1)
		out == 0;
	else if (c == 2){
		printf ("---------------------\n\n\n");
		printf ("\nTotal = %0.2lf\n\n\n", total);
		printf ("---------------------\n");
		break;
		}
	}
}

void option(char s[][MAX], char s1[][MAX], double s2[], int s3[], int n, double total){
	int a;
	int g = 0;
	char b;
	int c;
	char d;
	int out = 1;
	char name1[30];
	do{
	
	printf ("---------------------------------------------------------------------------------------------------------------------------------------\n");
	printf ("WELCOME TO FPT LIBRARY\n");
	printf ("1. Create 4 default books with their information\n");
	printf ("2. Add/ Delete books\n");
	printf ("3. Search book by name\n");
	printf ("4. List all books\n");
	printf ("5. List all books after sorting book by name\n");
	printf ("6. Let user to choose some books to buy and compute the total price\n");
	printf ("7. Quit\n");
	printf ("Your option (1 -> 7): ");
	scanf ("%d%c", &a,&b);
	
	printf ("---------------------------------------------------------------------------------------------------------------------------------------\n");
	
		if (a == 1){
			defaultBook(s,s1,s2,s3);
		}
		if (a == 2){
			printf ("1. Add book \n");
			printf ("2. Delete Book \n");
			scanf ("%d%c",&c,&d);
			if (c == 1)
				addBook(s,s1,s2,s3,n);
			else if ( c == 2)
				deleteBook(s,s1,s2,s3,n);
		
		}
		if (a == 3){
			printf ("Enter the book you want to find: ");
			scanf("%[^\n]", name1);
			fflush(stdin);
			searchBook(s,s1,s2,s3,name1,n);
		
		}
		if (a == 4){
			display(s,s1,s2,s3,n);
		}
		if (a == 5){
			sortBook(s,s1,s2,s3,n);
		}
		if (a == 6){
			chooseToBuy(s,s1,s2,s3,n,total);
		}
		if (a == 7){
			break;
		}
	} while (out == 1);
}

int main(){

	double total = 0;
	int n = 4;
	char s[100][100];
	char s1[100][100];
	double s2[100];
	int s3[100];
	option(s,s1,s2,s3,n,total);
	return 0;
	
	system ("pause");
}
