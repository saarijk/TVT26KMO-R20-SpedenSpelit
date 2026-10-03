#include "display.h"

// 74HC595 pins
const uint8_t LATCH_PIN = 8;
const uint8_t DATA_PIN  = 11;
const uint8_t CLOCK_PIN = 12;

// Segments for 0-9 and decimal dot
const uint8_t SEGMENTS[] =
{
  B01111101, // 0
  B00001100, // 1
  B10110101, // 2
  B10011101, // 3
  B11001100, // 4
  B11011001, // 5
  B11111001, // 6
  B00001101, // 7
  B11111101, // 8
  B11011101, // 9
  B00000010  // .
};

// Display selection
const uint8_t LEFT_ON  = B11111101;
const uint8_t RIGHT_ON = B11111011;
const uint8_t BOTH_OFF = B11111111;

// display score
volatile uint16_t currentScore = 0;

volatile uint8_t leftSegments = SEGMENTS[0];
volatile uint8_t rightSegments = SEGMENTS[0];

volatile bool leftDisplayActive = true;

unsigned long lastDisplayUpdate = 0;

const unsigned long DISPLAY_INTERVAL = 2;

// Send one byte manually to the 74HC595.
void sendByte(uint8_t data)
{
  for (int8_t bit = 7; bit >= 0; bit--)
  {
    digitalWrite(CLOCK_PIN, LOW);

    if (data & (1 << bit))
    {
      digitalWrite(DATA_PIN, HIGH);
    }
    else
    {
      digitalWrite(DATA_PIN, LOW);
    }

    digitalWrite(CLOCK_PIN, HIGH);
  }
}


// Send both 74HC595 bytes and update their outputs.
void sendToRegisters(uint8_t segmentData, uint8_t displayData)
{
  digitalWrite(LATCH_PIN, LOW);

  sendByte(displayData);
  sendByte(segmentData);

  digitalWrite(LATCH_PIN, HIGH);
}

// Display outputs
void initializeDisplay(void)
{
  pinMode(LATCH_PIN, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);

  digitalWrite(LATCH_PIN, LOW);
  digitalWrite(DATA_PIN, LOW);
  digitalWrite(CLOCK_PIN, LOW);

  // Turn both displays off initially.
  sendToRegisters(SEGMENTS[0], BOTH_OFF);
}

// Write one digit to the display register.
void writeByte(uint8_t number, bool last)
{
  if (number > 9)
  {
    number = 0;
  }

  digitalWrite(LATCH_PIN, LOW);

  sendByte(BOTH_OFF);
  sendByte(SEGMENTS[number]);

  if (last)
  {
    digitalWrite(LATCH_PIN, HIGH);
  }
}

// Set the two digits to be displayed.
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

// Set the score value.
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

  // if score over 100, show dot on left display
  if (score >= 100 && score < 200)
  {
    tensSegments |= SEGMENTS[10];
  }

  // if score over 200, show dots on bouth displays
  if (score >= 200)
  {
    tensSegments |= SEGMENTS[10];
    onesSegments |= SEGMENTS[10];
  }

  leftSegments = tensSegments;
  rightSegments = onesSegments;
}

void showResult(byte result)
{
  setScore(result);
}

// Update the score on display.
void updateDisplay(void)
{
  unsigned long currentTime = millis();

  if (currentTime - lastDisplayUpdate < DISPLAY_INTERVAL)
  {
    return;
  }

  lastDisplayUpdate = currentTime;

  if (leftDisplayActive)
  {
    // Turn both displays off before changing segment data.
    sendToRegisters(leftSegments, BOTH_OFF);

    // Enable left display.
    sendToRegisters(leftSegments, LEFT_ON);

    leftDisplayActive = false;
  }
  else
  {
    // Turn both displays off before changing segment data.
    sendToRegisters(rightSegments, BOTH_OFF);

    // Enable right display.
    sendToRegisters(rightSegments, RIGHT_ON);

    leftDisplayActive = true;
  }
}

