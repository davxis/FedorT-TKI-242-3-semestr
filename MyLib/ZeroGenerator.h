#pragma once

#include "Generator.h"

class ZeroGenerator : public Generator<int>
{
public:
    ZeroGenerator();

    int generate() override;
};

