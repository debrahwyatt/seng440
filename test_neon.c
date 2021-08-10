#include <stdio.h>
#include "arm_neon.h"

void main(){
    // rows of the input matrix A

    int16_t A[] = {1, 2, 1, 0, 3, 4, 0, 1};


    int16x4_t A0;
    int16x4_t A1;

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

    A0 = vld1_s16(A);
    A1 = vld1_s16(A+4);

    vst1_s16(C, A0);
    vst1_s16(C+4, A1);

    int16x4_t f = vmls_s16(b,d,e); // v3, v1, v2 = v3 - v1 * v2

    int16_t M[] = {0, 0, 0, 0};
    vst1_s16(M, f);
    vst1_s16(C, A0);
    vst1_s16(C+4, A1);

    for(int i = 0; i < 4; i++){
        printf("M: %i\n",  M[i]);
    }
}