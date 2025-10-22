#pragma once
#include "Excercise.h"
#include <memory>

class Ex3 : public Excercise<int>
{
    bool Contains1(int value);
public:
    Ex3(std::unique_ptr<Matrix<int>> matrix,
        std::unique_ptr<Generator<int>> generator);

    ~Ex3() override {}

    void Task() override { Task3(); };

    void Task1() override {};

    void Task2() override {};

    void Task3() override;
};

