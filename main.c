  ////////////////
 /// PACKAGES ///
////////////////
#include <stdio.h>
#include <math.h>
// #include "arm_neon.h"
// uint32x2_t aa, bb, ss;
// -std=c99

//Global variables
#define order 3
#define scale 8


  ////////////////////////////
 /// FUNCTION DECLARATION ///
////////////////////////////

void printMatrix(short (*)[], unsigned char row, unsigned char col);


  ////////////////////
 /// PROGRAM MAIN ///
////////////////////

int main(void) {
    printf("\n");
    
    // A 3x3 example matrix
    short matrix[3][3] = {    
                        {3, 2, -4}, 
                        {2, 3, 3}, 
                        {5, -3, 1} 
                    };

    //system variables
    unsigned char i = 0;
    unsigned char j = 0;
    unsigned char m = 0;
    unsigned char mat_i = 0;
    unsigned char mat_j = order;

    int first_op;
    int second_op;    

    int augmented_matrix[3][order*2];
    int inv_matrix[3][3];

    // unsigned char row = sizeof(matrix) / sizeof(matrix[0]);
    // unsigned char col = (sizeof(matrix)/sizeof(matrix[0][0]))/row;


    ///////////////////
    ///Print matrix///
    /////////////////

    // printf("Size of Matrix is: %dx%d\n", row, col);
    // for(i=0; i<row; i++){
    //     for(j=0; j<col; j++){
    //         printf("[%d]", matrix[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");
    ///////////////////////////////////////////


      ////////////////////
     /// AUGMENTATION ///
    ////////////////////

    // Sets up the matrix adjacent to an identity matrix
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


    /////////////////////////////
    ///Print Augmented matrix///
    ///////////////////////////

    // row = sizeof(augmented_matrix) / sizeof(augmented_matrix[0]);
    // col = (sizeof(augmented_matrix)/sizeof(augmented_matrix[0][0]))/row;
    // printf("Size of Matrix is: %dx%d\n", row, col);
    // for(i=0; i<row; i++){
    //     for(j=0; j<col; j++){
    //         printf("[%d]", augmented_matrix[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");
    ///////////////////////////////////////////


      ////////////////////
     ///     PIVOT    ///
    ////////////////////

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





      ////////////////////
     ///   DIVISION   ///
    ////////////////////

    for(i = 0; i < order ; i++){ 
        for(j = order; j < 2*order; j++){
            augmented_matrix[i][j] = (augmented_matrix[i][j] << scale ) / augmented_matrix[i][i];
        }
    }

    int k = 0;
    // collect the inverted matrix
    for(i = 0; i < order ; i++){ 
        for(j = order; j < 2*order; j++){
            // inv_matrix[i][k++] = augmented_matrix[i][j];
            printf("[%d]", augmented_matrix[i][j]/pow(2,scale));
        }
        printf("\n");
    }
    printf("\n");

    /////////////////////////////
    ///Print Augmented matrix///
    ///////////////////////////
    
    // printf("[%d]", inv_matrix[0][0]);

    // for(i=0; i<3; i++){
    //     for(j=0; j<3; j++){
    //         printf("[%d]", inv_matrix[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");
    /////////////////////////////////////////////////

}


  /////////////////
 /// FUNCTIONS ///
/////////////////

//prints a matrix to terminal
void printMatrix(short (*matrix)[2], unsigned char row, unsigned char col) {
    
    // //increment variables
    // unsigned short x;
    // unsigned short y;

    // printf("Size of Matrix is: %dx%d\n", row, col);

    // for(x=0; x<row; x++){
    //     for(y=0; y<col; y++){
    //         printf("[%d]", matrix[x][y]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");
    // printf("[%d]", matrix[1][0]);

}


void augment_matrix(){
    //Augmentation variables

}