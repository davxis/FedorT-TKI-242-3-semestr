#pragma once

#include "Generator.h"

class ConstGenerator : public Generator<int>
{
    int value;

public:
    ConstGenerator(const int value);

    int generate() override;
};

