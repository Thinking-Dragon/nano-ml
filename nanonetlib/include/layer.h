#pragma once

#include <vector>
#include "neural_module.h"
#include "neuron.h"

class Layer : public NeuralModule
{
public:
    Layer(int nin, int nout, bool nonlin = true);

    std::vector<GradValue> operator()(std::vector<GradValue>& x);
    std::vector<GradValue*> getParameters();

private:
    std::vector<Neuron> neurons;
};
