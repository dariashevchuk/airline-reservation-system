#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <vector>
#include "Flight.h"
#include "Reservation.h"

class Logger {
private:
    std::string logFile;

public:
    Logger(const std::string& logFile);
    void saveFlightData(const std::vector<Flight*>& flights) const;
    void loadFlightData(std::vector<Flight*>& flights) const;
    void logTransaction(const Reservation& reservation) const;
};

#endif
