#include "Reservation.h"

Reservation::Reservation(Flight* flight, Passenger* passenger)
    : flight(flight), passenger(passenger) {}

bool Reservation::bookSeat() {
    return flight->bookSeat(passenger, 1); // Default seat selection (can be expanded for specific seats)
}

bool Reservation::cancelSeat() {
    return flight->cancelSeat(passenger);
}

Flight* Reservation::getFlight() const {
    return flight;
}

Passenger* Reservation::getPassenger() const {
    return passenger;
}
