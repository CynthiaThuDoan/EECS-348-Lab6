
#include <iostream>
#include <fstream>
#include <iomanip> // For setw

const int MAX_SIZE = 10; // Maximum size of the square matrix

// Function to read matrix data from a file
void readMatrixFromFile(int matrix[][MAX_SIZE], int size, std::ifstream& file) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            file >> matrix[i][j];
        }
    }
}

// Function to print a matrix
void printMatrix(int matrix[][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << std::setw(4) << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Function to add two matrices
void addMatrices(int matrixA[][MAX_SIZE], int matrixB[][MAX_SIZE], int result[][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrices(int matrixA[][MAX_SIZE], int matrixB[][MAX_SIZE], int result[][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < size; ++k) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

// Function to subtract one matrix from another
void subtractMatrices(int matrixA[][MAX_SIZE], int matrixB[][MAX_SIZE], int result[][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
}

// Function to update an element of the matrix
void updateElement(int matrix[][MAX_SIZE], int row, int col, int newValue, int size) {
    if (row >= 0 && row < size && col >= 0 && col < size) {
        matrix[row][col] = newValue;
    } else {
        std::cerr << "Invalid row or column index!" << std::endl;
    }
}

// Function to find the maximum value in a matrix
int getMaxValue(int matrix[][MAX_SIZE], int size) {
    int maxVal = matrix[0][0];
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (matrix[i][j] > maxVal) {
                maxVal = matrix[i][j];
            }
        }
    }
    return maxVal;
}

// Function to transpose a matrix
void transposeMatrix(int matrix[][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            std::swap(matrix[i][j], matrix[j][i]);
        }
    }
}

int main() {
    std::string filename;
    std::cout << "Enter the name of the input file: ";
    std::cin >> filename;

    std::ifstream inputFile(filename);
    if (!inputFile) {
        std::cerr << "Failed to open the input file." << std::endl;
        return 1;
    }

    int size;
    inputFile >> size;

    int matrixA[MAX_SIZE][MAX_SIZE];
    int matrixB[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];

    // Read matrices A and B from the input file
    readMatrixFromFile(matrixA, size, inputFile);
    readMatrixFromFile(matrixB, size, inputFile);

    // Close the input file
    inputFile.close();

    std::cout << "Matrix A:" << std::endl;
    printMatrix(matrixA, size);
    std::cout << std::endl;

    std::cout << "Matrix B:" << std::endl;
    printMatrix(matrixB, size);
    std::cout << std::endl;

    // Menu for matrix operations
    int choice;
    do {
        std::cout << "Choose an operation:" << std::endl;
        std::cout << "1. Add two matrices" << std::endl;
        std::cout << "2. Multiply two matrices" << std::endl;
        std::cout << "3. Subtract the second matrix from the first matrix" << std::endl;
        std::cout << "4. Update an element of the first matrix" << std::endl;
        std::cout << "5. Get the max value of the first matrix" << std::endl;
        std::cout << "6. Transpose the first matrix" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addMatrices(matrixA, matrixB, result, size);
                std::cout << "Matrix Sum (A + B):" << std::endl;
                printMatrix(result, size);
                break;
            case 2:
                multiplyMatrices(matrixA, matrixB, result, size);
                std::cout << "Matrix Product (A * B):" << std::endl;
                printMatrix(result, size);
                break;
            case 3:
                subtractMatrices(matrixA, matrixB, result, size);
                std::cout << "Matrix Difference (A - B):" << std::endl;
                printMatrix(result, size);
                break;
            case 4:
                int row, col, newValue;
                std::cout << "Enter row index: ";
                std::cin >> row;
                std::cout << "Enter column index: ";
                std::cin >> col;
                std::cout << "Enter new value: ";
                std::cin >> newValue;
                updateElement(matrixA, row, col, newValue, size);
                std::cout << "Updated Matrix A:" << std::endl;
                printMatrix(matrixA, size);
                break;
            case 5:
                std::cout << "Max value of Matrix A: " << getMaxValue(matrixA, size) << std::endl;
                break;
            case 6:
                transposeMatrix(matrixA, size);
                std::cout << "Transposed Matrix A:" << std::endl;
                printMatrix(matrixA, size);
                break;
            case 0:
                std::cout << "Exiting program..." << std::endl;
                break; // Add a semicolon here
        }
    } while (choice != 0); // Add this line

    return 0; // Add this line
}