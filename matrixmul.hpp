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

    // Constructor - Initializes matrix of size (h x w) with 0's
    matrix(unsigned int h, unsigned int w);
    ~matrix();
};

template <typename T>
matrix<T>::matrix(unsigned int h = 0, unsigned int w = 0): height(h), width(w) {
    data = new T[height*width];
    for (int i = 0; i < height*width; i++) {
        data[i] = 0;
    }
}

template <typename T>
matrix<T>::~matrix() {
    delete [] data;
    }

template <typename T>
matrix<T> matMul(matrix<T> A, matrix<T> B) 
{
    matrix<T> C(A.height, B.width);

    int row, col;
    for (int entry = 0; entry < A.height*B.width; entry++) {
        row = entry / B.width;
        col = entry % B.width;
        for (int elem = 0; elem < A.width; elem++) {
            C.data[entry] += A.data[row*A.width + elem]*B.data[col + elem*B.width];
        }
    } 
  
    return C;
}

template <typename T>
void print_matrix_screen(matrix<T> A) {

    printf("\n| ");
    for(int i = 0; i < A.height; i++) {
        if(i > 0 && i < A.height) {
            printf(" |\n");
            printf("| ");
        }
        for(int j = 0; j < A.width; j++) {
            printf("%d ", A.data[i*A.width + j]);
        }
    }
    printf(" |\n");
}

template <typename T>
void print_matrix_file(matrix<T> A) {

    std::ofstream output;
    output.open("Matrix_Product.txt");

    output << "| ";
    for(int i = 0; i < A.height; i++) {
        if(i > 0 && i < A.height) {
        output << " |\n";
        output << "| ";}
        for(int j = 0; j < A.width; j++) {
            output << A.data[i*A.width + j] << " ";
        }
    }
    output << " |\n";

    printf("\n\n**The result has been written to Matrix_Product.txt**\n\n");
}
