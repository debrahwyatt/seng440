  /////////////////////
 ///    HEADERS    ///
/////////////////////

#include <stdio.h>
#include "arm_neon.h"


  ////////////////////////
 /// GLOBAL VARIABLES ///
////////////////////////

// Matrix dimentions
#define n 3
uint8_t m = n * 2;    


  ////////////////////
 ///   FUNCTIONS  ///
////////////////////

//prints a matrix to terminal
void printMatrix( int16_t *M, uint8_t m, uint8_t i, uint8_t j ) {
    
    //Print the starting matrix
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            printf("%i ",  M[i*m + j]);
        }
        printf("\n");
    }
    printf("\n");
}

//The first step in Augmentation
void initializeAugmentation( int16_t *A, int16_t *M, uint8_t m, uint8_t i, uint8_t j ) {
    
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            if( j < n ){
                A[ i*m + j ] = M[ i*n + j ];
            }
            else if(j-n == i){
                A[ i*m + j ] = 1;
            }
            else{
                A[ i*m + j ] = 0;
            }
        }
    }
}


  ////////////////////
 /// PROGRAM MAIN ///
////////////////////

void main(){

    //Program variables
    uint8_t i;
    uint8_t j;
    uint8_t k;

    //Starting matrix
    int16_t M[] = {
        1, 2, 3, 
        4, 5, 6, 
        7, 8, 9
    };
    
    // Print the starting matrix
    printf("\n");
    printMatrix( M, n, i, j );

    //The augmented matrix shell
    int16_t A[18];
    initializeAugmentation( A, M, m, i, j );

    //Prints the augmented matrix
    printMatrix( A, m, i, j );

      ////////////////////
     ///     PIVOT    ///
    ////////////////////
    
    uint8_t first_op;
    uint8_t second_op;    

    for(k = 0; k < n; k++){
        first_op = A[ k*n + k ];

        for(i = 0; i < n ; i++){ 
            second_op = A[ i*n + k ];

            for(j = 0; j < m; j++){
                if(i != k){
                    A[ i*m + j ] = first_op*A[ i*m + j ] - second_op*A[ k*m + j];
                }
            }
        } 
    }


    // for(k = 0; k < order; k++){
    //     first_op = augmented_matrix[k][k];

    //     for(i = 0; i < order ; i++){ 
    //         second_op = augmented_matrix[i][k];

    //         for(j = 0; j < 2*order; j++){
    //             if(i != k){
    //                 augmented_matrix[i][j] = first_op*augmented_matrix[i][j] - second_op*augmented_matrix[k][j];
    //             }
    //         }
    //     } 
    // }


    //Prints the augmented matrix
    printMatrix( A, m, i, j );
}