/* 
This is the source code to calculate the inverse of one Square Matrix 3x3
Made By: BiDD Nguyen
University: FPT
Major: Information Assurance (IA1301)
Country: Vietnam
Date: 11/03/2018
P/s: If you got any questions, error reports or advices, please send to the following email: luonghung.qb@gmail.com, i really appreciate that.

The idea of this algorithm contains 4 steps:
	1. Calculate The Matrix of Minors
	2. Calculate the Matrix of Cofactors
	3. Calculate the Adjugate of Matrix
	4. Calculate the Inverse of Matrix: Inverse = 1/Determinant * Adjugate 
*/

#include <stdio.h>

void inputMatrix( float s[][100], int a){ // Input a Square Matrix
	printf ("Please enter a Matrix!\n");
	for (int i = 1; i <= a; i++){
		for (int j = 1; j <= a; j++){
			printf ("s[%d][%d] = ", i, j);
			scanf ("%f", &s[i][j]);
		}
	}
}

void displayMatrix(float s[][100], int a){ // Display the Matrix
	for (int i = 1; i <= a; i++){
		for (int j = 1; j <= a; j++){
			printf ("%20.2f", s[i][j]);
		}
		printf ("\n");
	}
	
}

void copyMatrix(float s[][100], float s1[][100], int a){ // Copy the origin Matrix to another one
	for (int i = 1; i <= a; i++){
		for ( int j = 1; j <= a; j++){
			s1[i][j] = s[i][j];
		}
	}
}

void minorTrans(int i, int j, float s[][100], float s1[][100]){ // Transfer one 3x3 Matrix to its Minor 2x2
	int m, n = 1;
	for (int p = 1; p <= 3; p++){
		for (int q = 1; q <= 3; q++){
			while (p != i && q != j && m <= 2){
				s1[m][n] = s[p][q];
				n++;
				if (n == 3 || m == 3){
					n = 1;
					m++;
				}
				break;
			}
		}
	}
}
		






float detMatrix2(float s[][100]){ // Calculate the Determiant of 2x2 Matrix
	float detA;
	detA = ( s[1][1] * s[2][2] ) - ( s[1][2] * s[2][1] );
	return detA;
}


void cofactorTrans(float s[][100]){ // Transfer the 3x3 Matrix of Minors to 3x3 Matrix of Cofactors
	for (int i = 1; i <= 3; i++){
		for (int j = 1; j <= 3; j++){
			if ( (i + j) % 2 == 0)
				s[i][j] = s[i][j];
			else if ( (i + j) % 2 == 1)
				s[i][j] = -s[i][j];
		}
	}

}

void transposeMatrix(float s[][100]){ // Tranpose a Matrix
	for (int i = 1; i <= 3; i++){
		for (int j = 1; j <= 3; j++)
			s[i][j] = s[j][i];
	}
	
}

void adjugateOfMinors3(float s[][100], float s1[][100], float s2[][100], float s3[][100]){ // Calculate the adjugate of 3x3 Matrix
	int i, j;
	copyMatrix(s, s1, 3);
	for ( i = 1; i <= 3; i++ ){
		for ( j = 1; j <= 3; j++){
			minorTrans(i, j, s1, s2);
			s3[i][j] = detMatrix2(s2); // Calculate the coefficent of Matrix Of Minors		
		}
	}
	cofactorTrans(s3);
	transposeMatrix(s3);

}

void inverseOfMatrix3(float s[][100], float a){ // Calculate the inverse of a 3x3 Matrix
	for (int i = 1; i <= 3; i++){
		for (int j = 1; j <= 3; j++){
			s[i][j] = s[i][j] * (1.0/a);
		}
	}
}

int main(){
	int a;
	float detA, c; 
	float m[100][100], n[100][100], v[100][100], b[100][100];
	printf ("Please input the size of Square Matrix: ");
	scanf ("%d", &a);
	inputMatrix(m, a);
	printf ("Your matrix is: \n");
	displayMatrix(m, a);
	adjugateOfMinors3(m, n, v, b);
	printf ("Your s3 Matrix is: \n");
	displayMatrix(b, a);
	c = detMatrix2(m, 2);
	printf ("detA = %f", c);
	
	

}


