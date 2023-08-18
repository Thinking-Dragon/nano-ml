#include "neural_module.h"

void NeuralModule::zeroGradient()
{
    for(auto parameter : getParameters())
    {
        parameter->zeroGradient();
    }
}

std::vector<GradValue*> NeuralModule::getParameters()
{
    return std::vector<GradValue*> {};
}
