#ifndef GSM_HANDLER_H
#define GSM_HANDLER_H

#include <Arduino.h>

// Initialise the GSM serial connection and wait for the module to be ready
void initGSM();

// Send an SMS with the given message to the number defined in config.h
void sendSMS(String message);

#endif
