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
- Arduino/C++ implementation using modular hardware control files

## Hardware used

- Arduino board
- Multiple colored LEDs
- Input buttons
- 7-segment display or digital output display
- Supporting wiring and shift-register logic

## How it works

1. The game starts when the player triggers the start input.
2. A random LED sequence is generated and displayed.
3. The player must press matching buttons in the correct order.
4. Each successful round increases the score and speeds up the game.
5. If the player makes a wrong input or the queue exceeds the limit, the game ends.

## Project structure

- `SpedenSpelit.ino` – main program loop and setup, timer logic
- `SpedenSpelit.cpp` – main gameplay logic
- `buttons.*` – button input handling
- `leds.*` – LED control and visual effects
- `display.*` – score/output display functions
- `event_queue.*` – queue management for game events
- `MuistiSpeli.*` and related modules – supporting game logic and sequence handling for an extra game mode

## Getting started

1. Open the project in the Arduino IDE or a compatible C++/Arduino environment.
2. Connect the required hardware according to the project wiring.
3. Compile and upload the sketch to the Arduino board.
4. Start the game and follow the LED pattern.
