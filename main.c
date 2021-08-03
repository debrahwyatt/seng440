// #include <stdio.h>

// #define order 3
// #define precision 3
// float augmented_matrix[3][3*order];
// float matrix[3][3] = {    {3.0, 2.0, -4.0}, 
//                         {2.0, 3.0, 3.0}, 
//                         {5.0, -3.0, 1.0} 
//                     };
// float inv_matrix[3][3];

// input: matrix
// output: matrix appenended to identity matrix
void augment_matrix(){
    // int mat_i = 0;
    // int mat_j = order;
    // for(int i = 0; i < order; i++){
    //     for(int j = 0; j < order*2; j++){
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
}

/*
    Prints the matrix IA^-1 
*/
void print_augmented_matrix(){
    // for(int i = 0; i < order ; i++){
    //     for(int j = 0; j < 2*order; j++){
    //         printf("%.3f   ", augmented_matrix[i][j]);
    //     }
    //       printf("\n");
    // } 
}

/*
    Prints the matrix A
*/
void print_matrix(int rows, int cols, float matrix[rows][cols]){
    // for(int i = 0; i < rows; i++){
    //     for(int j = 0; j < cols; j++){
    //         printf("%.3f ", matrix[i][j]);
    //     }
    //     printf("\n");
    // } 
}

/*
    Operations to clear the rows and columns via multiplication, addition, and subtraction
*/
void pivot(){
    // int first_op;
    // int second_op;
    // first_op = augmented_matrix[0][0];
    // for(int i = 0; i < order - 1; i++){ 
    //     for(int j = 0; j < 2*order; j++){
    //         second_op = matrix[i+1][0]; 
    //         augmented_matrix[i+1][j] = first_op*augmented_matrix[i+1][j] - second_op*augmented_matrix[0][j];
    //     }
    //     printf("\n");
    // } 
    // first_op = augmented_matrix[1][1];
    
    // for(int i = 0; i < order ; i++){ 
    //     second_op = augmented_matrix[i][1];
    //     for(int j = 0; j < 2*order; j++){
    //         if(i != 1){
    //             augmented_matrix[i][j] = first_op*augmented_matrix[i][j] - second_op*augmented_matrix[1][j];
    //         }
    //     }
    // } 

    // first_op = augmented_matrix[2][2];
    // for(int i = 0; i < order ; i++){ 
    //     second_op = augmented_matrix[i][2];
    //     for(int j = 0; j < 2*order; j++){
    //         if(i != 2){
    //             augmented_matrix[i][j] = first_op*augmented_matrix[i][j] - second_op*augmented_matrix[2][j];
    //         }
    //     }
    // } 
    // //division
    // for(int i = 0; i < order ; i++){ 
    //     for(int j = order; j < 2*order; j++){
    //         augmented_matrix[i][j] = augmented_matrix[i][j] / augmented_matrix[i][i];
    //     }
    // }

    // // collect the inverted matrix
    // for(int i = 0; i < order ; i++){ 
    //     int k = 0;
    //     for(int j = order; j < 2*order; j++){
    //         inv_matrix[i][k++] = augmented_matrix[i][j];
    //     }
    // }
}

int main(){
    printf("\nThe original matrix\n");
    print_matrix(3, 3, matrix);

    printf("\nThe augmented matrix\n");
    augment_matrix();
    pivot();
    print_augmented_matrix();

    printf("\nThe inverted matrix\n");
    print_matrix(3, 3, inv_matrix);
    printf("\n");

    return 0;
}