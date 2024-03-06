#include "Morse.h"
#include <ctime> //may not be used


//constructors

Morse::Morse() : _led1(LED1), _led2(LED2), _led3(LED3), _timeInMillisec(100)
{
}

Morse::Morse(DigitalOut led1, DigitalOut led2, DigitalOut led3) : _led1(led1), _led2(led2), _led3(led3), _timeInMillisec(100)
{
}


void Morse::setTimeInMillisec(int ms)
{
    _timeInMillisec = ms;
}
 
//blink dot function
void Morse::blinkDot(int a)
{
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            _led2 = !_led2;
            timeUnit(1);
        }
    }
}


//blink dash function
void Morse::blinkDash(int b)
{
    for (int i = 0; i < b; i++)
    {
        _led2 = !_led2;
        timeUnit(2);
        _led2 = !_led2;
        timeUnit(1);
    }
}


//new page signal: blinking all leds simultaneously x 2
void Morse::newPageSignal()
{
    for (int j = 0; j < 4; j++)
    {
        _led1 = !_led1;
        _led2 = !_led2;
        _led3 = !_led3;
        timeUnit(1);
    }
}


//start signal: blinking leds 1>2>3>2>1
void Morse::startSignal()
{
    DigitalOut led[] = {_led1, _led2, _led3};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            led[i] = !led[i];
            timeUnit(1);
        }
    }
    for (int i = 1; i >= 0; i--)
    {
        for (int j = 0; j < 2; j++)
        {
            led[i] = !led[i];
            timeUnit(1);
        }
    }
    timeUnit(3);
}

//time unit function
void Morse::timeUnit(int i)
{

     /** 
      *dot 1 = 1u
      *dash 111 = 3u 
      *dot_dash 0 = 1u
      *short gap (_letters) 000 = 3u
      *medium gap (_words) 0000000 = 7u
      **/

    switch (i)
    {
    case 1:
        thread_sleep_for(_timeInMillisec);
        break;

    case 2:
        thread_sleep_for(_timeInMillisec * 3);
        break;

    case 3:
        thread_sleep_for(_timeInMillisec * 7);
        break;

    default:
        break;
    }
}


//translate chars to Morse code function

