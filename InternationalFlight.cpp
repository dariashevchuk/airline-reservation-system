#include "InternationalFlight.h"
#include <iostream>

InternationalFlight::InternationalFlight(int id, const std::string& depCity, const std::string& dest, const std::string& time,
    double priceEconomy, double priceBusiness, double priceFirst, int seatCount, const std::string& customs)
    : Flight(id, depCity, dest, time, priceEconomy, priceBusiness, priceFirst, seatCount), customsRequirements(customs) {}

void InternationalFlight::displayInfo() const {
    std::cout << "International Flight ID: " << flightID
        << ", Departure: " << departureCity
        << ", Arrival: " << destination
        << ", Customs: " << customsRequirements << "\n";
}

std::string InternationalFlight::getCustomsRequirements() const {
    return customsRequirements;
}
