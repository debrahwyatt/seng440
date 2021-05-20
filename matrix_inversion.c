#include <stdio.h> 


/*

This is a program to compute the inverse of a matrix.

Requires: a square matrix 
          the determinant must not be zero

*/

// Sample matrix to hold the 2x2 matrix 
float test_matrix[2][2] = { {1, 2},
                            {3, 4}  };


float *a = &test_matrix[0][0];
float *b = &test_matrix[0][1];
float *c = &test_matrix[1][0];
float *d = &test_matrix[1][1];

// Determinant of the matrix
float det;

void swap(float *x, float *y)
{
    float temp = *x;
    *x = *y;
    *y = temp;
}
// void as it will update the memory location so no need to return anything
void calc_det(){
    /*  | 1  2 | = | a  b | = | [0][0]  [0][1] |
        | 3  4 |   | c  d |   | [1][0]  [1][1] |
    */ 
   // swap a and d
   swap(a,d);
   // b = -b
   // c = -c
   *b = *b * -1.0;
   *c = *c * -1.0;

   det = 1/( (*a * *d) - (*b * *c) ); 

   if(det == 0){
       printf("The determinant is zero, cannot calculate the inverse.\n");
       exit(1);
   }
   else{
        *a = *a * det;
        *b = *b * det;
        *c = *c * det;
        *d = *d * det;
   }

}

int main(){
    // Calculate the determinant, and update matrix
    calc_det();
    // Output these values to the console
    printf("%f\n", *a );
    printf("%f\n", *b );
    printf("%f\n", *c );
    printf("%f\n", *d );
}
