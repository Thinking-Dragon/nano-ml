#include "grad_value.h"

GradValue::GradValue(double value) : data(value) {}

GradValue GradValue::operator+(const GradValue& other) const
{
    return GradValue(data + other.data);
}

GradValue GradValue::operator-(const GradValue& other) const
{
    return GradValue(data - other.data);
}

GradValue GradValue::operator*(const GradValue& other) const
{
    return GradValue(data * other.data);
}

GradValue GradValue::operator/(const GradValue& other) const
{
    return GradValue(data / other.data);
}

GradValue GradValue::pow(const double& exponent) const
{
    return GradValue(std::pow(data, exponent));
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

GradValue GradValue::relu() const
{
    return GradValue(data > 0 ? data : 0);
}

std::ostream& operator<<(std::ostream& os, const GradValue& value)
{
    os << value.data;
    return os;
}
