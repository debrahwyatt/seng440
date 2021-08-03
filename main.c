  ////////////////
 /// PACKAGES ///
////////////////
#include <stdio.h>
#include "arm_neon.h"
// uint32x2_t aa, bb, ss;
// -std=c99

//Global variables
#define order 2


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

void augment_matrix(){
    //Augmentation variables
    int i = 0;
    int j = 0;
    int mat_i = 0;
    int mat_j = order;
    int augmented_matrix[3][3*order] = {
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0}
    };


    for(i = 0; i < order; i++){
        for(j = 0; j < order*2; j++){
            if( (i < order) && (j < order) ){
                augmented_matrix[i][j] = matrix[i][j];
            }
            else if(i == mat_i && j == mat_j) {
               augmented_matrix[i][j] = 1;
               mat_i++;
               mat_j++;
            }
            else{
                augmented_matrix[i][j] = 0;
            }
        }
    }
}