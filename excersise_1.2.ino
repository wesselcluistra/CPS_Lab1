// Exercise 1.2 – WiFi Network Scanner
#include <WiFiNINA.h>   // Include official WiFi library for MKR1010

void setup() {
  Serial.begin(9600);   // Start serial communication at 9600 baud
  while (!Serial);      // Wait until Serial Monitor is open

  // Check if WiFi module is detected
  if (WiFi.status() == WL_NO_MODULE) {
    Serial.println("WiFi module not found!");
    while (true); // Stop here if no module
  }

  Serial.println("WiFi module found!");
}

void loop() {
  Serial.println("Scanning available networks...");

  // Scan for Wi-Fi networks
  int numNetworks = WiFi.scanNetworks();

  // Print information for each network
  for (int i = 0; i < numNetworks; i++) {
    Serial.print("Network: ");
    Serial.print(WiFi.SSID(i));          // Network name
    Serial.print(" | Signal: ");
    Serial.print(WiFi.RSSI(i));          // Signal strength (dBm)
    Serial.print(" dBm | Encryption: ");
    Serial.println(WiFi.encryptionType(i)); // Encryption type
  }

  Serial.print("Total networks found: ");
  Serial.println(numNetworks);
  Serial.println("-------------------------");

  delay(30000); // Wait 30 seconds before rescanning
}