#pragma once
#include "Excercise.h"
#include <memory>

class Ex3 : public Excercise<int>
{
    bool Contains1(int value);
public:
    Ex3(std::unique_ptr<Matrix<int>> matrix,
        std::unique_ptr<Generator<int>> generator);

    void Task() override;
};

