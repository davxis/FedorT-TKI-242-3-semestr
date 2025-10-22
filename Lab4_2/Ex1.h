#pragma once

#include "Excercise.h"
#include <memory>

class Ex1 : public Excercise<int>
{
public:
    Ex1(std::unique_ptr<Matrix<int>> matrix,
        std::unique_ptr<Generator<int>> generator);

    ~Ex1() override {}

    void Task() override { Task1(); };

    void Task1() override;

    void Task2() override {};
    
    void Task3() override {};
};

