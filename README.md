# SpedenSpelit - TVT26KMO, R20

A fast-paced Arduino-based reaction and memory game where players must follow a sequence of illuminated LEDs and respond by pressing the correct buttons as quickly as possible. The game increases in speed over time, challenging the player to maintain accuracy and reaction time under pressure.

## Project description

SpedenSpelit is a simple embedded game project developed for an Arduino hardware setup with LEDs, buttons, and a display. The objective of the game is to track the pattern shown by the lights, reproduce it by using the corresponding input buttons, and survive as long as possible while the difficulty steadily rises.

This project demonstrates how embedded systems can be used to create interactive and engaging gameplay using hardware input/output, timing logic, randomization, and real-time event handling.

## Features

- LED-based game sequence
- Button input for user interaction
- Score tracking and increasing difficulty
- Timer-based gameplay progression
- End-of-game logic and restart flow
- A dice game mode with queued rolls and automatic tallying after 15 rolls
- Arduino/C++ implementation using modular hardware control files

## Hardware used

- Arduino board
- Multiple colored LEDs
- Input buttons
- 7-segment display or digital output display
- Supporting wiring and shift-register logic

## SpedenSpelit game mode

1. The game starts when the player triggers the start input.
2. A random LED sequence is generated and displayed.
3. The player must press matching buttons in the correct order.
4. Each button press increases the score and every ten correct presses speeds up the game.
5. If the player makes a wrong input or the queue exceeds the limit, the game ends.

## Dice game mode

- Press button 1 (index 0) to enter the dice game.
- Press button 2 (index 1) to roll a six-sided die. The LEDs show the roll number in binary.
- Press button 3 (index 2) to display the sum and empty the roll queue.
- After 15 rolls, the sum is displayed and the queue is emptied automatically.
- Press button 4 (index 3) to switch to the SpedenSpelit game.

## Project structure

The project currently contains two game modes: the original SpedenSpelit reaction game and a dice game. The files are organized by responsibility:

- `SpedenSpelit.ino` / `SpedenSpelit.h` – Arduino setup and main loop, game-mode selection, timer configuration and control, and timer interrupt declaration
- `SpedenSpelit.cpp` – gameplay loop, input checking, scoring, difficulty progression, and game-over handling
- `diceGame.cpp` / `diceGame.h` – dice game mode; button 1 (index 0) starts it, button 2 rolls, button 3 totals and clears the rolls, and button 4 switches to SpedenSpelit. The total is also shown and cleared automatically after 15 rolls.
- `buttons.cpp` / `buttons.h` – button initialization and input handling
- `leds.cpp` / `leds.h` – LED initialization, control, and visual effects
- `display.cpp` / `display.h` – score and other output display functions
- `randomNumber.cpp` / `randomNumber.h` – random LED selection
- `eventQueue.cpp` / `eventQueue.h` – circular FIFO queue for game events
- `ledSequence.cpp` / `ledSequence.h` – LED-specific helpers that use the event queue
- `OuputsAndSegments.md` – notes about outputs and display segments


## Getting started

1. Open the project in the Arduino IDE or a compatible C++/Arduino environment.
2. Connect the required hardware according to the project wiring.
3. Compile and upload the sketch to the Arduino board.
4. Start the game and follow the LED pattern.
