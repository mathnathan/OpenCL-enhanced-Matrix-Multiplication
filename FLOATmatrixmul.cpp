/*  Author: Nathan Crock

    Date: 8/26/2010 @ 19:33

    Program Description: A float implementation of the matrix multiplication 
                         subroutines of large dimension. 
*/

# include <fstream>
# include <stdio.h>
# include <iostream>
# include "matrixmul.hpp"

// Returns a random float
float rand_float(const float mn, const float mx);

using namespace std;

int main ( int argc, char** argv ) {

    const int DIMENSIONS = 2000;
    const float MIN = 0.0;
    const float MAX = 9.0;
    const char* FILENAMEA = "FloatOutputA.txt";
    const char* FILENAMEB = "FloatOutputB.txt";
    const char* FILENAMEC = "FloatOutputC.txt";

    int ah, aw, bh, bw; // Matrix A's, and B's height and width

    ah = aw = bh = bw = DIMENSIONS;

    matrix<int> A(ah, aw), B(bh, bw), C(ah, bw);

    // Fill the matrices with random floats
    for(int i = 0; i < DIMENSIONS*DIMENSIONS; i++) {
        A.data[i] = rand_float(MIN, MAX);  
        B.data[i] = rand_float(MIN, MAX);  
    }

    C = matMul(A, B);

    printf("\nMatrix A was written to: %s\n", FILENAMEA);
    print_matrix_file(A, FILENAMEA);

    printf("\nMatrix B was written to: %s\n", FILENAMEB);
    print_matrix_file(B, FILENAMEB);

    printf("\nMatrix C was written to: %s\n", FILENAMEC);
    print_matrix_file(C, FILENAME);

    return 0;
}

float rand_float(const float mn, const float mx)
{
    float r = random() / (float) RAND_MAX;
    return mn + (mx-mn)*r;
}
