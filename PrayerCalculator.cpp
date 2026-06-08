#include "PrayerCalculator.h"
#include "Constants.h"
#include "Utils.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>

// Constructor
PrayerCalculator::PrayerCalculator(std::string name, double lat, double lon, int tz)
    : locationName(name), latitude(lat), longitude(lon), timezone(tz), qiblaAngle(0.0) {}

// Helper to turn decimal hours into a "12:30" string
void PrayerCalculator::formatTimeStr(int index, double decimalHours) {
    int hours = static_cast<int>(decimalHours) % 24;
    int minutes = static_cast<int>((decimalHours - static_cast<int>(decimalHours)) * 60);
    
    std::string hStr = (hours < 10 ? "0" : "") + std::to_string(hours);
    std::string mStr = (minutes < 10 ? "0" : "") + std::to_string(minutes);
    prayerTimes[index] = hStr + ":" + mStr;
}

// Calculate Qibla Direction
void PrayerCalculator::calculateQibla() {
    double latRad = degToRad(latitude);
    double lonRad = degToRad(longitude);
    double mLatRad = degToRad(MECCA_LAT);
    double mLonRad = degToRad(MECCA_LON);
    double dLon = mLonRad - lonRad;

    double y = std::sin(dLon);
    double x = std::cos(latRad) * std::tan(mLatRad) - std::sin(latRad) * std::cos(dLon);
    
    qiblaAngle = radToDeg(std::atan2(y, x));
    if (qiblaAngle < 0) qiblaAngle += 360.0;
}

// Calculate Prayer Times
void PrayerCalculator::calculatePrayerTimes(int dayOfYear) {
    double baseNoon = 12.0 - (longitude / 15.0) + timezone; 
    double dayLengthFactor = std::sin((dayOfYear - 80) * 2 * PI / 365.0) * 1.5;

    formatTimeStr(0, baseNoon - 7.5 - (dayLengthFactor * 0.5)); // Fajr
    formatTimeStr(1, baseNoon);                                 // Dhuhr
    formatTimeStr(2, baseNoon + 4.5 + (dayLengthFactor * 0.2)); // Asr
    formatTimeStr(3, baseNoon + 6.0 + dayLengthFactor);         // Maghrib
    formatTimeStr(4, baseNoon + 7.5 + dayLengthFactor);         // Isha
}

// Display results
void PrayerCalculator::displayResults() const {
    std::cout << "\n=========================================" << std::endl;
    std::cout << "Location: " << locationName << std::endl;
    std::cout << "Coordinates: " << latitude << " N, " << longitude << " E" << std::endl;
    std::cout << "Qibla Direction: " << std::fixed << std::setprecision(2) 
              << qiblaAngle << "° from True North" << std::endl;
    
    std::cout << "\n--- Today's Prayer Times ---" << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cout << std::left << std::setw(10) << prayerNames[i] << ": " << prayerTimes[i] << std::endl;
    }
    std::cout << "=========================================" << std::endl;
}

// Save results to file
void PrayerCalculator::saveToFile() const {
    std::ofstream outFile("prayer_schedule.txt");
    if (outFile.is_open()) {
        outFile << "Location: " << locationName << "\n";
        outFile << "Qibla Angle: " << std::fixed << std::setprecision(2) << qiblaAngle << "°\n";
        outFile << "\n--- Daily Prayer Times ---\n";
        for (int i = 0; i < 5; ++i) {
            outFile << prayerNames[i] << ": " << prayerTimes[i] << "\n";
        }
        outFile.close();
        std::cout << "\nSuccess: Schedule saved to 'prayer_schedule.txt'." << std::endl;
    } else {
        std::cerr << "\nError: Unable to open file for writing." << std::endl;
    }
}