#include "layer.h"

Layer::Layer(int nin, int nout, bool nonlin)
{
    for(size_t i = 0; i < nout; ++i)
    {
        neurons.push_back(Neuron(nin, nonlin));
    }
}

std::vector<GradValue> Layer::operator()(std::vector<GradValue>& x)
{
    std::vector<GradValue> result;

    for(auto neuron : neurons)
    {
        result.push_back(neuron(x));
    }

    return result;
}

std::vector<GradValue*> Layer::getParameters()
{
    std::vector<GradValue*> parameters;

    for(auto neuron : neurons)
    {
        std::vector<GradValue*> neuronParameters = neuron.getParameters();
        parameters.insert(parameters.end(), neuronParameters.begin(), neuronParameters.end());
    }

    return parameters;
}
