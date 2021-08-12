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
    uint8_t i = 0;
    uint8_t j = 0;
    uint8_t k = 0;

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

    //Perform the pivot

}