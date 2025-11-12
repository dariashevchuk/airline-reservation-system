#include "Logger.h"
#include <fstream>
#include <iostream>

Logger::Logger(const std::string& logFile) : logFile(logFile) {}

void Logger::saveFlightData(const std::vector<Flight*>& flights) const {
    std::ofstream outFile(logFile);
    if (!outFile) {
        std::cerr << "Failed to open log file for saving flight data.\n";
        return;
    }

    for (const auto& flight : flights) {
        outFile << flight->getPassengerList().size() << " passengers on Flight ID: " << flight->getFlightID() << "\n";
    }

    outFile.close();
}

void Logger::loadFlightData(std::vector<Flight*>& flights) const {
    std::ifstream inFile(logFile);
    if (!inFile) {
        std::cerr << "Failed to open log file for loading flight data.\n";
        return;
    }

    std::string line;
    while (std::getline(inFile, line)) {
        std::cout << line << "\n";
    }

    inFile.close();
}

void Logger::logTransaction(const Reservation& reservation) const {
    std::ofstream outFile(logFile, std::ios::app);
    if (!outFile) {
        std::cerr << "Failed to open log file for logging transactions.\n";
        return;
    }

    outFile << "Reservation: Passenger " << reservation.getPassenger()->getName()
        << " booked a seat on Flight ID: " << reservation.getFlight()->getFlightID() << "\n";

    outFile.close();
}
