#ifndef PRAYER_CALCULATOR_H
#define PRAYER_CALCULATOR_H

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

    void formatTimeStr(int index, double decimalHours);

public:
    PrayerCalculator(std::string name, double lat, double lon, int tz);

    void calculateQibla();
    void calculatePrayerTimes(int dayOfYear);
    void displayResults() const;
    void saveToFile() const;
};

#endif // PRAYER_CALCULATOR_H