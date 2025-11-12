#include "Flight.h"
#include <algorithm>

Flight::Flight(int id, const std::string& depCity, const std::string& dest, const std::string& time,
    double priceEconomy, double priceBusiness, double priceFirst, int seatCount)
    : flightID(id), departureCity(depCity), destination(dest), departureTime(time),
    priceEconomy(priceEconomy), priceBusiness(priceBusiness), priceFirst(priceFirst) {
    for (int i = 1; i <= seatCount; ++i) {
        seats.emplace_back(i, SeatType::Economy);
    }
}

Flight::~Flight() {
    for (Passenger* passenger : passengers) {
        delete passenger;
    }
}

bool Flight::bookSeat(Passenger* passenger, int seatNumber) {
    auto it = std::find_if(seats.begin(), seats.end(), [seatNumber](const Seat& seat) {
        return seat.getSeatNumber() == seatNumber && seat.isSeatAvailable();
        });

    if (it != seats.end()) {
        it->bookSeat();
        passengers.push_back(passenger);
        return true;
    }
    return false;
}

bool Flight::cancelSeat(Passenger* passenger) {
    auto it = std::find(passengers.begin(), passengers.end(), passenger);
    if (it != passengers.end()) {
        passengers.erase(it);
        return true;
    }
    return false;
}

int Flight::getAvailableSeats() const {
    return std::count_if(seats.begin(), seats.end(), [](const Seat& seat) {
        return seat.isSeatAvailable();
        });
}

const std::vector<Passenger*>& Flight::getPassengerList() const {
    return passengers;
}

int Flight::getFlightID() const {
    return flightID;
}

const std::string& Flight::getDestination() const {
    return destination;
}

const std::string& Flight::getDepartureCity() const {
    return departureCity;
}

const std::string& Flight::getDepartureTime() const {
    return departureTime;
}

double Flight::getPriceEconomy() const {
    return priceEconomy;
}

double Flight::getPriceBusiness() const {
    return priceBusiness;
}

double Flight::getPriceFirst() const {
    return priceFirst;
}

double Flight::calculateRevenue() const {
    double revenue = 0;
    for (const auto& passenger : passengers) {
        revenue += (passenger->getSeatType() == SeatType::Economy) ? priceEconomy :
            (passenger->getSeatType() == SeatType::Business) ? priceBusiness :
            priceFirst;
    }
    return revenue;
}
