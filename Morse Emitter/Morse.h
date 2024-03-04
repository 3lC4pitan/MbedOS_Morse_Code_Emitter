#ifndef MORSE_H
#define MORSE_H

#include "DigitalOut.h"
#include "mbed.h"
#include <string>

class Morse
{
public:
    Morse();
    Morse(DigitalOut led1, DigitalOut led2, DigitalOut led3);

    void newPageSignal();
    void startSignal();
    void charToMorse(char c);
    void setTimeInMillisec(int ms);

private:
    void blinkDot(int a);
    void blinkDash(int b);
    void timeUnit(int i);

private:
    DigitalOut _led1;
    DigitalOut _led2;
    DigitalOut _led3;
    int _timeInMillisec;
};

#endif // MORSE_H
