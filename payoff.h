#ifndef __PAY_OFF_HPP
#define __PAY_OFF_HPP

#include <algorithm>

class PayOff {
public:
    PayOff();
    virtual ~PayOff() {};
    
    virtual double operator() (const double& S) const = 0;
};

class PayOffCall : public PayOff {
private:
    double strikePrice;
    
public:
    PayOffCall(const double& optionStrikePrice);
    virtual ~PayOffCall() {};
    
    virtual double operator() (const double& S) const;
};

class PayOffPut : public PayOff {
private:
    double strikePrice;
    
public:
    PayOffPut(const double& optionStrikePrice);
    virtual ~PayOffPut() {};
    
    virtual double operator() (const double& S) const;
};

#endif
