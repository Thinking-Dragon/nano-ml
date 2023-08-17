#pragma once

#include <iostream>
#include <cmath>

class Value
{
public:
    Value(double value = 0.0);

    Value operator+(const Value& other) const;
    Value operator-(const Value& other) const;
    Value operator*(const Value& other) const;
    Value operator/(const Value& other) const;
    Value pow(const double& exponent) const;

    Value operator+(const double& other) const;
    Value operator-(const double& other) const;
    Value operator*(const double& other) const;
    Value operator/(const double& other) const;

    Value relu() const;

    friend std::ostream& operator<<(std::ostream& os, const Value& value);

private:
    double data;
};
