/*  Author: Nathan Crock - http://www.mathnathan.com

    Date: 8/26/2010 @ 19:33

    Program Description: A matrix multiplication function written for my 
                         Numerical Analysis class. This program takes in
                         two matrices of any size and any type and 
                         multiplies them using the standard row by column
                         matrix multiplication technique.
*/

# include <fstream>
# include <stdio.h>

using namespace std;

// --------------Matrix data structure-----------------
//   It has three members: data - a pointer to an array
//                         height - the number of rows
//                         width - the number of columns
//
// I'm using a one dimensional array and listing the rows
// one after another. Then I can use math tricks to simplify
// the multiplication algorithm. And ultimately use the arrays
// to rewrite this in OpenCL and optimize the computation time.

template <typename T>
struct matrix {
    T* data;
    unsigned int height;
    unsigned int width;

    matrix(unsigned int h, unsigned int w);
};

// Constructor - Initializes matrix of size (h x w) with
template <typename T>
matrix<T>::matrix(unsigned int h = 0, unsigned int w = 0): height(h), width(w) {
    data = new T[height*width];
}

/* -------------Multiplication Function-----------------
     Without using sparse matrices, this is roughly as
   quick as you'll get when brute force multiplying 
   matrices. The first for loop goes through every 
   element of the resultant matrix, while the nested
   for loop goes over the columns. The products of all the 
   elements in the respective rows and columns are summed
   up in each entry of the resultant matrix.            */

template <typename T>
void matMul(const matrix<T> & A, const matrix<T> & B, matrix<T> & C) {

    int row, col;
    for (int entry = 0; entry < A.height*B.width; entry++) {
        row = entry / B.width;
        col = entry % B.width;
        for (int elem = 0; elem < A.width; elem++) {
            C.data[entry] += A.data[row*A.width + elem]*B.data[col + elem*B.width];
        }
    } 
}

// Print a matrix to the screen
template <typename T>
void print_matrix_screen(const matrix<T> & A) {

    printf("\n| ");
    for(int i = 0; i < A.height; i++) {
        if(i > 0 && i < A.height) {
            printf("|\n");
            printf("| ");
        }
        for(int j = 0; j < A.width; j++) {
            cout << A.data[i*A.width + j] << " ";
        }
    }
    printf("|\n");
}

// Print a matrix to a file
template <typename T>
void print_matrix_file(const matrix<T> & A, const char* filename) {

    std::ofstream output;
    output.open(filename);

    output << "| ";
    for(int i = 0; i < A.height; i++) {
        if(i > 0 && i < A.height) {
        output << "|\n";
        output << "| ";}
        for(int j = 0; j < A.width; j++) {
            output << A.data[i*A.width + j] << " ";
        }
    }
    output << "|\n";
}
