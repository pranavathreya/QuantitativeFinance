#ifndef __PAY_OFF_CPP
#define __PAY_OFF_CPP

#include "payoff.h"

PayOff::PayOff() {}

PayOffCall::PayOffCall(const double& _strikePrice) { strikePrice = _strikePrice; }

double PayOffCall::operator()  (const double& spotPrice) const {
    return std::max(spotPrice-strikePrice, 0.0);
}

PayOffPut::PayOffPut(const double& _strikePrice) {
    strikePrice = _strikePrice;
}

double PayOffPut::operator() (const double& spotPrice) const {
    return std::max(strikePrice-spotPrice, 0.0);
}

#endif