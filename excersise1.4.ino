#include "sam.h"

#define LED_PIN   10   // PB10 → D4

void setup() {
    // Enable clock for PORT module
    PM->APBBMASK.reg |= PM_APBBMASK_PORT;
    
    // Start with LED as OUTPUT
    PORT->Group[1].DIRSET.reg = (1 << LED_PIN);
}

void loop() {
    // Toggle direction bit: if output → input, if input → output
    PORT->Group[1].DIRTGL.reg = (1 << LED_PIN);
    
    // Optional: blink when output
    if ((PORT->Group[1].DIR.reg & (1 << LED_PIN)) != 0) {
        // Pin is output, turn LED on/off
        PORT->Group[1].OUTTGL.reg = (1 << LED_PIN);
    }
    
    delay(1000); // 1 second delay
}