#include <stdio.h>
#include "arm_neon.h"

void main(){
    
    //Program variables
    unsigned char i = 0;
    unsigned char j = 0;
    unsigned char k = 0;

    // The starting matrix
    unsigned char N = 2;    
    int16_t m[] = {1, 2, 3, 4};
    // [1,2]
    // [3,4]
    
    //Print the starting matrix
    printf("\n");
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            printf("%i ",  m[i*N + j]);
        }
        printf("\n");
    }

    //The augmented matrix shell
    int16_t A[] = { m[0], m[1], 1, 0, m[2], m[3], 0, 1 };
    unsigned char M = 4;    

    printf("\n");
    for(i = 0; i < N; i++){
        for(j = 0; j < M; j++){
            printf("%i ",  A[i*N + j]);
        }
        printf("\n");
    }

    // int16_t first_op;
    // int16_t second_op;  

    //Perform the pivot
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