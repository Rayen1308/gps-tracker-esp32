#include "gsm_handler.h"
#include "config.h"

HardwareSerial gsmSerial(1);

// Send an AT command and wait for a response
static void sendAT(const char* cmd, unsigned long waitMs = 1000) {
    gsmSerial.println(cmd);
    delay(waitMs);
    while (gsmSerial.available()) {
        Serial.write(gsmSerial.read());
    }
}

void initGSM() {
    gsmSerial.begin(GSM_BAUD, SERIAL_8N1, GSM_RX, GSM_TX);
    Serial.println("[GSM] Waiting for SIM800L to boot...");
    delay(5000);

    // Handshake
    sendAT("AT");

    // Disable echo
    sendAT("ATE0");

    // Check SIM card
    sendAT("AT+CPIN?");

    // Check network registration (1 = registered home, 5 = roaming)
    sendAT("AT+CREG?");

    // Set SMS to text mode
    sendAT("AT+CMGF=1");

    // Set character set
    sendAT("AT+CSCS=\"GSM\"");

    Serial.println("[GSM] Initialisation complete.");
}

void sendSMS(String message) {
    Serial.println("[GSM] Sending SMS...");

    gsmSerial.print("AT+CMGS=\"");
    gsmSerial.print(PHONE_NUMBER);
    gsmSerial.println("\"");
    delay(2000);

    gsmSerial.print(message);
    delay(500);

    gsmSerial.write(26);  // CTRL+Z — triggers send
    delay(5000);

    // Read response
    while (gsmSerial.available()) {
        Serial.write(gsmSerial.read());
    }

    Serial.println("[GSM] SMS sent.");
}
