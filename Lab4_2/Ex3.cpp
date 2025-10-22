#include "Ex3.h"
#include "Matrix.h"

#include <iostream>

using namespace std;

Ex3::Ex3(std::unique_ptr<Matrix<int>> matrix,
    std::unique_ptr<Generator<int>> generator)
    : Excercise<int>(std::move(matrix), std::move(generator)) {}

void Ex3::Task3() {
    if (matrix->getCount() == 0) {
        return;
    }
    Matrix<int> A(*matrix);

    for (size_t i = 0; i < matrix->getCount(); i++) {
        if (i % 2 == 0) {
            A[i] = (*matrix)[i] + i;
        } else {
            A[i] = (*matrix)[i] - i;
        }
    }
    cout << "A: " << A << endl;
}

