#include "grad_value.h"

GradValue::GradValue(double value, std::vector<GradValue*> previousValues)
    : data(value), gradient(0.0), previousValues(previousValues) {}

GradValue GradValue::operator+(GradValue& other)
{
    GradValue result = GradValue(data + other.data);

    result.updateGradientBackward = [&]
    {
        gradient += result.gradient;
        other.gradient += result.gradient;
    };

    return result;
}

GradValue GradValue::operator-(GradValue& other)
{
    GradValue result = GradValue(data - other.data);

    result.updateGradientBackward = [&]
    {
        gradient += result.gradient;
        other.gradient -= result.gradient;
    };

    return result;
}

GradValue GradValue::operator*(GradValue& other)
{
    GradValue result = GradValue(data * other.data);

    result.updateGradientBackward = [&]
    {
        gradient += other.data * result.gradient;
        other.gradient += data * result.gradient;
    };

    return result;
}

GradValue GradValue::pow(double exponent)
{
    GradValue result = GradValue(std::pow(data, exponent));

    result.updateGradientBackward = [&]
    {
        gradient += (exponent * std::pow(data, exponent - 1)) * result.gradient;
    };

    return result;
}

GradValue GradValue::operator-()
{
    return GradValue(-data);
}

GradValue GradValue::operator/(GradValue& other)
{
    GradValue result = GradValue(data / other.data);

    result.updateGradientBackward = [&]
    {
        gradient += result.gradient / other.data;
        other.gradient -= (data / (other.data * other.data)) * result.gradient;
    };

    return result;
}

GradValue GradValue::relu()
{
    GradValue result = GradValue(data > 0 ? data : 0);

    result.updateGradientBackward = [&]
    {
        gradient += (data > 0) ? result.gradient : 0;
    };

    return result;
}

void GradValue::zeroGradient()
{
    gradient = 0;
}

void GradValue::updateGradientsBackward()
{
    std::vector<GradValue*> topological_order;
    std::set<GradValue*> visited;

    std::function<void(GradValue*)> build_topological_order = [&](GradValue* value)
    {
        if(visited.find(value) == visited.end())
        {
            visited.insert(value);

            for(GradValue* child : value->previousValues)
            {
                build_topological_order(child);
            }

            topological_order.push_back(value);
        }
    };

    build_topological_order(this);

    gradient = 1.0;
    for(auto iterator = topological_order.rbegin(); iterator != topological_order.rend(); ++iterator)
    {
        GradValue* value = *iterator;
        value->updateGradientBackward();
    }
}

std::ostream& operator<<(std::ostream& os, const GradValue& value)
{
    os << std::format("GradValue(data: {}, gradient: {})", value.data, value.gradient);
    return os;
}
