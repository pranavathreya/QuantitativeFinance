#ifndef __ASIAN_H
#define __ASIAN_H

#include <vector>
#include "payoff.h"


class AsianOption {
protected:
    PayOff* payOff;
    
public:
    AsianOption(PayOff* _pay_off);
    virtual ~AsianOption() {};
    
    virtual double payOffPrice(
        const std::vector<double>& spot_prices
        ) const = 0;
};

class AsianOptionArithmetic : public AsianOption {
public:
    AsianOptionArithmetic(PayOff* payOff1);
    virtual ~AsianOptionArithmetic() {};
    
    virtual double payOffPrice(const std::vector<double>& spot_prices) const;
};

class AsianOptionGeometric : public AsianOption {
public:
    AsianOptionGeometric(PayOff* payOff1);
    virtual ~AsianOptionGeometric() {};
    
    virtual double payOffPrice(const std::vector<double>& spot_prices) const;
};

#endif

