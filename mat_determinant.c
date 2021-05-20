#include <stdio.h> 


/*

This is a program to compute the determinant of a matrix.

*/

// Sample matrix to hold the 4x4 matrix 
float test_matrix[5][5] = { {2, -3, 0, 1},
                            {5,  4, 2, 0},
                            {1, -1, 0, 3},
                            {-2, 1, 0, 0}
                          };


float *a = &test_matrix[0][0];
float *b = &test_matrix[0][1];
float *c = &test_matrix[1][0];
float *d = &test_matrix[1][1];

// Determinant of the matrix
float det;

int n = 4; // size of matrix

void swap(float *x, float *y)
{
    float temp = *x;
    *x = *y;
    *y = temp;
}
// void as it will update the memory location so no need to return anything
float determinant(float matrix[10][10]){
    // Expanding along the top row is probably easiest

    // Do the cofactor multiplication on each value of the matrix
    for(int i = 0; i < n; i++){
       
        int s = n-1;

        if(s > 2){
            // intantiate new matrix to recursively call determinant on 
            float sub_matrix[s][s];

            for(int j = 0; j < s; j++){
                for (int k = 0; k < s; k++){
                    if(j != 0 && k == 0){
                        sub_matrix[j][k] = test_matrix[j][k];
                    }
            }
            sub_matrix[0][i]*determinant(sub_matrix);
            }
        }
        else{ 
            return matrix[0][0]*matrix[1][1];
        }


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
