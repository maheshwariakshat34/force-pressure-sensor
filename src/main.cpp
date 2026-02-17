#include <Arduino.h>

// Variable to store analog sensor value
int value = 0;

void setup() {
    // Start serial communication at 9600 baud rate
    Serial.begin(9600);

    // Configure analog pin A0 as input
    pinMode(A0, INPUT);
}

void loop() {
    // Read analog value from sensor connected to A0
    value = analogRead(A0);

    // Print sensor value to Serial Monitor
    Serial.println(value);

    // Wait 500 milliseconds before next reading
    delay(500);
}
