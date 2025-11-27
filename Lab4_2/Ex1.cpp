#include "Ex1.h"

Ex1::Ex1(std::unique_ptr<Matrix<int>> matrix,
    std::unique_ptr<Generator<int>> generator)
    : Excercise<int>(std::move(matrix), std::move(generator)) {}

void Ex1::Task() {
    if (matrix->getCount() == 0) {
        return;
    }
    int maxValue = (*matrix)[0];
    for (size_t i = 1; i < matrix->getCount(); i++) {
        if ((*matrix)[i] > maxValue) {
            maxValue = (*matrix)[i];
        }
    }
    for (size_t i = 0; i < matrix->getCount(); i++) {
        if ((*matrix)[i] == maxValue) {
            (*matrix)[i] = -maxValue;
        }
    }
}
