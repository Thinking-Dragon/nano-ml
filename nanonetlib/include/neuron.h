#pragma once

#include <random>
#include "neural_module.h"
#include "grad_value.h"

class Neuron : public NeuralModule
{
public:
    Neuron(int nin, bool nonlin = true);
    GradValue operator()(std::vector<GradValue> &x);
    std::vector<GradValue*> getParameters();

private:
    std::vector<GradValue> w;
    GradValue b;
    bool nonlin;
};
