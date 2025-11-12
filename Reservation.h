#ifndef RESERVATION_H
#define RESERVATION_H

#include "Flight.h"
#include "Passenger.h"

class Reservation {
private:
    Flight* flight;
    Passenger* passenger;

public:
    Reservation(Flight* flight, Passenger* passenger);

    bool bookSeat();
    bool cancelSeat();

    Flight* getFlight() const;
    Passenger* getPassenger() const;
};

#endif
