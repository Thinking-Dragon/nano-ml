#include "multi_layer_perceptron.h"

MultiLayerPerceptron::MultiLayerPerceptron(int nin, const std::vector<int>& nouts)
{
    std::vector<int> dz = {nin};
    dz.insert(dz.end(), nouts.begin(), nouts.end());

    for(size_t i = 0; i < nouts.size(); ++i)
    {
        layers.push_back(Layer(dz[i], dz[i + 1], i != nouts.size() - 1));
    }
}

std::vector<GradValue> MultiLayerPerceptron::operator()(std::vector<GradValue>& x)
{
    std::vector<GradValue> result = x;

    for(auto layer : layers)
    {
        result = layer(result);
    }

    return result;
}

std::vector<GradValue*> MultiLayerPerceptron::getParameters()
{
    std::vector<GradValue*> parameters;

    for(auto layer : layers)
    {
        std::vector<GradValue*> layerParameters = layer.getParameters();
        parameters.insert(parameters.end(), layerParameters.begin(), layerParameters.end());
    }

    return parameters;
}