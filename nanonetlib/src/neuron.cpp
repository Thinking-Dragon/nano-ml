#include "neuron.h"

Neuron::Neuron(int nin, bool nonlin) : b(0), nonlin(nonlin)
{
    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution(-1.0, 1.0);

    for(int i = 0; i < nin; ++i)
    {
        w.push_back(GradValue(distribution(generator)));
    }
}

GradValue Neuron::operator()(std::vector<GradValue> &x)
{
    GradValue accumulator = b;

    for(size_t i = 0; i < w.size(); ++i)
    {
        GradValue value = w[i] * x[i];
        accumulator = accumulator + value;
    }

    return nonlin ? accumulator.relu() : accumulator;
}

std::vector<GradValue*> Neuron::getParameters() {
    std::vector<GradValue*> parameters;

    for(auto wi : w)
    {
        parameters.push_back(&wi);
    }

    parameters.push_back(&b);

    return parameters;
}