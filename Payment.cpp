#include "Payment.h"
#include <iostream>

Payment::Payment(double amount, PaymentMethod method)
    : amount(amount), paymentMethod(method) {}

bool Payment::processPayment(const Reservation& reservation) const {
    std::cout << "Processing payment of $" << amount
        << " for Passenger: " << reservation.getPassenger()->getName()
        << " on Flight ID: " << reservation.getFlight()->getFlightID() << "\n";

    return true;
}
