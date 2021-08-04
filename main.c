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

int main(void) {
    // ss = vadd_u32( aa, bb);
    printf("\n");
    
    //2x2 Matrix Inversion: [M]^-1 = 1/(a*d - b*c) * [M]
    int matrix[3][3] = {    
                        {3, 2, -4}, 
                        {2, 3, 3}, 
                        {5, -3, 1} 
                    };


    unsigned char row = sizeof(matrix) / sizeof(matrix[0]);
    unsigned char col = (sizeof(matrix)/sizeof(matrix[0][0]))/row;
    printMatrix(matrix, row, col);    


      ////////////////////
     /// AUGMENTATION ///
    ////////////////////
    unsigned char i = 0;
    unsigned char j = 0;
    unsigned char mat_i = 0;
    unsigned char mat_j = order;

    int augmented_matrix[3][2*order];

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
    //////////////////////////////////////////////////

    row = sizeof(augmented_matrix) / sizeof(augmented_matrix[0]);
    col = (sizeof(augmented_matrix)/sizeof(augmented_matrix[0][0]))/row;
    printMatrix(augmented_matrix, row, col);    


      ////////////////////
     ///     PIVOT    ///
    ////////////////////
    unsigned char first_op;
    unsigned char second_op;
    unsigned char m = 0;

    for(m = 0; m < order; m++){
        first_op = augmented_matrix[m][m];

        for(i = 0; i < order ; i++){ 
            second_op = augmented_matrix[i][m];

            for(j = 0; j < 2*order; j++){
                if(i != m){
                    augmented_matrix[i][j] = first_op*augmented_matrix[i][j] - second_op*augmented_matrix[m][j];
                }
            }
        } 
    }


    printMatrix(augmented_matrix, row, col);    


      ////////////////////
     ///   DIVISION   ///
    ////////////////////

    // for(i = 0; i < order ; i++){ 
    //     for(j = order; j < 2*order; j++){
    //         augmented_matrix[i][j] = augmented_matrix[i][j] / augmented_matrix[i][i];
    //     }
    // }

    // int k = 0;
    // // collect the inverted matrix
    // for(i = 0; i < order ; i++){ 
    //     k = 0;
    //     for(j = order; j < 2*order; j++){
    //         inv_matrix[i][k++] = augmented_matrix[i][j];
    //     }
    // }

}


  /////////////////
 /// FUNCTIONS ///
/////////////////

//prints a matrix to terminal
void printMatrix(int (*matrix)[2], int row, int col) {
    
    //increment variables
    unsigned char x;
    unsigned char y;

    printf("Size of Matrix is: %dx%d\n", row, col);

    for(x=0; x<row; x++){
        for(y=0; y<col; y++){
            printf("[%d]", matrix[x][y]);
        }
        printf("\n");
    }
    printf("\n");
}


void augment_matrix(){
    //Augmentation variables

}