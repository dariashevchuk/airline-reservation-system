#ifndef INTERNATIONALFLIGHT_H
#define INTERNATIONALFLIGHT_H

#include "Flight.h"

class InternationalFlight : public Flight {
private:
    std::string customsRequirements;

public:
    InternationalFlight(int id, const std::string& depCity, const std::string& dest, const std::string& time,
        double priceEconomy, double priceBusiness, double priceFirst, int seatCount, const std::string& customs);

    void displayInfo() const override;
    std::string getCustomsRequirements() const;
};

#endif
