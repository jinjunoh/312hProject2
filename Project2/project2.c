
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "matrix.h"

void multiplyMatrices(double a[],
                      const uint32_t a_rows,
                      const uint32_t a_cols,
                      double b[],
                      const uint32_t b_cols,
                      double c[]) {
    // Aij is stored in the location a[i * a cols + j]
    for(int i = 0 ; i < a_rows ; i++){
        for(int j = 0; j < b_cols ; j++){
            c[i * b_cols + j] = 0;
            for( int m = 0; m < a_cols; m ++){
                c[i * b_cols + j] += a[i * a_cols + m] * b[m * b_cols + j];
            }
        }
    }
    // The matrices B and C are similarly stored in the arrays b[] and c[] respectively.
    // https://en.wikipedia.org/wiki/Row-_and_column-major_order
//    int i = 0; //starting row location for matrix C
//    int j = 0; //starting column location for matrix C
//    while(i < a_rows){
//        //increment to the next row until the last row is reached
//        while(j < b_cols){
//            //increment through the row until a location is found
//            //this should fill C[i0], C[i1], C[i2], ..., C[ij]
//            //where ij is essentially the last number in that row
//            //get the sum for that location
//            //all of a in that row, all of b in that column
//            c[i * b_cols + j] = 0;
//            //make the element in the array 0 before adding them all up
//            for (int k = 0; k < a_cols; ++k) {
//                //this function will run until the entire row is added up
//                // k < a_cols means that the maximum value for k is a_cols - 1
//                c[i * b_cols + j] += a[i * a_cols + k] * b[k * b_cols + j];
//                //c[i * b_cols + j] should be c[ij]
//                //this means that c[ij] = a[i0] * b[0j] + a[i1] * b[1j], etc.
//                //until k = a_cols - 1
//            }
//            ++j;
//            //increment j until the end of the row is reached
//        }
//        ++i; //once j reaches the end of the row, increment i to the next row
//        j = 0; //also set j to 0 to go to the start of the next row
//    }
}

double** multiplyMatricesPtr(double** a,
                             const uint32_t a_rows,
                             const uint32_t a_cols,
                             double** b,
                             const uint32_t b_cols) {

    double** c = malloc(sizeof(double*) * a_rows);
    for (int i = 0; i<a_rows; i++){ // allocate a new array pointer
        c[i] = (double *) malloc(b_cols*sizeof(double));
    }

    for (int i = 0; i < a_rows ; i++){
        for (int j = 0; j < b_cols ; j++){
            c[i][j] = 0; //sets the element that is being checked as 0 first
            for (int k = 0; k < a_cols; ++k) {
                //multiply together a[i][k] and b[k][j] to produce c[i][j]
                c[i][j] += (a[i][k] * b[k][j]);
            }
        }
    }

    return c;
    //return NULL;
}

double** transposeMatrix(double** a,
                         const uint32_t a_rows,
                         const uint32_t a_cols) {
    // https://en.wikipedia.org/wiki/Transpose
    double ** c;
    c = malloc(sizeof(double *) * a_cols);
    for (int m = 0; m < a_cols; m++){
        c[m] = malloc(sizeof(double) * a_rows);
    }
    for (int i = 0; i < a_cols; i++){
        for( int j = 0; j < a_rows; j++){
            c[i][j] = a[j][i];
        }
    }
    return c;
//    double **c;
//    c = malloc(a_cols * sizeof(double *));
//    for (int p = 0; p < a_cols; ++p) {
//        c[p] = malloc(a_rows * sizeof(double));
//    }
//    for (int i = 0; i < a_cols; ++i) {
//        for (int j = 0; j < a_rows; ++j) {
//            c[i][j] = a[j][i];
//            //ij must become ji
//            //this code will put out when we reach flipped territory (i'll debug this later)
//        }
//    }


    // https://en.wikipedia.org/wiki/Transpose
    return c;
}
