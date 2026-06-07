# Qibla-direction-and-prayer-timing-app
An API-free lightweight C++ console application designed to calculate the Qibla direction and estimate daily Islamic prayer times (Fajr, Dhuhr, Asr, Maghrib, and Isha). This tool serves Muslims, travelers, and developers needing a quick, offline utility to determine accurate prayer schedules based on geographical coordinates, UTC timezone offsets, and the current day of the year. It solves the problem of relying on internet connectivity for prayer times by using localized astronomical calculations, displaying the results in the terminal, and automatically saving them to a text file.

Built to showcase core OOP concepts—Abstraction, Encapsulation, Inheritance, Polymorphism (Static/Dynamic)—and File Handling. 

## Prerequisites

To compile and run this project, you will need the following:

* A C++ compiler supporting C++11 or higher (e.g., GCC, Clang, or MSVC).
* A command-line terminal or integrated development environment (IDE).
* *(Optional)* Git, if you are cloning the repository.

## Installation Instructions

Open your terminal and run the following commands to get the project and compile it locally:

# 1. Clone the repository or navigate to your extracted zip folder
git clone https://github.com/yourusername/qibla-prayer-calculator.git
cd "qibla-prayer-calculator"

# 2. Compile the source code using g++
g++ main.cpp PrayerCalculator.cpp utils.cpp -o prayer_calculator

Once compiled, you can run the executable directly from your terminal. The program will prompt you for your location data.

To run the program:

# On Linux or macOS:
./prayer_calculator

# On Windows:
.\prayer_calculator.exe

##Example Interactive Flow:

```text
=== Simple Qibla & Prayer Times Calculator ===
Enter Country/City Name: Lahore
Enter Latitude (e.g., 24.86 for Karachi): 31.52
Enter Longitude (e.g., 67.00 for Karachi): 74.35
Enter UTC Timezone Offset (e.g., +5): 5
Enter Day of the Year (1 to 365): 158

=========================================
Location: Lahore
Coordinates: 31.52 N, 74.35 E
Qibla Direction: 260.67° from True North

--- Today's Prayer Times ---
Fajr      : 03:52
Dhuhr     : 12:02
Asr       : 16:47
Maghrib   : 19:17
Isha      : 20:47
=========================================

Success: Schedule saved to 'prayer_schedule.txt'.

```

## License

This project is licensed under the **MIT License**. For more details, please refer to the `LICENSE` file in the root directory.
