#include <stdio.h>
#include <stdint.h>

/*
# CF**k

## Introduction
CF**k is a rewrite of [Brainf**k](https://en.wikipedia.org/wiki/BrainF) in C. Both are similar, but not the same.

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
*/

uint8_t bufferArray[256];
uint8_t bufferPointer = 0;
char instructions[256];

int doInstruction(char instruction, uint8_t index) {
  if (instruction == 0x3E) {
    bufferPointer++;
  } else if (instruction == 0x3C) {
    bufferPointer--;
  } else if (instruction == 0x2B) {
    bufferArray[bufferPointer]++;
  } else if (instruction == 0x2D) {
    bufferArray[bufferPointer]--;
  } else if (instruction == 0x2E) {
    printf("%d", bufferArray[bufferPointer]);
  } else if (instruction == 0x21) {
    printf("%c", bufferArray[bufferPointer]);
  } else if (instruction == 0x2C) {
    int readValue;
    scanf("%d", &readValue);
    bufferArray[bufferPointer] = readValue;
  } else if (instruction == 0x3B) {
    if (bufferArray[bufferPointer] > 0) {
      return index - 10;
    }
  }
  
  return index + 1;
}

int interpreterMode() {
  printf(">> ");
  
  fgets(instructions, sizeof(instructions), stdin);
  
  for (uint8_t i = 0; instructions[i] > 0; i = doInstruction(instructions[i], i)) {}
  
  printf("\n");
  interpreterMode();
  
  return 0;
}

int main(int argc, char *argv[]) {
  printf("CF**k Interpreter\n");
  interpreterMode();
  return 0;
}
