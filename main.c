  ////////////////
 /// PACKAGES ///
////////////////
#include <stdio.h>
#include "arm_neon.h"
uint32x2_t aa, bb, ss;
// -std=c99

  ////////////////////////////
 /// FUNCTION DECLARATION ///
////////////////////////////
void printMatrix(int (*)[], int N);


  ////////////////////
 /// PROGRAM MAIN ///
////////////////////

int main( void) {
    // ss = vadd_u32( aa, bb);
    printf("\n");
    
    //2x2 Matrix Inversion: [M]^-1 = 1/(a*d - b*c) * [M]
    int M[2][2] = {
                    {1, 2}, 
                    {3, 4}
                };

    //Determaine the length of the square matrix
    int N = sizeof(M) / sizeof(M[0]);
    printf("Size of Matrix is: %dx%d\n", N, N);
    
    //Print the matrix
    printMatrix(M, N);    
}


  /////////////////
 /// FUNCTIONS ///
/////////////////

//prints a matrix to terminal
void printMatrix(int (*M)[2], int N) {
    
    int i;
    int j;

    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            printf("[%d]", M[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
