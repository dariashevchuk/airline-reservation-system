#ifndef PAYMENT_H
#define PAYMENT_H

#include "Reservation.h"
#include <string>

enum class PaymentMethod {
    CreditCard,
    DebitCard,
    PayPal
};

class Payment {
private:
    double amount;
    PaymentMethod paymentMethod;

public:
    Payment(double amount, PaymentMethod method);
    bool processPayment(const Reservation& reservation) const;
};

#endif
