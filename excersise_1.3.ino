// MKR1010 Robust Basic Calculator

float num1, num2, result;
char op;
String input;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // wachten tot de Serial poort verbonden is
  }
  Serial.println("Basic MKR1010 Calculator");
  Serial.println("Voer een operatie in: number operator number");
  Serial.println("Voorbeeld: 8 * 5");
}

void loop() {
  Serial.print("\nEnter calculation: ");

  // Wacht tot er iets in de Serial Monitor wordt getypt
  while (Serial.available() == 0) {
    ; // niets doen
  }

  input = Serial.readStringUntil('\n'); // Lees tot newline
  input.trim(); // verwijdert spaties en \r of \n

  // Vind posities van eerste en laatste spatie
  int firstSpace = input.indexOf(' ');
  int lastSpace = input.lastIndexOf(' ');

  if (firstSpace > 0 && lastSpace > firstSpace) {
    // Haal nummers en operator uit de string
    num1 = input.substring(0, firstSpace).toFloat();
    op = input.charAt(firstSpace + 1);
    num2 = input.substring(lastSpace + 1).toFloat();

    // Berekening uitvoeren
    switch (op) {
      case '+':
        result = num1 + num2;
        break;
      case '-':
        result = num1 - num2;
        break;
      case '*':
        result = num1 * num2;
        break;
      case '/':
        if (num2 != 0) {
          result = num1 / num2;
        } else {
          Serial.println("Error: Division by zero!");
          return; // skip printing result
        }
        break;
      default:
        Serial.println("Error: Unknown operator!");
        return; // skip printing result
    }
    Serial.print("Result: ");
    Serial.println(result);
  } else {
    Serial.println("Invalid input! Gebruik: number operator number");
  }

  delay(100); // korte pauze
}