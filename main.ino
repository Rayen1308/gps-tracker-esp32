#include "config.h"
#include "gps_handler.h"
#include "gsm_handler.h"

String locationLink;

void setup() {
    Serial.begin(115200);
    Serial.println("=== ESP32 GPS Tracker ===");

    initGPS();
    initGSM();

    Serial.println("[Main] Attempting to get GPS fix...");

    if (getGPSLocation(locationLink)) {
        sendSMS(locationLink);
        Serial.println("[Main] Location sent successfully.");
    } else {
        Serial.println("[Main] Could not acquire GPS fix. No SMS sent.");
        sendSMS("GPS Tracker: Failed to acquire location fix.");
    }
}

void loop() {
    // Wait for the defined interval, then get a new location and send again
    delay(UPDATE_INTERVAL);

    Serial.println("[Main] Interval elapsed — getting new location...");

    if (getGPSLocation(locationLink)) {
        sendSMS(locationLink);
        Serial.println("[Main] Location update sent.");
    } else {
        Serial.println("[Main] GPS fix failed on update cycle.");
    }
}
