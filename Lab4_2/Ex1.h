#pragma once

#include "Excercise.h"
#include <memory>

class Ex1 : public Excercise<int>
{
public:
    Ex1(std::unique_ptr<Matrix<int>> matrix,
        std::unique_ptr<Generator<int>> generator);

    void Task() override;
};

