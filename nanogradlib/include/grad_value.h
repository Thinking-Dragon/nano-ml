#pragma once

#include <iostream>
#include <cmath>

class GradValue
{
public:
    GradValue(double value = 0.0);

    GradValue operator+(const GradValue& other) const;
    GradValue operator-(const GradValue& other) const;
    GradValue operator*(const GradValue& other) const;
    GradValue operator/(const GradValue& other) const;
    GradValue pow(const double& exponent) const;

    GradValue operator+(const double& other) const;
    GradValue operator-(const double& other) const;
    GradValue operator*(const double& other) const;
    GradValue operator/(const double& other) const;

    GradValue relu() const;

    friend std::ostream& operator<<(std::ostream& os, const GradValue& value);

private:
    double data;
};
