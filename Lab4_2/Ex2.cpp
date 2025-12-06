#include "Ex2.h"

Ex2::Ex2(std::unique_ptr<Matrix<int>> matrix,
    std::unique_ptr<Generator<int>> generator)
    : Excercise<int>(std::move(matrix), std::move(generator)) {}

void Ex2::Task() {
    if (matrix->getCount() == 0) {
        return;
    }
    int maxValue = (*matrix)[0];
    for (size_t i = 1; i < matrix->getCount(); i++) {
        if ((*matrix)[i] > maxValue) {
            maxValue = (*matrix)[i];
        }
    }
    // Начинаем с конца, чтобы в случае, когда максимальный
    // элемент сам по себе содержит цифру 1, все остальные
    // после него элементы не были заданы в максимальный.
    //
    // Условие i >= 0 не будет работать, т.к. переменная типа size_t всегда >= 0.
    for (size_t i = matrix->getCount() - 2; i != static_cast<size_t>(-1); i--) {
        if (Contains1((*matrix)[i])) {
            (*matrix)[i + 1] = maxValue;
        }
    }
}

// Contains1 проверяет, есть ли цифра 1 в числе value
bool Ex2::Contains1(int value) {
    if (value < 0) {
        value = -value;
    }
    while (value) {
        int digit = value % 10;
        if (digit == 1) {
            return true;
        }
        value /= 10;
    }
    return false;
}
