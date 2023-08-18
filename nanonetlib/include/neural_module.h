#pragma once

#include <vector>
#include "grad_value.h"

class NeuralModule
{
public:
    void zeroGradient();
    std::vector<GradValue*> getParameters();
};
