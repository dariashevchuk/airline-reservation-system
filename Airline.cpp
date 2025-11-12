#include "Airline.h"
#include "DomesticFlight.h"
#include "InternationalFlight.h"

#include <algorithm>
#include <fstream>
#include <sstream>
#include <iostream>

// Constructor
Airline::Airline() : totalRevenue(0) {}

// Destructor
Airline::~Airline() {
    // Clean up dynamically allocated flights
    for (Flight* flight : flights) {
        delete flight;
    }
}

// Add a flight to the vector
void Airline::addFlight(Flight* flight) {
    flights.push_back(flight);
}

// Remove a flight by ID
void Airline::removeFlight(int flightID) {
    auto it = std::remove_if(flights.begin(), flights.end(),
                             [flightID](Flight* flight) {
                                 return flight->getFlightID() == flightID;
                             });
    if (it != flights.end()) {
        // Delete the removed Flight objects
        for (auto itr = it; itr != flights.end(); ++itr) {
            delete *itr;
        }
        flights.erase(it, flights.end());
        std::cout << "Flight with ID " << flightID << " removed.\n";
    } else {
        std::cout << "No flight found with ID " << flightID << ".\n";
    }
}

// Accessor for flights
const std::vector<Flight*>& Airline::getFlights() const {
    return flights;
}

// Generates a simple airline report
void Airline::generateReport() const {
    std::cout << "Airline Report:\n";
    for (auto& flight : flights) {
        std::cout << "Flight ID: " << flight->getFlightID()
                  << ", Destination: " << flight->getDestination()
                  << ", Total Revenue: $" << flight->calculateRevenue()
                  << "\n";
    }
}

// Loads flights from the given text file
void Airline::loadFlightsFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << "\n";
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        int id, seatCount, type;
        double priceEconomy, priceBusiness, priceFirst;
        std::string departureCity, arrivalCity, departureDate, departureTime, additionalInfo;

        // Parse the line into variables
        // Order of data in file: [FlightID] [DepartureCity] [ArrivalCity] [Date] [Time]
        //                       [Seats] [PriceEconomy] [PriceBusiness] [PriceFirst] [Type]
        // example: 1234 Prague London 15.02.2025 12:35 300 50 100 150 2
        if (!(iss >> id >> departureCity >> arrivalCity >> departureDate >> departureTime
                  >> seatCount >> priceEconomy >> priceBusiness >> priceFirst >> type)) {
            std::cerr << "Error: Invalid data format in line: " << line << "\n";
            continue;
        }

        // Read additional policy or customs info (if present)
        // For example, if you want to store extra text after the type
        std::getline(iss, additionalInfo);

        // Construct the flight object based on the type
        if (type == 1) {
            flights.push_back(new DomesticFlight(
                id,
                departureCity,
                arrivalCity,
                departureDate + " " + departureTime, // Combine date + time
                priceEconomy,
                priceBusiness,
                priceFirst,
                seatCount,
                additionalInfo // domestic policy
            ));
        } else if (type == 2) {
            flights.push_back(new InternationalFlight(
                id,
                departureCity,
                arrivalCity,
                departureDate + " " + departureTime,
                priceEconomy,
                priceBusiness,
                priceFirst,
                seatCount,
                additionalInfo // customs requirements
            ));
        } else {
            std::cerr << "Error: Unknown flight type (" << type << ") in line: " << line << "\n";
        }
    }

    file.close();
    std::cout << "Flights loaded successfully from " << filename << "\n";
}



//Airline::Airline() : totalRevenue(0) {}
//
//void Airline::addFlight(Flight* flight) {
//    flights.push_back(flight);
//}
//
//void Airline::removeFlight(int flightID) {
//    auto it = std::remove_if(flights.begin(), flights.end(), [flightID](Flight* flight) {
//        return flight->getFlightID() == flightID;
//        });
//
//    if (it != flights.end()) {
//        flights.erase(it, flights.end());
//    }
//}
//
//const std::vector<Flight*>& Airline::getFlights() const {
//    return flights;
//}
//
//void Airline::generateReport() const {
//    std::cout << "Airline Report:\n";
//    for (const auto& flight : flights) {
//        std::cout << "Flight ID: " << flight->getFlightID()
//            << ", Destination: " << flight->getDestination()
//            << ", Total Revenue: $" << flight->calculateRevenue() << "\n";
//    }
//}
//
//Airline::~Airline() {
//    for (auto flight : flights) {
//        delete flight;
//    }
//}
