#pragma once
#include "Excercise.h"
#include <memory>

class Ex2 : public Excercise<int>
{
    bool Contains1(int value);
public:
    Ex2(std::unique_ptr<Matrix<int>> matrix,
        std::unique_ptr<Generator<int>> generator);

    ~Ex2() override {}

    void Task() override { Task2(); };

    void Task1() override {};

    void Task2() override;

    void Task3() override {};
};

