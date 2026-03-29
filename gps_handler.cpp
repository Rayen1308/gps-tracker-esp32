#include "gps_handler.h"
#include "config.h"

HardwareSerial gpsSerial(2);
TinyGPSPlus gps;

void initGPS() {
    gpsSerial.begin(GPS_BAUD, SERIAL_8N1, GPS_RX, GPS_TX);
    Serial.println("[GPS] Serial initialised.");
}

bool getGPSLocation(String &locationLink) {
    Serial.println("[GPS] Waiting for fix...");
    unsigned long start = millis();

    while (millis() - start < GPS_TIMEOUT) {
        while (gpsSerial.available()) {
            gps.encode(gpsSerial.read());
        }

        if (gps.location.isValid() && gps.location.age() < 2000) {
            double lat = gps.location.lat();
            double lng = gps.location.lng();

            locationLink = "Location update:\nhttps://maps.google.com/?q=" +
                           String(lat, 6) + "," +
                           String(lng, 6);

            Serial.println("[GPS] Fix acquired: " + locationLink);
            return true;
        }
    }

    Serial.println("[GPS] Timed out — no fix within timeout window.");
    return false;
}
