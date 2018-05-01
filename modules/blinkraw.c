/* main.c
 * A simple blinky program for ATtiny85
 * internal LED: MISO (PB1)
 *
 * via http://electronut.in/getting-started-with-attiny85-avr-programming/
 * better: https://blog.ithasu.org/2014/12/blinking-a-digispark-without-arduino-ide/
 * see https://de.wikibooks.org/wiki/C-Programmierung_mit_AVR-GCC/_IO-Ports
 */

#include <avr/io.h>
#include <util/delay.h>

// Digispark Internal LED
#define PIN_LED     PB1
#define DELAY_MS    500

int main(void) {
  // Init LED pin as output
  DDRB |= (1 << PIN_LED);
  // Light up LED
  PORTB |= (1 << PIN_LED);

  // Blink !
  for (;;) {
    PORTB ^= (1 << PIN_LED);
    _delay_ms(DELAY_MS);
  }

  return 0;
}
