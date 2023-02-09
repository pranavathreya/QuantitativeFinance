#ifndef ASIANOPTION_CPP
#define ASIANOPTION_CPP

#include <numeric>
#include <cmath>
#include "asianoption.h"

AsianOption::AsianOption(PayOff* payOff) : payOff(payOff) {}

AsianOptionArithmetic::AsianOptionArithmetic(PayOff* payOff) : AsianOption(payOff) {}

double AsianOptionArithmetic::payOffPrice(const std::vector<double>& spotPrices) const {
    unsigned numTimes = spotPrices.size();
    double sum = std::accumulate(spotPrices.begin(), spotPrices.end(), 0);
    double arithMean = sum / static_cast<double>(numTimes);
    return (*payOff)(arithMean);
}

double AsianOptionGeometric::payOffPrice(const std::vector<double> &spotPrices) const {
    unsigned numTimes = spotPrices.size();
    double logSum = 0.0;
    for (int i=0; i<spotPrices.size(); i++) {
        logSum += log(spotPrices[i]);
    }
    double geomMean = exp(logSum / static_cast<double>(numTimes));
    return (*payOff)(geomMean);
}

#endif
