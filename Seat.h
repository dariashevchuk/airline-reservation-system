#ifndef SEAT_H
#define SEAT_H

#include <string>
#include "SeatType.h"

class Seat {
private:
    int seatNumber;
    bool isAvailable;
    SeatType seatType;

public:
    Seat(int number, SeatType seatType);
    void bookSeat();
    void cancelBooking();
    bool isSeatAvailable() const;
    int getSeatNumber() const;
    SeatType getSeatType() const;
};

#endif
