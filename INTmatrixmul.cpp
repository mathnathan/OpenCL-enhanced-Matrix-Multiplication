/*  Author: Nathan Crock

    Date: 8/27/2010 @ 17:29

    Program Description: An integer implementation of the matrix multiplication 
                         subroutines. 
*/

# include <fstream>
# include <string.h>
# include <stdio.h>
# include <iostream>
# include "matrixmul.hpp"

using namespace std;

int main ( int argc, char** argv ) {

    const char * FILENAME = "IntOutput.txt";
    int ah, aw, bh, bw; // Matrix A's, and B's height and width

    ah = 3;
    aw = 4;
    bh = 4;
    bw = 5;

    matrix<int> A(ah, aw), B(bh, bw), C(ah, bw);

    // Matrix A is a 3x4 matrix where each row is listed
    // one after the other
    int a [] = {1,2,1,0,4,0,1,2,2,1,0,3};
    memcpy(A.data, a, sizeof(int)*ah*aw);
    // Matrix B is a 4x5 matrix where each row is listed 
    // one after the other
    int b [] = {0,1,4,2,1,3,0,0,1,0,2,4,1,0,1,3,0,1,4,3};
    memcpy(B.data, b, sizeof(int)*bh*bw);

    printf("\nMatrix A:\n");
    print_matrix_screen(A);    
    printf("\nMatrix B:\n");
    print_matrix_screen(B);    

    matMul(A, B, C);
    printf("\nMatrix A*B:\n");
    print_matrix_screen(C);
    print_matrix_file(C, FILENAME);
    printf("\nMatrix A*B has been written to file %s\n\n", FILENAME);

    return 0;
}
