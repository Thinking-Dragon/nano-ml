#pragma once

#include <vector>
#include "neural_module.h"
#include "layer.h"

class MultiLayerPerceptron : public NeuralModule
{
public:
    MultiLayerPerceptron(int nin, const std::vector<int>& nouts);

    std::vector<GradValue> operator()(std::vector<GradValue>& x);
    std::vector<GradValue*> getParameters();

private:
    std::vector<Layer> layers;
};
