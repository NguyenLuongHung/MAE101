#include <stdio.h>





void enterMatrix(int s[][100], int a, int b){ // Input a Matrix

	printf ("Please enter a Matrix!\n");

	for (int i = 1; i <= a; i++){

		for (int j = 1; j <= b; j++){

			printf ("s[%d][%d] = ", i,j);

			scanf ("%d", &s[i][j]);

		}

	}

}



void displayMatrix( int s[][100], int a, int b){ // Display a Matrix

	for (int i = 1; i <= a; i++){

		for (int j = 1; j <= b; j++){

			printf ("%5d", s[i][j]);

		}

		printf ("\n");

	}

}



void addMatrix(int s[][100], int s1[][100],int s2[][100], int a, int b, int c, int d){ // add 2 Matrix

	if (a != c || b != d){

		printf ("Cannot Calculate");

	}

	else if ( a == c && b == d){

		for (int i = 1; i <= a; i++){

			for (int j = 1; j <= b; j++){

				s2[i][j] = s[i][j] + s1[i][j];

			}

		}

	}

}



void minusMatrix(int s[][100], int s1[][100], int s2[][100], int a, int b, int c, int d){ // minus 2 Matrix

	if (a != c || b != d){

		printf ("Cannot Calculate");

	}

	else if ( a == c && b == d){

		for (int i = 1; i <= a; i++){

			for (int j = 1; j <= b; j++){

				s2[i][j] = s[i][j] - s1[i][j];

			}

		}

	}

}

int x = 0;

void multiplyMatrix (int s[][100], int s1[][100], int s2[][100], int a, int b, int c, int d){ // multiply 2 Matrix

	if ( b == c){

		for (int i = 1; i <= a; i++){

			for (int j = 1; j <= d; j++){

				for (int l = 1; l <= b; l++){

					s2[i][j] = s2[i][j] + s[i][l] * s1[l][j];

				}

			}

		}

	}

}



void clearMatrix(int s[][100], int a, int b){

	for (int i = 1; i <= a; i++){

		for (int j = 1; j <= b; j++){

			s[i][j] = 0;

		}

	}	

}



void selectOrder(int s[][100], int s1[][100], int s2[][100], int a, int b, int c, int d){ // Choose Options 

	int e;

	char f;

	printf ("Choose the following options to calculate: \n");

	printf ("(1) Adding 2 Matrixes.\n");

	printf ("(2) Minusing 2 Matrixes.\n");

	printf ("(3) Multiply 2 Matrixes.\n");

	printf ("Your choice: ");

	scanf ("%d%c", &e, &f);

	

	if (e == 1){

		addMatrix(s, s1, s2, a, b, c, d);

		printf ("Your Matrix after Adding: \n"); // Adding

		displayMatrix (s2, a, b);

		clearMatrix(s2,a ,b);

	}

	

	else if (e == 2){

		minusMatrix(s, s1, s2, a, b, c, d);

		printf ("Your Matrix after Minusing: \n"); // Minusing

		displayMatrix (s2, a, b);

		clearMatrix(s2, a , b);

	}

	else if (e == 3){

		multiplyMatrix(s, s1, s2, a, b, c, d);

		printf ("Your Matrix after Multiplying: \n"); // Multyplying

		displayMatrix (s2, a, d);

		clearMatrix(s2, a ,d);

	}

}





int main(){

	char g, h;

	int a, b, c, d;

	int m[100][100], n[100][100], v[100][100];

	do {

	printf ("Please enter the size of first Matrix: Row(s) X Collumn(s) \n");

	printf ("Row(s) = ");

	scanf ("%d", &a);

	printf ("Collumn(s) = ");

	scanf ("%d", &b);

	

	enterMatrix(m, a, b); // Enter the size of first Matrix

	

	printf ("Please enter the size of the second Matrix: Row(s) X Collumn(s) \n");

	printf ("Row(s) = ");

	scanf ("%d", &c);

	printf ("Collumn(s) = ");

	scanf ("%d", &d);

	

	enterMatrix(n, c, d); // Enter the size of second Matrix

	

	printf ("Your first Matrix is: \n");

	displayMatrix(m, a, b); // Display the size of first Matrix

	printf ("Your second Matrix is: \n");

	displayMatrix(n, c, d); // Display the size of second Matrix

	

	selectOrder(m, n, v, a, b, c, d);

	

	

	printf ("Do you want to run again? (y/n)");

	

	scanf ("%c%c", &g, &h);

	printf ("\n");

	printf ("--------------------------------------------------------------------------");

	printf ("\n");

	} while (g == 'y');



}
