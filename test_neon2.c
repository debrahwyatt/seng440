#include <stdio.h>
#include "arm_neon.h"
// void printMatrix(short (*)[], unsigned char row, unsigned char col);

// Matrix dimentions
unsigned char n = 3;   
unsigned char m = 6;    

int16_t M[] = {
    1, 2, 3, 
    4, 5, 6, 
    7, 8, 9
};

//prints a matrix to terminal
void printMatrix(int16_t *M, unsigned char i, unsigned char j) {
    
    //Print the starting matrix
    printf("\n");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("%i ",  M[i*n + j]);
        }
        printf("\n");
    }
}

void main(){
    
    //Program variables
    unsigned char i = 0;
    unsigned char j = 0;
    unsigned char k = 0;

    printMatrix( M, i, j);

    //Print the starting matrix
    printf("\n");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("%i ",  M[i*n + j]);
        }
        printf("\n");
    }

    //The augmented matrix shell
    //PROCESS NEEDS AUTOMATION
    int16_t A[] = { 
        M[0], M[1], M[2], 1, 0, 0, 
        M[3], M[4], M[5], 0, 1, 0, 
        M[6], M[7], M[8], 0, 0, 1 
    };

    //Prints the Augmented Matrix
    printf("\n");
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            printf("%i ",  A[i*m + j]);
        }
        printf("\n");
    }
    printf("\n");

    //Perform the pivot
    int16_t first_op;
    int16_t second_op;


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


    // int16_t B[] = {1, 2, 1, 0, 3, 4, 0, 1};

    // int16x4_t B0;
    // int16x4_t B1;

    // int16x4_t b = {1, 2, 3 ,4 };
    // int16x4_t d = {2,2,2,2};
    // int16x4_t e = {3,3,3,3};

    // rows of the augmented matrix b
   // printf("A: \n", *A);

    // int16_t C[] = {0, 0, 0, 0, 0 ,0 ,0, 0};

  //  int16x4_t f;

    //vmls_s16
    /*
        multiply subtract operation
    */

    // B0 = vld1_s16(B);
    // B1 = vld1_s16(B+4);

    // vst1_s16(C, B0);
    // vst1_s16(C+4, B1);

    // int16x4_t f = vmls_s16(b,d,e); // v3, v1, v2 = v3 - v1 * v2

    // int16_t M[] = {0, 0, 0, 0};
    // vst1_s16(M, f);
    // vst1_s16(C, B0);
    // vst1_s16(C+4, B1);

    // for(int i = 0; i < 4; i++){
    //     printf("M: %i\n",  M[i]);
    // }
}