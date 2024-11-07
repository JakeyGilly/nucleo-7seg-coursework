#include "7segment.h"

// function to display a character on the 7-segment display
// it converts the character to the 7-segment pattern and calls the display function
void SevenSegment::display_char(char c) {
    printf("displaying character %c\n", c);
    if (c >= 48 && c <= 57) {
        display(digits[c-48]);
    } else if (c >= 97 && c <= 122) {
        display(chars[c-97]);
    }
    ThisThread::sleep_for(_delay);
}

// function to display a 7-segment pattern on the display
void SevenSegment::display(int s) {
    _A = (s & 0b10000000) != 0;
    _B = (s & 0b01000000) != 0;
    _C = (s & 0b00100000) != 0;
    _D = (s & 0b00010000) != 0;
    _E = (s & 0b00001000) != 0;
    _F = (s & 0b00000100) != 0;
    _G = (s & 0b00000010) != 0;
}

// function to change the delay for printing each character
void SevenSegment::set_delay(Kernel::Clock::duration_u32 delay) {
    _delay = delay;
}