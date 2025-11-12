#ifndef DOMESTICFLIGHT_H
#define DOMESTICFLIGHT_H

#include "Flight.h"

class DomesticFlight : public Flight {
private:
    std::string domesticPolicy;

public:
    DomesticFlight(int id, const std::string& depCity, const std::string& dest, const std::string& time,
        double priceEconomy, double priceBusiness, double priceFirst, int seatCount, const std::string& policy);

    void displayInfo() const override;
    std::string getDomesticPolicy() const;
};

#endif
