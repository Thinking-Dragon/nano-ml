#include "value.h"

Value::Value(double value) : data(value) {}

Value Value::operator+(const Value& other) const
{
    return Value(data + other.data);
}

Value Value::operator-(const Value& other) const
{
    return Value(data - other.data);
}

Value Value::operator*(const Value& other) const
{
    return Value(data * other.data);
}

Value Value::operator/(const Value& other) const
{
    return Value(data / other.data);
}

Value Value::pow(const double& exponent) const
{
    return Value(std::pow(data, exponent));
}

Value Value::operator+(const double& other) const
{
    return Value(data + other);
}

Value Value::operator-(const double& other) const
{
    return Value(data - other);
}

Value Value::operator*(const double& other) const
{
    return Value(data * other);
}

Value Value::operator/(const double& other) const
{
    return Value(data / other);
}

Value Value::relu() const
{
    return Value(data > 0 ? data : 0);
}

std::ostream& operator<<(std::ostream& os, const Value& value)
{
    os << value.data;
    return os;
}
