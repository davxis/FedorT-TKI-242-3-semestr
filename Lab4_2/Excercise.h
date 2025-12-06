#pragma once

#include "../MyLib/Matrix.h"
#include "../MyLib/Generator.h"
#include <memory>
#include <iostream>

template<class T>
class Excercise
{
protected:
    std::unique_ptr<Matrix<T>> matrix;
    std::unique_ptr<Generator<T>> generator;

public:
    Excercise(std::unique_ptr<Matrix<T>> matrix,
        std::unique_ptr<Generator<T>> generator)
        : matrix(std::move(matrix)),
        generator(std::move(generator)) {}

    virtual ~Excercise() = default;

    // Do() - это общий алгоритм выполнения какого-либо задания
    void Do() {
        matrix->generateValues(*generator);
        std::cout << "До изменения:    " << *matrix << std::endl;
        Task();
        std::cout << "После изменения: " << *matrix << std::endl;
        std::cout << std::endl;
    }

    // Task() выполняет необходимую задачу (Task1, Task2 или Task3)
    virtual void Task() = 0;
};

