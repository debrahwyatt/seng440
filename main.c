  ////////////////
 /// PACKAGES ///
////////////////
#include <stdio.h>
#include <math.h>

//Global variables
#define order 5
#define scale 8


  ////////////////////
 /// PROGRAM MAIN ///
////////////////////

int main(void) {
    printf("\n");
    
    // A 3x3 example matrix
    short matrix[5][5] = {
        {1,3,4,1,6},
        {2,1,1,3,1},
        {2,3,1,3,3}, 
        {1,2,5,1,2}, 
        {1,5,4,1,1}
    };

    //system variables
    short first_op;
    short second_op;                      
    unsigned char i = 0;
    unsigned char j = 0;
    unsigned char m = 0;
    int augmented_matrix[5][order*2];


      ////////////////////
     /// AUGMENTATION ///
    ////////////////////

    // Sets up the matrix adjacent to an identity matrix
    for(i = 0; i < order; i++){
        augmented_matrix[i][0] = matrix[i][0];
        augmented_matrix[i][1] = matrix[i][1];
        augmented_matrix[i][2] = matrix[i][2];
        augmented_matrix[i][3] = matrix[i][3];
        augmented_matrix[i][4] = matrix[i][4];

        augmented_matrix[i][5] = 0;
        augmented_matrix[i][6] = 0;
        augmented_matrix[i][7] = 0;
        augmented_matrix[i][8] = 0;
        augmented_matrix[i][9] = 0;
    }
    augmented_matrix[0][5] = 1;
    augmented_matrix[1][6] = 1;
    augmented_matrix[2][7] = 1;
    augmented_matrix[3][8] = 1;
    augmented_matrix[4][9] = 1;
    //////////////////////////////////////////////////



      ////////////////////
     ///     PIVOT    ///
    ////////////////////

    for(m = 0; m < order; m++){
        first_op = augmented_matrix[m][m];

        for(i = 0; i < order ; i++){ 
            second_op = augmented_matrix[i][m];

            if(i != m){
                augmented_matrix[i][0] = first_op*augmented_matrix[i][0] - second_op*augmented_matrix[m][0];
                augmented_matrix[i][1] = first_op*augmented_matrix[i][1] - second_op*augmented_matrix[m][1];
                augmented_matrix[i][2] = first_op*augmented_matrix[i][2] - second_op*augmented_matrix[m][2];
                augmented_matrix[i][3] = first_op*augmented_matrix[i][3] - second_op*augmented_matrix[m][3];
                augmented_matrix[i][4] = first_op*augmented_matrix[i][4] - second_op*augmented_matrix[m][4];
                augmented_matrix[i][5] = first_op*augmented_matrix[i][5] - second_op*augmented_matrix[m][5];       
                augmented_matrix[i][6] = first_op*augmented_matrix[i][6] - second_op*augmented_matrix[m][6];
                augmented_matrix[i][7] = first_op*augmented_matrix[i][7] - second_op*augmented_matrix[m][7];
                augmented_matrix[i][8] = first_op*augmented_matrix[i][8] - second_op*augmented_matrix[m][8];    
                augmented_matrix[i][9] = first_op*augmented_matrix[i][9] - second_op*augmented_matrix[m][9];    
            }    
        } 
    }


      ////////////////////
     ///   DIVISION   ///
    ////////////////////

    for(i = 0; i < order ; i++){ 
        augmented_matrix[i][order] = (augmented_matrix[i][order] << scale ) / augmented_matrix[i][i];
        augmented_matrix[i][order + 1] = (augmented_matrix[i][order + 1] << scale ) / augmented_matrix[i][i];
        augmented_matrix[i][order + 2] = (augmented_matrix[i][order + 2] << scale ) / augmented_matrix[i][i];
        augmented_matrix[i][order + 3] = (augmented_matrix[i][order + 3] << scale ) / augmented_matrix[i][i];
        augmented_matrix[i][order + 4] = (augmented_matrix[i][order + 4] << scale ) / augmented_matrix[i][i];        
    }

    //print the inverse to console
    for(i = 0; i < order ; i++){ 
        printf("[%f]", (float)(augmented_matrix[i][order]/pow(2,scale)));
        printf("[%f]", (float)(augmented_matrix[i][order + 1]/pow(2,scale)));
        printf("[%f]", (float)(augmented_matrix[i][order + 2]/pow(2,scale)));
        printf("[%f]", (float)(augmented_matrix[i][order + 3]/pow(2,scale)));
        printf("[%f]", (float)(augmented_matrix[i][order + 4]/pow(2,scale)));
        printf("\n");
    }
    printf("\n");

}

