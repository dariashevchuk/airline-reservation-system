#include "Report.h"
#include <iostream>
#include <algorithm>

Report::Report(const std::vector<Flight*>& flights) : flights(flights), totalRevenue(0) {}

void Report::generateFlightReport() const {
    std::cout << "Flight Report:\n";
    for (const auto& flight : flights) {
        std::cout << "Flight ID: " << flight->getFlightID()
            << ", Departure City: " << flight->getDepartureCity()
            << ", Arrival City: " << flight->getDestination()
            << ", Departure Time: " << flight->getDepartureTime()
            << ", Available Seats: " << flight->getAvailableSeats() << "\n";
    }
}

void Report::generateRevenueReport() {
    totalRevenue = 0;
    for (const auto& flight : flights) {
        for (const auto& passenger : flight->getPassengerList()) {
            double price = (passenger->getSeatType() == SeatType::Economy) ? flight->getPriceEconomy() :
                (passenger->getSeatType() == SeatType::Business) ? flight->getPriceBusiness() :
                flight->getPriceFirst();
            totalRevenue += price;
        }
    }
    std::cout << "Total Revenue: $" << totalRevenue << "\n";
}
