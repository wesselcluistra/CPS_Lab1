// Lab 1.1 – Digital + Analog I/O
const int ledPin = 6;   // Built-in LED on D6
const int potPin = A1;  // Potentiometer connected to A1

void setup() {
  pinMode(ledPin, OUTPUT);  // LED as output
  Serial.begin(9600);       // Start serial monitor
}

void loop() {
  // Blink LED every 500 ms
  digitalWrite(ledPin, HIGH);
  delay(500);
  digitalWrite(ledPin, LOW);
  delay(500);

  // Read potentiometer and print raw value
  int rawValue = analogRead(potPin);  // 0–4095 for 12-bit ADC
  Serial.print("Analog value: ");
  Serial.println(rawValue);

  delay(1000); // Read once per second
}