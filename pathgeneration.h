#ifndef __PATH_GENERATION_H
#define __PATH_GENERATION_H

#include <vector>
#include <cmath>

double gaussian_box_muller() {
    double x = 0.0;
    double y = 0.0;
    double euclid_sq = 0.0;
    
    do {
        x = 2.0 * rand() / static_cast<double>(RAND_MAX)-1;
        y = 2.0 * rand() / static_cast<double>(RAND_MAX)-1;
        euclid_sq = x*x + y*y;
    } while (euclid_sq >= 1.0);
    
    return x*sqrt(-2*log(euclid_sq)/euclid_sq);
}

void calc_path_spot_prices(
    std::vector<double>& spotPrices,
    const double riskFreeRate,
    const double& underlyingVolatility,
    const double& expiryTime) {
        double driftTime = expiryTime / static_cast<double>(spotPrices.size());
        double drift = exp(driftTime * (riskFreeRate - 0.5 * underlyingVolatility * underlyingVolatility));
        double volatility = sqrt(underlyingVolatility * underlyingVolatility * driftTime);
        
        for (int i=1; i<spotPrices.size(); i++) {
            double gauss_bm = gaussian_box_muller();
            spotPrices[i] = spotPrices[i-1] * drift * exp(volatility * gauss_bm);
        }
}

#endif
