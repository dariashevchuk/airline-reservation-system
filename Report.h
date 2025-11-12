#ifndef REPORT_H
#define REPORT_H

#include <vector>
#include "Flight.h"

class Report {
private:
    double totalRevenue;
    const std::vector<Flight*>& flights;

public:
    Report(const std::vector<Flight*>& flights);
    void generateFlightReport() const;
    void generateRevenueReport();
};

#endif
