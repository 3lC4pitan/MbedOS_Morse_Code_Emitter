/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "Morse.h"

#define BUF_SIZE 256
#define WAIT_TIME_MS 500


BufferedSerial pc(USBTX, USBRX);

char buf[BUF_SIZE];
//char s[BUF_SIZE+1];
//int buf_count = 0;
//char message[BUF_SIZE+1];
char receivedDataBuffer[BUF_SIZE + 1];
bool new_message_received = false;

void on_serial_activity();

int main()
{
    //printf("This is the bare metal blinky example running on Mbed OS %d.%d.%d.\n", MBED_MAJOR_VERSION, MBED_MINOR_VERSION, MBED_PATCH_VERSION);

    //1st param= principale output LED,
    //2nd param= error translation LED,
    //3rd param= ----------- 


    Morse morse(LED2,LED1,LED3); 
    
    //param= time_unit in millisec
    morse.timeInMillisec(100); //100ms

    pc.sigio(&on_serial_activity);        
    while (true)
    {

            if (newMessageReceived)
                    {
                        int len = strlen(receivedDataBuffer);
                        printf("Received a length %d message: %s \n", len, receivedDataBuffer);
                        morse.startSignal();
            
                        for (int i = 0; i < len; i++)
                        {
                            morse.charToMorse(receivedDataBuffer[i]);
                        }
            
                        morse.newPageSignal();
                        newMessageReceived = false;
                    }
            
                    thread_sleep_for(WAIT_TIME_MS)
                        
}

char *strnchr(char *s, size_t count, char c)
{
    char *pos = s;
    while (pos - s < count && *pos != c) {
        pos++;
    }
    if (pos - s == count) {
        pos = nullptr;
    }

    return pos;
}

//UART connection

void on_serial_activity()
{
    if (pc.readable()) {
                                /** 
                                    int len = pc.read(buf + buf_count, BUF_SIZE - buf_count);
                                if (len > 0) {
                                    char *pos = strnchr(buf + buf_count, len, '\r');
                                    buf_count += len;
                                    if (pos) {
                                        strncpy(message, buf, pos - buf);
                                        message[pos-buf+1] = '\0';
                                        new_message_received = true;
                                        if (pos - buf + 1 < buf_count) {
                                            strncpy(buf, pos+1, buf_count - (pos - buf + 1));
                                            buf_count -= pos - buf + 1;
                                        }
                                        else {
                                            buf_count = 0;
                                        }
                                    }
                                }
                                **/
                        int len = pc.read(buf, BUF_SIZE);
                        if (len > 0)
                        {
                            char *pos = strnchr(buf, len, '\r');
                            if (pos)
                            {
                                strncpy(receivedDataBuffer, buf, pos - buf);
                                receivedDataBuffer[pos - buf] = '\0';
                                newMessageReceived = true;
                            }
                        }
    }
}
