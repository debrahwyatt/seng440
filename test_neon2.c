  /////////////////////
 ///    HEADERS    ///
/////////////////////

#include <stdio.h>
#include <math.h>
#include "arm_neon.h"


  ////////////////////////
 /// GLOBAL VARIABLES ///
////////////////////////

// Matrix dimentions
#define n 3
#define scale 8

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

void printInverse( int16_t *I, int8_t m, int8_t i, int8_t j ) {
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            // printf("%i ",  I[i*m + j]);
            printf("%f ", (float)(I[i*m + j])/pow(2, scale));

        }
        printf("\n");
    }
    printf("\n");
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

    for(i = 0; i < n ; i++){ 
        for(j = n; j < m; j++){
            // printf("%i \n\n", A[ i*m + j ]);
            // printf("%i \n\n", A[ i*m + i ]);
            // if(A[ i*n + i ] == 0){
            //     continue;
            // }
            A[ i*m + j ] = ((A[ i*m + j ] << scale ) / A[ i*m + i ]) ;
        }
    }

    collectInverse( I, A, m, i, j, k );
    printInverse( I, n, i, j );

    //Prints the augmented matrix
    // printMatrix( I, n, i, j );

    // 0000 0000 0000 0000

    // 0000 0000 0001 0101
    // int16_t a = 21;

    // 0000 0000 0000 0010
    // int16_t b = 2;

    // a = a << scale;
    // 0001 0101 0000 0000

    // int16_t e = (c << 16) >> 16;
    // 1000 0000 0000 0000 
    // printf("%i \n\n", a);
    // printf("%i \n\n", b);
    // printf("%f \n\n", (float)(a/b)/pow(2, scale));

}
