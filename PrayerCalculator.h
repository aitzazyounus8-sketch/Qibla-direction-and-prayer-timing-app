#ifndef PRAYERCALCULATOR_H
#define PRAYERCALCULATOR_H

#include <string>

class PrayerCalculator {
private:
    std::string locationName;
    double latitude;
    double longitude;
    int timezone;
    double qiblaAngle;
    
    std::string prayerTimes[5]; 
    const std::string prayerNames[5] = {"Fajr", "Dhuhr", "Asr", "Maghrib", "Isha"};

    // Helper to turn decimal hours
    void formatTimeStr(int index, double decimalHours);

public:
    // Constructor
    PrayerCalculator(std::string name, double lat, double lon, int tz);

    // Core functionality
    void calculateQibla();
    void calculatePrayerTimes(int dayOfYear);
    
    // Output
    void displayResults() const;
    void saveToFile() const;
};

#endif
