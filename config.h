#ifndef CONFIG_H
#define CONFIG_H

// --- GPS Module (NEO-6M) ---
#define GPS_RX 16
#define GPS_TX 17
#define GPS_BAUD 9600

// --- GSM Module (SIM800L) ---
#define GSM_RX 26
#define GSM_TX 27
#define GSM_BAUD 9600

// --- Target phone number (international format) ---
#define PHONE_NUMBER "+4915781146580"

// --- GPS fix timeout in milliseconds (60 seconds) ---
#define GPS_TIMEOUT 60000

// --- Delay between location updates in milliseconds (5 minutes) ---
#define UPDATE_INTERVAL 300000

#endif
