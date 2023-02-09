#include <iostream>

#include "payoff.h"
#include "asianoption.h"
#include "pathgeneration.h"

int main(int argc, char **argv) {
    unsigned numSims = 100000;
    unsigned numIntervals = 250;
    double underlyingPrice = 30.0;
    double strikePrice = 29.0;
    double riskFreeRate = 0.08;
    double underlyingVol = 0.3;
    double timeToExpiry = 1.00; // Years
    std::vector<double> spotPrices(numIntervals, underlyingPrice);

    PayOff* payOffCall = new PayOffCall(strikePrice);
    AsianOptionArithmetic asianOptionArithmetic(payOffCall);

    double payOffSum = 0.0;
    for (int i=0; i<numSims; i++) {
        calc_path_spot_prices(spotPrices, riskFreeRate, underlyingVol,
                              timeToExpiry);
        payOffSum += asianOptionArithmetic.payOffPrice(spotPrices);
    }

    double discountedPayOffAvg = (payOffSum / static_cast<double>(numSims)) * exp(-riskFreeRate * timeToExpiry);
    delete payOffCall;

    std::cout << "Number of Paths:     " << numSims << std::endl;
    std::cout << "Number of Intervals: " << numIntervals << std::endl;
    std::cout << "Underlying Price:    " << underlyingPrice  << std::endl;
    std::cout << "Strike Price:        " << strikePrice << std::endl;
    std::cout << "Risk-Free Rate:      " << riskFreeRate << std::endl;
    std::cout << "Volatility:          " << underlyingVol << std::endl;
    std::cout << "Maturity:            " << timeToExpiry << std::endl;
    std::cout << "Asian Price:         " << discountedPayOffAvg << std::endl;

    return 0;
}