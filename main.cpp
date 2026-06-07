#include <iostream>
#include <string>
#include "PrayerCalculator.h"

int main() {
    std::cout << "=== Simple Qibla & Prayer Times Calculator ===" << std::endl;

    std::string name;
    double lat, lon;
    int tz, day;

    std::cout << "Enter Country/City Name: ";
    std::getline(std::cin, name);
    std::cout << "Enter Latitude (e.g., 24.86 for Karachi): ";
    std::cin >> lat;
    std::cout << "Enter Longitude (e.g., 67.00 for Karachi): ";
    std::cin >> lon;
    std::cout << "Enter UTC Timezone Offset (e.g., +5): ";
    std::cin >> tz;
    std::cout << "Enter Day of the Year (1 to 365): ";
    std::cin >> day;

    // Create a simple, normal stack object (No pointers, no 'new', no memory leaks!)
    PrayerCalculator calc(name, lat, lon, tz);

    // Run the calculations
    calc.calculateQibla();
    calc.calculatePrayerTimes(day);

    // Show output and save
    calc.displayResults();
    calc.saveToFile();

    return 0;
}