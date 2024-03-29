# RTOS Morse Code Emitter

## University MBED Assignment

**Project:** Morse code emitter application project using NUCLEO-F746ZG(STM32F746ZG)

![STM32F746ZG]([https://www.st.com/bin/ecommerce/api/image.PF262631.en.feature-description-include-personalized-no-cpn-large.jpg](https://os.mbed.com/media/cache/platforms/Nucleo144_perf_logo_1024_rDHDP6L.jpg.250x250_q85.jpg))



### Assignment Requirements:

1. Translate textual messages into Morse code using the on-board LED (LED1 - the green LED).
2. Accept reconfiguration of the output pin to operate with any DigitalOut capable pin, not limited to LED1.
3. Input textual messages using the PC keyboard via UART connection (USB UART connection).
4. Maximum length of a textual message: 254 ASCII characters.
5. Case-insensitive application.
6. Character set includes letters, digits, and punctuation symbols as listed in [Wikipedia - Morse Code](https://en.wikipedia.org/wiki/Morse_code) under "Letters, numbers, punctuation, prosigns for Morse code and non-English variants".
7. Allow changing the Morse code time unit.
8. Spaces between words in messages; Morse code equivalent for a space is a medium gap, i.e., a 7-time unit long pause.
9. Start each message with a "Starting Signal" prosign.
10. Terminate each message with a "New Page Signal" prosign.
11. Use the Morse code protocol defined in [Wikipedia - Morse Code](https://en.wikipedia.org/wiki/Morse_code).

### Suggestions:

- Organize code in a class structure.
- Provide a function to change the duration of the basic time unit.
- Define a table/array to store all corresponding codes for accepted characters.
