#include "Passenger.h"
#include <sstream>

Passenger::Passenger(const std::string& name, const std::string& contact, SeatType seatType)
    : name(name), contactInfo(contact), seatType(seatType) {}

std::string Passenger::getDetails() const {
    std::ostringstream details;
    details << "Name: " << name
        << ", Contact: " << contactInfo
        << ", Seat Type: " << (seatType == SeatType::Economy ? "Economy" :
            seatType == SeatType::Business ? "Business" : "First Class");
    return details.str();
}

std::string Passenger::getName() const {
    return name;
}

std::string Passenger::getContactInfo() const {
    return contactInfo;
}

SeatType Passenger::getSeatType() const {
    return seatType;
}
