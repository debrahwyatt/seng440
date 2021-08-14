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
// #define m 6
uint8_t m = n * 2;    


  ////////////////////
 ///   FUNCTIONS  ///
////////////////////

//prints a matrix to terminal

void printMatrix( int16_t *M, int8_t m, int8_t i, int8_t j ) {
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            printf("%i ",  M[i*m + j]);
        }
        printf("\n");
    }
    printf("\n");
}

//The first step in Augmentation

void initializeAugmentation( int16_t *A, int16_t *M, int8_t m, int8_t i, int8_t j ) {
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

void pivot( int16_t *A, int8_t m, int8_t i, int8_t j, int8_t k ) {
    
    int16_t first_op;
    int16_t second_op;    

    for(k = 0; k < n; k++){
        first_op = A[ k*m + k ];

        for(i = 0; i < n ; i++){ 
            second_op = A[ i*m + k ];

            for(j = 0; j < m; j++){
                if(i != k){
                    A[ i*m + j ] = first_op*A[ i*m + j ] - second_op*A[ k*m + j];
                }
            }
        } 
    }
}

void collectInverse( int16_t *I, int16_t *A, int16_t m, int8_t i, int8_t j, int8_t k ) {
    for(i = 0; i < n ; i++){ 
        k = 0;
        for(j = n; j < m; j++){
            I[ i*n + k ] = A[ i*m + j ];
            k++;
        }
    }
}

  ////////////////////
 /// PROGRAM MAIN ///
////////////////////

void main(){

    //Program variables
    int8_t i;
    int8_t j;
    int8_t k;
    int16_t I[9];
    int16_t A[18];

    //Starting matrix
    int16_t M[] = {
        3, 2, -4, 
        2, 3, 3, 
        5, -3, 1
    };
    
    // Print the starting matrix
    printf("\n");
    printMatrix( M, n, i, j );

    //Augment the matrix
    initializeAugmentation( A, M, m, i, j );
    pivot( A, m, i, j, k );
    printMatrix( A, m, i, j );

    // Real -> integer
    // Integer -> real
      ////////////////////
     ///   DIVISION   ///
    ////////////////////

    // for(i = 0; i < n ; i++){ 
    //     for(j = n; j < m; j++){
    //         A[ i*m + j ] = A[ i*m + j ] / A[ i*n + j ];
    //     }
    // }

    
    collectInverse( I, A, m, i, j, k );

    //Prints the augmented matrix
    printMatrix( I, n, i, j );

    int32_t a = 6570;
    int32_t b = (540) << 1;
    int32_t c = (b / a) << 8;
    printf("%i \n\n", a);
    printf("%i \n\n", b);

    printf("%i \n\n", c);

}
