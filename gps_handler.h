#ifndef GPS_HANDLER_H
#define GPS_HANDLER_H

#include <TinyGPSPlus.h>

// Initialise the GPS serial connection
void initGPS();

// Attempt to get a valid GPS fix within the timeout defined in config.h
// Returns true and fills locationLink if successful, false if timed out
bool getGPSLocation(String &locationLink);

#endif
