#ifndef PASSENGER_H
#define PASSENGER_H

#include <string>
#include "SeatType.h"

class Passenger {
private:
    std::string name;
    std::string contactInfo;
    SeatType seatType;

public:
    Passenger(const std::string& name, const std::string& contact, SeatType seatType);
    std::string getDetails() const;
    std::string getName() const;
    std::string getContactInfo() const;
    SeatType getSeatType() const;
};

#endif
