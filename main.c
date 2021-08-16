  ////////////////
 /// PACKAGES ///
////////////////
#include <stdio.h>
#include <math.h>

//Global variables
#define order 3
#define scale 8


  ////////////////////////////
 /// FUNCTION DECLARATION ///
////////////////////////////

void printMatrix(short (*)[], unsigned char row, unsigned char col);


  ////////////////////
 /// PROGRAM MAIN ///
////////////////////

int main(void) {
    printf("\n");
    
    // A 3x3 example matrix
    short matrix[3][3] = {    
                        {3, 2, -4}, 
                        {2, 3, 3}, 
                        {5, -3, 1} 
                    };

    //system variables
    unsigned char i = 0;
    unsigned char j = 0;
    unsigned char m = 0;
    unsigned char mat_i = 0;
    unsigned char mat_j = order;

    int first_op;
    int second_op;    

    int augmented_matrix[3][order*2];
    int inv_matrix[3][3];


      ////////////////////
     /// AUGMENTATION ///
    ////////////////////

    // Sets up the matrix adjacent to an identity matrix
    for(i = 0; i < order; i++){
        for(j = 0; j < order*2; j++){
            if( (i < order) && (j < order) ){
                augmented_matrix[i][j] = matrix[i][j];
            }
            else if(i == mat_i && j == mat_j) {
               augmented_matrix[i][j] = 1;
               mat_i++;
               mat_j++;
            }
            else{
                augmented_matrix[i][j] = 0;
            }
        }
    }
    //////////////////////////////////////////////////


      ////////////////////
     ///     PIVOT    ///
    ////////////////////

    for(m = 0; m < order; m++){
        first_op = augmented_matrix[m][m];

        for(i = 0; i < order ; i++){ 
            second_op = augmented_matrix[i][m];

            for(j = 0; j < 2*order; j++){
                if(i != m){
                    augmented_matrix[i][j] = first_op*augmented_matrix[i][j] - second_op*augmented_matrix[m][j];
                }
            }
        } 
    }


      ////////////////////
     ///   DIVISION   ///
    ////////////////////

    for(i = 0; i < order ; i++){ 
        for(j = order; j < 2*order; j++){
            augmented_matrix[i][j] = (augmented_matrix[i][j] << scale ) / augmented_matrix[i][i];
        }
    }

    //print the inverse to console
    for(i = 0; i < order ; i++){ 
        for(j = order; j < 2*order; j++){
            printf("[%f]", (float)(augmented_matrix[i][order]/pow(2,scale)));
            printf("[%f]", (float)(augmented_matrix[i][order + 1]/pow(2,scale)));
            printf("[%f]", (float)(augmented_matrix[i][order + 2]/pow(2,scale)));
        }
        printf("\n");
    }
    printf("\n");

}