void Morse::charToMorse(char c){
    
    switch (c) {

        //letters
        case 'a':
        case 'A':  // .-
        blinkDot(1);
        blinkDash(1);
            break;
        
        case 'b':
        case 'B':  //-...
        blinkDash(1);
        blinkDot(3);
            break;
        
        case 'c':
        case 'C':  // -.-.
        blinkDash(1);
        blinkDot(1);
        blinkDash(1);
        blinkDot(1);
            break;
        
        case 'd':
        case 'D':  // -..
        blinkDash(1);
        blinkDot(2);
            break;
        
        case 'e': 
        case 'E':  // .
        blinkDot(1);
            break;
        
        case 'f':
        case 'F':  // ..-.
        blinkDot(2);
        blinkDash(1);
        blinkDot(1);
            break;
        
        case 'g':
        case 'G':  // --.
        blinkDash(2);
        blinkDot(1);
            break;
        
        case 'h':
        case 'H':  // ....
        blinkDot(4);
            break;
        
        case 'i':
        case 'I':  // ..
        blinkDot(2);
            break;

        case 'j': 
        case 'J':  // .---
        blinkDot(1);
        blinkDash(3);
            break;
        
        case 'k': 
        case 'K':  // -.-
        blinkDash(1);
        blinkDot(1);
        blinkDash(1);
            break;
        
        case 'l': 
        case 'L':  // .-..
        blinkDot(1);
        blinkDash(1);
        blinkDot(2);
            break;
        
        case 'm': 
        case 'M':  // --
        blinkDash(2);
            break;
        
        case 'n':
        case 'N':  // -.
        blinkDash(1);
        blinkDot(1);
            break;
        
        case 'o':
        case 'O':  // ---
        blinkDash(3);
            break;
        
        case 'p':
        case 'P':  // .--.
        blinkDot(1);
        blinkDash(2);
        blinkDot(1);
            break;
        
        case 'q': 
        case 'Q':  // --.-
        blinkDash(2);
        blinkDot(1);
        blinkDash(1);
            break;
        
        case 'r':
        case 'R':  // .-.
        blinkDot(1);
        blinkDash(1);
        blinkDot(1);
            break;
        
        case 's': 
        case 'S':  // ...
        blinkDot(3);
            break;
        
        case 't':
        case 'T':  // -
        blinkDash(1);
            break;
        
        case 'u': 
        case 'U':  // ..-
        blinkDot(2);
        blinkDash(1);
            break;
        
        case 'v':
        case 'V':  // ...-
        blinkDot(3);
        blinkDash(1);
            break;
        
        case 'w': 
        case 'W':  // .--
        blinkDot(1);
        blinkDash(2);
            break;
        
        case 'x': 
        case 'X':  // -..-
        blinkDash(1);
        blinkDot(2);
        blinkDash(1);
            break;
        
        case 'y': 
        case 'Y':  // -.--
        blinkDash(1);
        blinkDot(1);
        blinkDash(2);
            break;
        
        case 'z': 
        case 'Z':  // --..
        blinkDash(2);
        blinkDot(2);
            break;

        //Numbers

        case '1' : // .----
        blinkDot(1);
        blinkDash(4);
            break;
        
        case '2' :  // ..---
        blinkDot(2);
        blinkDash(3);
            break;
        
        case '3' :  // ...--
        blinkDot(3);
        blinkDash(2);
            break;
        
        case '4' :  // ....-
        blinkDot(4);
        blinkDash(1);
            break;
        
        case '5' :  // .....
        blinkDot(5);
            break;
        
        case '6' :  // -....
        blinkDash(1);
        blinkDot(4);
            break;
        
        case '7' :  // --...
        blinkDash(2);
        blinkDot(3);
            break;
        
        case '8' :  // ---..
        blinkDash(3);
        blinkDot(2);
            break;
        
        case '9' :  // ----.
        blinkDash(4);
        blinkDot(1);
            break;
        
        case '0' :  // -----
        blinkDash(5);
            break;
            
        /* Punctuation */

        case '.':  // .-.-.-
            blinkDot(1);
            blinkDash(1);
            blinkDot(1);
            blinkDash(1);
            blinkDot(1);
            blinkDash(1);
            break;
        case ',':  // --..--
            blinkDash(2);
            blinkDot(2);
            blinkDash(2);
            break;         
        case '?':   // ..--..
            blinkDot(2);
            blinkDash(2);
            blinkDot(2);
            break; 
        case '\'':  // .----.
            blinkDot(1);
            blinkDash(4);
            blinkDot(1);
            break; 
        case '!':   // -.-.--
            blinkDash(1);
            blinkDot(1);
            blinkDash(1);
            blinkDot(1);
            blinkDash(2);
            break;
        case '/':   // -..-.
            blinkDash(1);
            blinkDot(2);
            blinkDash(1);
            blinkDot(1);
            break; 
        case '(':   // -.--.
            blinkDash(1);
            blinkDot(1);
            blinkDash(2);
            blinkDot(1);
            break;
        case ')':   // -.--.-
            blinkDash(1);
            blinkDot(1);
            blinkDash(2);
            blinkDot(1);
            blinkDash(1);
            break;
        case '&':   // .-...
            blinkDot(1);
            blinkDash(1);
            blinkDot(3);
            break;
        case ':':   // ---...
            blinkDash(3);
            blinkDot(3);
            break; 
        case ';':   // -.-.-.
            blinkDash(1);
            blinkDot(1);
            blinkDash(1);
            blinkDot(1);
            blinkDash(1);
            blinkDot(1);
            break;
        case '=':   // -...-
            blinkDash(1);
            blinkDot(3);
            blinkDash(1);
            break;
        case '+':   // -.-.-
            blinkDash(1);
            blinkDot(1);
            blinkDash(1);
            blinkDot(1);
            blinkDash(1); 
            break;
        case '-':   // -....-
            blinkDash(1);
            blinkDot(4);
            blinkDash(1);
            break; 
        case '_':   // ..--.-
            blinkDot(2);
            blinkDash(2);
            blinkDot(1);
            blinkDash(1);
            break;
        case '"':   // .-..-.
            blinkDot(1);
            blinkDash(1);
            blinkDot(2);
            blinkDash(1);
            blinkDot(1);
            break;
        case '$':   // ...-..-
            blinkDot(3);
            blinkDash(1);
            blinkDot(2);
            blinkDash(1);
            break;
        case '@':   // .--.-.
            blinkDot(1);
            blinkDash(2);
            blinkDot(1);
            blinkDash(1);
            blinkDot(1);
            break;
        case ' ':  //....
            blinkDot(4);
            break;
        default : 
            _led3 = !_led3;
            timeUnit(2);            
            _led3 = !_led3;
            timeUnit(2);
            break;

    /* Prosigns */
/*      SYM_EOW,    // ...-.-
        SYM_ERR,    // ........
        SYM_ITX,    // -.-
        SYM_STS,    // -.-.-
        SYM_NPS,    // .-.-.
        SYM_USTOOD, // ...-.
        SYM_WAIT,   // .-...

        SYM_INVALID,
        SYM_COUNT
*/
        }
}

