#include "mbed.h"

// set the pins for the 7-segment display to output
DigitalOut seg_a(D2);
DigitalOut seg_b(D3);
DigitalOut seg_c(D4);
DigitalOut seg_d(D5);
DigitalOut seg_e(D6);
DigitalOut seg_f(D7);
DigitalOut seg_g(D8);

// 7-segment display patterns for each character and digit
int chars[26] = {250, 62, 26, 122, 158, 142, 188, 46, 136, 176, 174, 28, 170, 42, 58, 206, 230, 10, 180, 30, 56, 84, 86, 40, 118, 216};
int digits[10] = {252, 96, 218, 242, 102, 182, 190, 224, 254, 246};

// function to display a 7-segment pattern on the display
void display(int s) {
    seg_a = (s & 0b10000000) != 0;
    seg_b = (s & 0b01000000) != 0;
    seg_c = (s & 0b00100000) != 0;
    seg_d = (s & 0b00010000) != 0;
    seg_e = (s & 0b00001000) != 0;
    seg_f = (s & 0b00000100) != 0;
    seg_g = (s & 0b00000010) != 0;
}

// function to display a character on the 7-segment display
// it converts the character to the 7-segment pattern and calls the display function
void display_char(char c) {
    printf("displaying character %c\n", c);
    if (c >= 48 && c <= 57) {
        display(digits[c-48]);
    } else if (c >= 97 && c <= 122) {
        display(chars[c-97]);
    }
    ThisThread::sleep_for(500ms);
}

int main() {
    // set the buttons to input with pull-up resistors
    DigitalIn btn1(D9, PullUp);
    DigitalIn btn2(D10, PullUp);

    // set the first and last name as character arrays
    char fname[6];
    char lname[6];

    // get the first and last name as input from the user
    printf("Enter the first name: ");
    scanf("%5s", fname);
    printf("Enter the second name: ");
    scanf("%5s", lname);

    int count1 = 0; 
    int count2 = 0;
    
    while (true) {
        // check if button 1 is pressed
        if (!btn1) {
            // for each character in the first name, display it on the 7-segment display
            for (int i = 0; i < 5; i++) {
                display_char(fname[i]);
            }
            printf("first name has been displayed %d times\n", ++count1);
        // check if button 2 is pressed
        } else if (!btn2) {
            // for each character in the last name, display it on the 7-segment display
            for (int i = 0; i < 5; i++) {
                display_char(lname[i]);
            }
            printf("last name has been displayed %d times\n", ++count2);
        }
    }
}