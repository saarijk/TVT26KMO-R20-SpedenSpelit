
#include "display.h"
#include <avr/io.h>
#include <stdint.h>

#define LATCH_PIN  PB0
#define DATA_PIN   PB3
#define CLOCK_PIN  PB4


const uint8_t SEGMENTS[] =
{
  0b01111101,   // 0
  0b00001100,   // 1
  0b10110101,   // 2
  0b10011101,   // 3
  0b11001100,   // 4
  0b11011001,   // 5
  0b11111001,   // 6
  0b00001101,   // 7
  0b11111101,   // 8
  0b11011101,   // 9
  0b00000010    // decimal point
};

const uint8_t LEFT_ON  = 0b11111101;
const uint8_t RIGHT_ON = 0b11111011;
const uint8_t BOTH_OFF = 0b11111111;


volatile uint16_t currentScore = 0;

volatile uint8_t leftSegments  = SEGMENTS[0];
volatile uint8_t rightSegments = SEGMENTS[0];

volatile bool leftDisplayActive = true;

void sendByte(uint8_t data)
{
  for (int8_t bit = 7; bit >= 0; bit--)
  {
    // CLOCK LOW
    PORTB &= ~(1 << CLOCK_PIN);


    // Set DATA according to current bit
    if (data & (1 << bit))
    {
      PORTB |= (1 << DATA_PIN);
    }
    else
    {
      PORTB &= ~(1 << DATA_PIN);
    }


    // CLOCK HIGH
    // 74HC595 reads the bit here.
    PORTB |= (1 << CLOCK_PIN);
  }


  // CLOCK LOW
  PORTB &= ~(1 << CLOCK_PIN);
}


// ============================================================
// Send two bytes to the two 74HC595 circuits
// ============================================================

void sendToRegisters(uint8_t segmentData, uint8_t displayData)
{
  // LATCH LOW
  PORTB &= ~(1 << LATCH_PIN);


  // First byte goes through both registers.
  sendByte(displayData);
  sendByte(segmentData);


  // LATCH HIGH
  PORTB |= (1 << LATCH_PIN);
}


// ============================================================
// Initialize display
// ============================================================

void initializeDisplay(void)
{
  // D8, D11 and D12 as outputs

  DDRB |= (1 << LATCH_PIN);
  DDRB |= (1 << DATA_PIN);
  DDRB |= (1 << CLOCK_PIN);


  // Initial states

  PORTB &= ~(1 << LATCH_PIN);
  PORTB &= ~(1 << DATA_PIN);
  PORTB &= ~(1 << CLOCK_PIN);


  // Both displays off

  sendToRegisters(SEGMENTS[0], BOTH_OFF);


  leftDisplayActive = true;
}


// ============================================================
// Write one digit
// ============================================================

void writeByte(uint8_t number, bool last)
{
  if (number > 9)
  {
    number = 0;
  }


  // LATCH LOW
  PORTB &= ~(1 << LATCH_PIN);


  // Both displays off
  sendByte(BOTH_OFF);


  // Send segment data
  sendByte(SEGMENTS[number]);


  // LATCH HIGH
  if (last)
  {
    PORTB |= (1 << LATCH_PIN);
  }
}


// ============================================================
// Set two digits
// ============================================================

void writeHighAndLowNumber(uint8_t tens, uint8_t ones)
{
  if (tens > 9)
  {
    tens = 0;
  }

  if (ones > 9)
  {
    ones = 0;
  }


  leftSegments = SEGMENTS[tens];
  rightSegments = SEGMENTS[ones];
}


// ============================================================
// Set score
// ============================================================

void setScore(int score)
{
  if (score < 0)
  {
    score = 0;
  }


  currentScore = score;


  uint8_t displayValue = score % 100;

  uint8_t tens = displayValue / 10;
  uint8_t ones = displayValue % 10;


  uint8_t tensSegments = SEGMENTS[tens];
  uint8_t onesSegments = SEGMENTS[ones];


  // 100...199
  // Decimal point on left display

  if (score >= 100 && score < 200)
  {
    tensSegments |= SEGMENTS[10];
  }


  // 200 or more
  // Decimal point on both displays

  if (score >= 200)
  {
    tensSegments |= SEGMENTS[10];
    onesSegments |= SEGMENTS[10];
  }


  leftSegments = tensSegments;
  rightSegments = onesSegments;
}


// ============================================================
// Show result
// ============================================================

void showResult(byte result)
{
  setScore(result);
}

// Update display

void updateDisplay(void)
{
  static unsigned long lastDisplayUpdate = 0;

  unsigned long currentTime = millis();


  if (currentTime - lastDisplayUpdate < 2)
  {
    return;
  }


  lastDisplayUpdate = currentTime;


  if (leftDisplayActive)
  {
    // Turn both displays off
    sendToRegisters(leftSegments, BOTH_OFF);


    // Turn left display on
    sendToRegisters(leftSegments, LEFT_ON);


    leftDisplayActive = false;
  }
  else
  {
    // Turn both displays off
    sendToRegisters(rightSegments, BOTH_OFF);


    // Turn right display on
    sendToRegisters(rightSegments, RIGHT_ON);


    leftDisplayActive = true;
  }
}
  void clearDisplay(void)
{
    sendToRegisters(SEGMENTS[0], BOTH_OFF);
}

