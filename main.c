  ////////////////
 /// PACKAGES ///
////////////////
#include <stdio.h>
#include "arm_neon.h"
// uint32x2_t aa, bb, ss;
// -std=c99

//Global variables
#define order 3


  ////////////////////////////
 /// FUNCTION DECLARATION ///
////////////////////////////
void printMatrix(int (*)[], int row, int col);


  ////////////////////
 /// PROGRAM MAIN ///
////////////////////

int main( void) {
    // ss = vadd_u32( aa, bb);
    printf("\n");
    
    //2x2 Matrix Inversion: [M]^-1 = 1/(a*d - b*c) * [M]
    int matrix[3][3] = {    
                        {3, 2, -4}, 
                        {2, 3, 3}, 
                        {5, -3, 1} 
                    };

    //Determaine the length of the square matrix
    int row = sizeof(matrix) / sizeof(matrix[0]);
    int col = (sizeof(matrix)/sizeof(matrix[0][0]))/row;

    printMatrix(matrix, row, col);    


    /////////////////////////////////////////////
    //Augmentation function /////////////////////
    /////////////////////////////////////////////
    int i = 0;
    int j = 0;
    int mat_i = 0;
    int mat_j = order;
    int augmented_matrix[3][2*order];


    for(i = 0; i < order; i++){
        for(j = 0; j < order*2; j++){
            if( (i < order) && (j < order) ){
                augmented_matrix[i][j] = matrix[i][j];
                printf("[%d]", matrix[i][j]);

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
    //////////////////////////////////////////////////

    row = sizeof(augmented_matrix) / sizeof(augmented_matrix[0]);
    col = (sizeof(augmented_matrix)/sizeof(augmented_matrix[0][0]))/row;
    printf("Augmented Matrix row size is: %d\n", row);
    printf("Augmented Matrix col size is: %d\n", col);
    // printf("Augmented Matrix [0][0] is: %d\n", matrix[0][0]);

    // printMatrix(augmented_matrix, row, col);    



}


  /////////////////
 /// FUNCTIONS ///
/////////////////

//prints a matrix to terminal
void printMatrix(int (*matrix)[2], int row, int col) {
    
    // int row = sizeof(matrix) / sizeof(matrix[0]);
    // int col=(sizeof(matrix)/sizeof(matrix[0][0]))/row;
    // int col = N;
    // int row = N;

    printf("Size of Matrix is: %dx%d\n", row, col);

    int i;
    int j;

    for(i=0; i<row; i++){
        for(j=0; j<col; j++){
            printf("[%d]", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void augment_matrix(){
    //Augmentation variables

}