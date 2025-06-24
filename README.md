# CF**k

## Introduction
CF\*\*k is a rewrite of [Brainf\*\*k](https://en.wikipedia.org/wiki/BrainF) in C. Both are similar, but not the same.

## Features
There is a buffer with 256 uint8_t objects. A pointer exists that points to a cell in this buffer.

### Instructions
There are several instructions:

- Point Right (>); moves pointer to the right.
- Point Left (<); moves pointer to the left.
- Increment (+); increments the value of the cell at the pointer.
- Decrement (-); decrements the value of the cell at the pointer.
- Output Value; there are two types:
  - Output Numerical Value** (.); outputs the value as a number.
  - Output ASCII Character* (!); outputs the value as an ASCII character.
- Backmover (;); moves back 10 instructions if cell value at the pointer is greater than 0.

## Examples

This program outputs Hello World:
`++++++++++>+++++++<-;>++!>+++<--   ;>-------!+++++++!!+++!>++++++>+++++++<-;>++!------------!<<++++++++!--------!+++!------!--------!>>+!`
