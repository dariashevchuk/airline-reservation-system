#ifndef FLIGHT_H
#define FLIGHT_H

#include <vector>
#include <string>
#include "Seat.h"
#include "Passenger.h"

class Flight {
protected:
    int flightID;
    std::string destination;
    std::string departureCity;
    std::string departureTime;
    double priceEconomy;
    double priceBusiness;
    double priceFirst;
    std::vector<Seat> seats;
    std::vector<Passenger*> passengers;

public:
    Flight(int id, const std::string& depCity, const std::string& dest, const std::string& time,
        double priceEconomy, double priceBusiness, double priceFirst, int seatCount);
    virtual ~Flight();
    virtual void displayInfo() const = 0;
    bool bookSeat(Passenger* passenger, int seatNumber);
    bool cancelSeat(Passenger* passenger);
    int getAvailableSeats() const;
    const std::vector<Passenger*>& getPassengerList() const;
    int getFlightID() const;
    const std::string& getDestination() const;
    const std::string& getDepartureCity() const;
    const std::string& getDepartureTime() const;
    double getPriceEconomy() const;
    double getPriceBusiness() const;
    double getPriceFirst() const;
    double calculateRevenue() const;
};

#endif
