#include "Seat.h"

Seat::Seat(int number, SeatType seatType)
    : seatNumber(number), isAvailable(true), seatType(seatType) {}

void Seat::bookSeat() {
    isAvailable = false;
}

void Seat::cancelBooking() {
    isAvailable = true;
}

bool Seat::isSeatAvailable() const {
    return isAvailable;
}

int Seat::getSeatNumber() const {
    return seatNumber;
}

SeatType Seat::getSeatType() const {
    return seatType;
}
