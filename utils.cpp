#include "utils.h"
#include "constants.h"

// Utility functions for degree/radian conversion
double degToRad(double deg) { return deg * PI / 180.0; }
double radToDeg(double rad) { return rad * 180.0 / PI; }