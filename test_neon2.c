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

//prints a matrix to terminal
int16_t initializeAugmentation( int16_t *M, uint8_t m, uint8_t i, uint8_t j ) {
    
    int16_t B[18];

    //Basic for loop
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            if( j < n ){
                B[ i*m + j ] = M[ i*n + j ];
            }
            else if(j-n == i){
                B[ i*m + j ] = 1;
            }
            else{
                B[ i*m + j ] = 0;
            }
        }
    }
    return *B;
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
    //PROCESS NEEDS AUTOMATION
    int16_t A[] = { 
        M[0], M[1], M[2], 1, 0, 0, 
        M[3], M[4], M[5], 0, 1, 0, 
        M[6], M[7], M[8], 0, 0, 1 
    };
    
    int16_t B[18];

    //Basic for loop
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            if( j < n ){
                B[ i*m + j ] = M[ i*n + j ];
            }
            else if(j-n == i){
                B[ i*m + j ] = 1;
            }
            else{
                B[ i*m + j ] = 0;
            }
        }
    }
    printMatrix( B, m, i, j );
    
    // // Sets up the matrix adjacent to an identity matrix
    // for(i = 0; i < order; i++){
    //     for(j = 0; j < order*2; j++){
    //         if( (i < order) && (j < order) ){
    //             augmented_matrix[i][j] = matrix[i][j];
    //         }
    //         else if(i == mat_i && j == mat_j) {
    //            augmented_matrix[i][j] = 1;
    //            mat_i++;
    //            mat_j++;
    //         }
    //         else{
    //             augmented_matrix[i][j] = 0;
    //         }
    //     }
    // }

    printf("\n");

    //Prints the augmented matrix
    printMatrix( A, m, i, j );

    //Perform the pivot
    // int16_t first_op;
    // int16_t second_op;




}