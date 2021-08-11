#include <stdio.h>
#include "arm_neon.h"

void main(){
    
    //Program variables
    unsigned char i = 0;
    unsigned char j = 0;
    unsigned char k = 0;

    // The starting matrix
    int16_t M0[] = {1, 2, 3};
    int16_t M1[] = {4, 5, 6};
    int16_t M2[] = {7, 8, 9};

    //Print the starting matrix
    printf("\n");
    for(i = 0; i < 3; i++){
        printf("%i ",  M0[i]);
    }
    printf("\n");
    for(i = 0; i < 3; i++){
        printf("%i ",  M1[i]);
    }
    printf("\n");
    for(i = 0; i < 3; i++){
        printf("%i ",  M2[i]);
    }
    printf("\n");
    printf("\n");


    //The augmented matrix shell
    int16_t A0[] = {M0[0], M0[1], M0[2], 1, 0, 0};
    int16_t A1[] = {M1[0], M1[1], M1[2], 0, 1, 0};
    int16_t A2[] = {M2[0], M2[1], M2[2], 0, 0, 1};

    //Print the augmented matrix shell
    printf("\n");
    for(i = 0; i < 6; i++){
        printf("%i ",  A0[i]);
    }
    printf("\n");
    for(i = 0; i < 6; i++){
        printf("%i ",  A1[i]);
    }
    printf("\n");
    for(i = 0; i < 6; i++){
        printf("%i ",  A2[i]);
    }
    printf("\n");
    printf("\n");

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


    int16_t B[] = {1, 2, 1, 0, 3, 4, 0, 1};

    int16x4_t B0;
    int16x4_t B1;

    int16x4_t b = {1, 2, 3 ,4 };
    int16x4_t d = {2,2,2,2};
    int16x4_t e = {3,3,3,3};

    // rows of the augmented matrix b
   // printf("A: \n", *A);

    int16_t C[] = {0, 0, 0, 0, 0 ,0 ,0, 0};

  //  int16x4_t f;

    //vmls_s16
    /*
        multiply subtract operation
    */

    B0 = vld1_s16(B);
    B1 = vld1_s16(B+4);

    vst1_s16(C, B0);
    vst1_s16(C+4, B1);

    int16x4_t f = vmls_s16(b,d,e); // v3, v1, v2 = v3 - v1 * v2

    int16_t M[] = {0, 0, 0, 0};
    vst1_s16(M, f);
    vst1_s16(C, B0);
    vst1_s16(C+4, B1);

    for(int i = 0; i < 4; i++){
        printf("M: %i\n",  M[i]);
    }
}