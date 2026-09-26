  # Arduino DigitalOutputs

  ## 1. LED digitalOutputs and Colors.

  **Led's go from Left to right Blue, Yellow, Green, Red**

  pinMode(6, OUTPUT); //Blue
  pinMode(7, OUTPUT); //Yellow
  pinMode(9, OUTPUT); //Green
  pinMode(10, OUTPUT); //Red

  ## 2. Button DigitalOutputs.

  pinMode(2, OUTPUT); //Button 1, Blue Led
  pinMode(3, OUTPUT); //Button 2, Yellow Led
  pinMode(4, OUTPUT); //Button 3, Green Led
  pinMode(5, OUTPUT); //Button 4, Red Led

  ## 3. Segment screen Bits and 74HC595 shift register digitalOutputs.

  **74HC595 Shift register DigitalOutputs**

  LATCH_PIN = 8;
  DATA_PIN  = 11;
  CLOCK_PIN = 12;

  **Segments number bits from 0-9 and dot **

  B01111101,  // 0
  B00001100,  // 1
  B10110101,  // 2
  B10011101,  // 3
  B11001100,  // 4
  B11011001,  // 5
  B11111001,  // 6
  B00001101,  // 7
  B11111101,  // 8
  B11011101,  // 9
  B00000010,  // .

  **7-digit screen controls**

  LEFT_ON  = B11111101;
  RIGHT_ON = B11111011;
  BOTH_OFF = B11111111;