#include "mbed.h"
#include "7Segment/7segment.h"

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

    SevenSegment sevsegment(1000ms, D2, D3, D4, D5, D6, D7, D8);
    
    while (true) {
        // check if button 1 is pressed
        if (!btn1) {
            // for each character in the first name, display it on the 7-segment display
            for (int i = 0; i < 5; i++) {
                sevsegment.display_char(fname[i]);
            }
            printf("first name has been displayed %d times\n", ++count1);
        // check if button 2 is pressed
        } else if (!btn2) {
            // for each character in the last name, display it on the 7-segment display
            for (int i = 0; i < 5; i++) {
                sevsegment.display_char(lname[i]);
            }
            printf("last name has been displayed %d times\n", ++count2);
        }
    }
}