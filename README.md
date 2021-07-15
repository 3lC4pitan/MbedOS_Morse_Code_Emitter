# Morse_Code_Emitter
University MBED Assignment: Simple Morse code emitter application project (STM32F746ZG)

Assignment Requirements:

Your application should be able to translate textual messages into Morse code that is emitted using the on-board LED (LED1 - the green led).
Your application should accept reconfiguration of the output pin (it should be able to operate with any DigitalOut capable pin, not only the LED1).
The textual messages are input using the PC keyboard, i.e. your application should establish a UART connection to the PC (use the USB UART connection).
The maximum length of a textual message shall be 254 ASCII characters.
The application shall be case insensitive.
The character set shall be comprised of letters, digits and punctuation symbols, as they are listed at: https://en.wikipedia.org/wiki/Morse_code in the table „Letters, numbers, punctuation, prosigns for Morse code and non-English variants”
The application shall allow changing the Morse code time unit.
The message will accept spaces between word, and the Morse code equivalent for a space shall be a medium gap, i.e. a 7 time units long pause
Each message will be started with a "Starting Signal" prosign.
Each message will be terminated with a "New Page Signal" prosign.
The Morse code protocol used is the one define in https://en.wikipedia.org/wiki/Morse_code.
Suggestion:

Organize your code in a class
Provide a function to change the duration of the basic time unit
Define a table/array to store all the corresponding codes for the accepted characters
