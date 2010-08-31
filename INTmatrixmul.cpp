/*  Author: Nathan Crock

    Date: 8/27/2010 @ 17:29

    Program Description: An integer implementation of the matrix multiplication 
                         subroutines. 

    DISCLAIMER: There is very little error checking, please follow the rules!
*/

# include <fstream>
# include <stdio.h>
# include <iostream>
# include "matrixmul.hpp"

using namespace std;

int main ( int argc, char** argv ) {

    int ah, aw, bh, bw; // Matrix A's, and B's height and width
    bool sameSize = false; // for looping below

    while( sameSize == false ) {
        printf("\nEnter the number of rows and columns of the first matrix\n"
               " separated by a space.\n ->");

        cin >> ah;
        cin >> aw;

        printf("\nEnter the number of rows and columns of the second matrix\n"
               " separated by a space.\n ->");

        cin >> bh;
        cin >> bw;

        // Assert that the columns of matrix A are the same as the rows of matrix B
        if( aw == bh ) 
            sameSize = true; // If so exit loop
        else { // Else inform of error and take input again
            printf("\nThe columns of the first matrix must equal the rows\n"
                   " of the second matrix\n");
        }
    }

    matrix<int> A(ah, aw), B(bh, bw), C(ah, bw);
/*
    printf("\nValues for the matrices will be entered separated by spaces:\n"
            " Example: | 2 4 0 |\n"
            "          | 1 3 1 |\n"
            "          | 8 2 2 |\n"
            " Would be entered like this: 2 4 0 1 3 1 8 2 2\n"
            " \nData for the first matrix: ");

    for(int i = 0; i < ah*aw; i++) {
        cin >> A.data[i];
        break;
    }

    printf("\nData for the second matrix: ");

    for(int i = 0; i < bh*bw; i++) {
        cin >> B.data[i];
    }
*/
    // Hard coding input for testing purposes
    int a [] = {1,2,1,0,4,0,1,2,2,1,0,3};
    A.data = a;
    int b [] = {0,1,4,2,1,3,0,0,1,0,2,4,1,0,1,3,0,1,4,3};
    B.data = b;

    printf("\nMatrix A:\n");
    print_matrix_screen(A);    
    printf("\nMatrix B:\n");
    print_matrix_screen(B);    

    C = matMul(A, B);
    printf("\nMatrix A*B:\n");
    print_matrix_screen(C);
    print_matrix_file(C);

    return 0;
}
