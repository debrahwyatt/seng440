#include <stdio.h>

#define order 3
#define SHIFT_AMOUNT 8
#define SHIFT_MASK  ((1 << SHIFT_AMOUNT) - 1)

int augmented_matrix[3][3*order]; // n+ 1
int matrix[3][3] = {  {3, 2, -4}, 
                      {2, 3, 3}, 
                      {5, -3, 1} 
                    };
int inv_matrix[3][3];

// input: matrix
// output: matrix appenended to identity matrix
void augment_matrix(){
    int mat_i = 0;
    int mat_j = order;
    for(int i = 0; i < order; i++){
        for(int j = 0; j < order*2; j++){
            if( (i < order) && (j < order) ){
                // shift the matrix value left because of later division
               // augmented_matrix[i][j] = matrix[i][j] << SHIFT_AMOUNT;
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
}

/*
    Prints the matrix IA^-1 
*/
void print_augmented_matrix(){
    for(int i = 0; i < order ; i++){
        for(int j = 0; j < 2*order; j++){
            printf("%i   ", augmented_matrix[i][j]);
        }
          printf("\n");
    } 
}

/*
    Shifts the right side of the matrix so we can do fixed point math (division).
    - instead of shifting the inverted matrix we will shift the right 
    side of the augmented matrix so we can work with one matrix instead of two
*/
void shift_inverted_matrix(){
    for(int i = 0; i < order; i++){
        for(int j = 0; j < 2*order; j++){
            if(j >= order){
                augmented_matrix[i][j] = augmented_matrix[i][j] << SHIFT_AMOUNT;
            }
        }
        
    } 
}
/*
   Floating point divide on the inverted matrix
*/
void divide_inverted_matrix(){
    for(int i = 0; i < order; i++){
        for(int j = order; j < 2*order; j++){
           augmented_matrix[i][j] = augmented_matrix[i][j] / augmented_matrix[i][i];
        }
        printf("\n");
    } 
}

/*
    After the shift and inversion have been completed, print the matrix values
*/
void print_after_shift_and_inversion(){
    for(int i = 0; i < order; i++){
        for(int j = order; j < 2*order; j++){
            if(augmented_matrix[i][j] < 0){
                float f = ((float)(augmented_matrix[i][j] & SHIFT_MASK) / (1 << SHIFT_AMOUNT));
                printf("-%f ", 1-f);
            }
            else{
                printf("%f ", ((float)(augmented_matrix[i][j] & SHIFT_MASK) / (1 << SHIFT_AMOUNT)));
            }
        }
        printf("\n");
    } 
}

/*
    Prints the matrix A
*/
void print_matrix(int rows, int cols, int matrix[rows][cols]){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            printf("%i ", matrix[i][j]);
        }
        printf("\n");
    } 
}

/*
    Operations to clear the rows and columns via multiplication, addition, and subtraction
*/
void pivot(){
    int first_op;
    int second_op;
    for(int m = 0; m < order; m++){
        first_op = augmented_matrix[m][m];
        for(int i = 0; i < order ; i++){ 
            second_op = augmented_matrix[i][m];
            for(int j = 0; j < 2*order; j++){
                if(i != m){
                  augmented_matrix[i][j] = first_op*augmented_matrix[i][j] - second_op*augmented_matrix[m][j];
                }
            }
        } 
    }
    /*
     for(int i = 0; i < order ; i++){ 
        for(int j = order; j < 2*order; j++){
           // augmented_matrix[i][j] = augmented_matrix[i][j] / augmented_matrix[i][i];
        
        }
    }
    */
    

    // collect the inverted matrix
    for(int i = 0; i < order ; i++){ 
        int k = 0;
        for(int j = order; j < 2*order; j++){
            //augmented_matrix[i][j] = augmented_matrix[i][j] / augmented_matrix[i][i];
            //printf("%f ", ((double)(augmented_matrix[i][j]  & SHIFT_MASK) / (1 << SHIFT_AMOUNT)));
            inv_matrix[i][k++] = augmented_matrix[i][j];
           // printf("price fraction in decimal is %f\n", ((double)(amount & SHIFT_MASK) / (1 << SHIFT_AMOUNT)));
        }
    }
}
   

int main(){
    printf("\nThe original matrix\n");
    print_matrix(3, 3, matrix);

    printf("\nThe augmented matrix\n");
    augment_matrix();
    print_augmented_matrix();

    printf("\nThe augmented matrix (post pivot)\n");
    pivot();
    print_augmented_matrix();
    printf("\n");
    /*
    printf("\nThe inverted matrix\n");
    print_matrix(3, 3, inv_matrix);
    printf("\n");
    */
    printf("\nThe shifted matrix\n");
    shift_inverted_matrix();
   // print_matrix(3, 6, augmented_matrix); 
    print_augmented_matrix();
    printf("\n");
  
    printf("\nThe divided matrix\n");
    divide_inverted_matrix();
    print_augmented_matrix();
    printf("\n");
    printf("After shift and inversion\n");
    print_after_shift_and_inversion();

    
    return 0;
}