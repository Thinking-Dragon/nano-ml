#pragma once

#include <iostream>
#include <format>

#include <cmath>
#include <functional>

#include <vector>
#include <set>

class GradValue
{
public:
    GradValue(double value = 0.0, std::vector<GradValue*> previousValues = std::vector<GradValue*> {});

    GradValue operator+(GradValue& other);
    GradValue operator-(GradValue& other);
    GradValue operator*(GradValue& other);
    GradValue operator/(GradValue& other);
    GradValue pow(double& exponent);
    GradValue operator-();

    GradValue relu();

    void updateGradientsBackward();

    friend std::ostream& operator<<(std::ostream& os, const GradValue& value);

private:
    double data;
    double gradient;

    std::vector<GradValue*> previousValues;
    std::function<void()> updateGradientBackward;
};
