/**
 * @file main.cpp
 * @brief Reads an analog force/pressure sensor on A0 and prints raw ADC values to Serial.
 *
 * This sketch demonstrates a minimal example for reading an analog sensor connected
 * to pin A0 and streaming the raw ADC values to the Serial Monitor every 500 ms.
 *
 * @note The ADC resolution on many AVR-based Arduinos is 10-bit (range 0-1023). If
 *       you use a different board (ESP32, SAMD, etc.), check the ADC resolution and
 *       Vref and adjust scaling accordingly.
 *
 * @version 1.0
 * @date 2026-02-17
 * @auhor Akshat Lakhotiya
 */

#include <Arduino.h>

/**
 * @brief Latest analog reading from the sensor (raw ADC units).
 *
 * Range: 0 (0V) to 1023 (Vref) on 10-bit ADC devices. Update documentation if using
 * higher/lower resolution ADCs.
 */
int value = 0;

/**
 * @brief Arduino setup function.
 *
 * Initializes the Serial peripheral used to print sensor readings and configures
 * the analog pin A0 as an input. This function is executed once after the board
 * boots or the sketch is uploaded.
 *
 * @note Serial.begin(9600) sets the baud rate for the Serial Monitor. Match the
 *       Serial Monitor's baud setting to view output correctly.
 */
void setup() {
    // Start serial communication at 9600 baud rate
    Serial.begin(9600);

    // Configure analog pin A0 as input
    pinMode(A0, INPUT);
}

/**
 * @brief Arduino main loop.
 *
 * Repeatedly reads the analog value from A0, stores it in the global `value`,
 * and prints the measured value to the Serial Monitor. The loop pauses 500 ms
 * between readings.
 *
 * @note This implementation uses a blocking delay. For non-blocking timing,
 *       consider using millis() to schedule periodic reads.
 */
void loop() {
    // Read analog value from sensor connected to A0
    value = analogRead(A0);

    // Print sensor value to Serial Monitor
    Serial.println(value);

    // Wait 500 milliseconds before next reading
    delay(500);
}
