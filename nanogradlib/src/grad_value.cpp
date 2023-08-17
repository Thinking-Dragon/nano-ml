#include "grad_value.h"

GradValue::GradValue(double value) : data(value), gradient(0.0) {}

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

GradValue GradValue::pow(double& exponent)
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

GradValue GradValue::operator+(const double& other) const
{
    return GradValue(data + other);
}

GradValue GradValue::operator-(const double& other) const
{
    return GradValue(data - other);
}

GradValue GradValue::operator*(const double& other) const
{
    return GradValue(data * other);
}

GradValue GradValue::operator/(const double& other) const
{
    return GradValue(data / other);
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

std::ostream& operator<<(std::ostream& os, const GradValue& value)
{
    os << value.data;
    return os;
}
