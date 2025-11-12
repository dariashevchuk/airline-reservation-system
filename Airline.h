#ifndef AIRLINE_H
#define AIRLINE_H
#include <string>
#include <vector>
#include "Flight.h"

class Airline {
private:
    std::vector<Flight*> flights;
    double totalRevenue;

public:
    Airline();
    ~Airline();
    
    void addFlight(Flight* flight);
    void removeFlight(int flightID);
    const std::vector<Flight*>& getFlights() const;
    void generateReport() const;
    double calculateTotalRevenue();
    void loadFlightsFromFile(const std::string& filename);
};


#endif
