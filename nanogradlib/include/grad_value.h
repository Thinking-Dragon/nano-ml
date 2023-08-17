#pragma once

#include <iostream>
#include <cmath>
#include <functional>

class GradValue
{
public:
    GradValue(double value = 0.0);

    GradValue operator+(GradValue& other);
    GradValue operator-(GradValue& other);
    GradValue operator*(GradValue& other);
    GradValue operator/(GradValue& other);
    GradValue pow(double& exponent);
    GradValue operator-();

    GradValue relu();

    friend std::ostream& operator<<(std::ostream& os, const GradValue& value);

private:
    double data;
    double gradient;

    std::function<void()> updateGradientBackward;
};
