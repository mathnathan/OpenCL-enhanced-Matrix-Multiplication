Author: Nathan Crock - http://www.mathnathan.com

Honors Thesis Advisor: Mark Sussman

Institute: Florida State University - Undergraduate studies in Applied Mathematics and Scientific Computing. 

This is a simple matrix multiplication program written for my numerical analysis course. I'm planning to use this as a foundation for experimenting with OpenCLi optimization.

FILES:
    matrixmul.hpp - Multiplication algorithm and print functions (library)
    CMakeLists.txt -  Cmake file with build commands (build file)
    INTmatrixmul.cpp - An implementation of my funtions using ints (example)
    FLOATmatrixmul.cpp - An implementation using floats (example)

Compliation Instructions:

-If you don't have cmake you can get it here

    sudo apt-get install cmake

-For a breif introduction to CMake follow my tutorial

    http://mathnathan.com/2010/07/11/getting-started-with-cmake/

-From the build directory run 

    cmake ..
    make

All of the binaries will be built in the build folder. you can run either the INTmatrixmul or the FLOATmatrixmul by using the the ./ command

    ./INTmatrixmul
    ./FLOATmatrixmul


