#include "DomesticFlight.h"
#include <iostream>

DomesticFlight::DomesticFlight(int id, const std::string& depCity, const std::string& dest, const std::string& time,
    double priceEconomy, double priceBusiness, double priceFirst, int seatCount, const std::string& policy)
    : Flight(id, depCity, dest, time, priceEconomy, priceBusiness, priceFirst, seatCount), domesticPolicy(policy) {}

void DomesticFlight::displayInfo() const {
    std::cout << "Domestic Flight ID: " << flightID
        << ", Departure: " << departureCity
        << ", Arrival: " << destination
        << ", Policy: " << domesticPolicy << "\n";
}

std::string DomesticFlight::getDomesticPolicy() const {
    return domesticPolicy;
}
