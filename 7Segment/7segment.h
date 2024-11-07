#pragma once
#include "mbed.h"

class SevenSegment {
    // delay for printing each character
    Kernel::Clock::duration_u32 _delay;
    // Pins for seven segment display
    DigitalOut _A;
    DigitalOut _B;
    DigitalOut _C;
    DigitalOut _D;
    DigitalOut _E;
    DigitalOut _F;
    DigitalOut _G;
    // 7-segment display patterns for each character and digit
    int chars[26] = {250, 62, 26, 122, 158, 142, 188, 46, 136, 176, 174, 28, 170, 42, 58, 206, 230, 10, 180, 30, 56, 84, 86, 40, 118, 216};
    int digits[10] = {252, 96, 218, 242, 102, 182, 190, 224, 254, 246};
public:
    // constructor
    SevenSegment(Kernel::Clock::duration_u32 delay, PinName A, PinName B, PinName C, PinName D, PinName E, PinName F, PinName G): _A(A), _B(B), _C(C), _D(D), _E(E), _F(F), _G(G) {
        _delay = delay;
    }
    // function to display a character on the 7-segment display
    void display_char(char c);
    // function to display a 7-segment pattern on the display
    void display(int s);
    // function to change the delay for printing each character
    void set_delay(Kernel::Clock::duration_u32 delay);
};