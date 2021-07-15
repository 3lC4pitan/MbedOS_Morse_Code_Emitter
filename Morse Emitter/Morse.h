#ifndef MORSE_H
#define MORSE_H


#include "DigitalOut.h"
#include "mbed.h"

//#define WAIT_TIME_MS 100 

class Morse {
  public:
  //methods
  
  Morse();
  Morse(DigitalOut led1, DigitalOut led2, DigitalOut led3);

    void newPageSig();    //new page signal
    void startSig(); //start signal
    void char2Morse(char c);   //translate char to morse
    int timeInMillisec(int ms);

private:
    void blinkDot(int a);
    void blinkDash(int b);
    void timeUnit(int i);  //time unit
  
private:
  //attributs
  
  DigitalOut _led1; //LED1, LED2, LED3
  DigitalOut _led2; //LED1, LED2, LED3
  DigitalOut _led3; //LED1, LED2, LED3  
  
};

#endif // MORSE_H