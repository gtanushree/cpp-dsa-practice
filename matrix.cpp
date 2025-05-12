/*A vector of vectors in C++ is a dynamic 2D array, where each element of the main vector is itself another vector. 
This structure allows for rows of potentially different lengths, offering flexibility compared to traditional fixed-size arrays. 
It's commonly used to represent matrices, tables, or any grid-like data where the dimensions might not be known at compile time.*/

#include <iostream>
#include <vector>

int main(){
    // Declare a vector of vector of integers
    std::vector<std::vector<int>> matrix; // This declares a 2D vector named matrix, where each element is a vector<int>. Think of it as a grid/ table that can shrink/ grow dynamically.

    // Add rowse to the matrix
    matrix.push_back({1, 2, 3});
    matrix.push_back({4, 5});
    matrix.push_back({6, 7, 8, 9}); // This is called a jagged array.

    // Access and print elements
    for (size_t i = 0; i < matrix.size(); ++i)
    //size_t is an unsigned integer type used to represent the size of objects or array indices. It’s defined in the C++ standard library and is returned by functions like .size() for vectors, arrays, strings, etc.
    {
        for (size_t j = 0; j < matrix[i].size(); ++j){
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Modify an element
    matrix[1][1] = 10;

    // Print the modified element
    std::cout << "Modified element at matrix[1][1]: " << matrix[1][1] << std::endl;

    return 0;
}