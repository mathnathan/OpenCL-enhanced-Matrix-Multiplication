/*  Author: Nathan Crock

    Date: 8/26/2010 @ 19:33

    Program Description: A float implementation of the matrix multiplication 
                         subroutines of large dimension. 
*/

# include <stdlib.h>
# include <fstream>
# include <stdio.h>
# include <iostream>
# include "matrixmul.hpp"

// Returns a random float
float rand_float(const float mn, const float mx);

using namespace std;

int main ( int argc, char** argv ) {

    // If DIMENSIONS is above 500, the program can
    // take up to a few minutes depending on your CPU speed.
    // This will no longer matter once I rewrite this in OpenCL >=)
    const int DIMENSIONS = 20;
    const float MIN = 0.0;
    const float MAX = 9.0;
    const char* FILENAMEA = "FloatOutputA.txt";
    const char* FILENAMEB = "FloatOutputB.txt";
    const char* FILENAMEC = "FloatOutputC.txt";

    int ah, aw, bh, bw; // Matrix A's, and B's height and width

    ah = aw = bh = bw = DIMENSIONS;

    matrix<float> A(ah, aw), B(bh, bw), C(ah, bw);

    // Fill the matrices with random floats
        printf("\nFilling in random floats...\n");
    for(int i = 0; i < DIMENSIONS*DIMENSIONS; i++) {
        A.data[i] = rand_float(MIN, MAX);  
        B.data[i] = rand_float(MIN, MAX);  
    }

    printf("\nMultiplying Matrices...\n");
    matMul(A, B, C);

    printf("\nMatrix A was written to: %s\n", FILENAMEA);
    print_matrix_file(A, FILENAMEA);

    printf("\nMatrix B was written to: %s\n", FILENAMEB);
    print_matrix_file(B, FILENAMEB);

    printf("\nMatrix C was written to: %s\n\n", FILENAMEC);
    print_matrix_file(C, FILENAMEC);

    return 0;
}

float rand_float(const float mn, const float mx)
{
    float r = random() / (float) RAND_MAX;
    return mn + (mx-mn)*r;
}
