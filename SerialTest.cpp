/*

Credit to Tom Archer and Rick Leinecker
for the Serial.h header class

Credit to "Coding Badly"
From the Arduino.cc forums for parts of this code

*/


#define STRICT
#include <tchar.h>
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include "Serial.h"

int main() {
     CSerial serial;
     LONG lLastError = ERROR_SUCCESS;      
     int i=0;

     // Attempt to open the serial port (COM3)
     lLastError = serial.Open(_T("COM3"),0,0,false);

     if (lLastError != ERROR_SUCCESS) printf("*Unable to open COM port\n");
     else printf("*COM port open\n");

     // Setup the serial port (9600,8N1, which is the default setting)
     lLastError = serial.Setup(CSerial::EBaud9600,CSerial::EData8,CSerial::EParNone,CSerial::EStop1);

     if (lLastError != ERROR_SUCCESS) printf("*Unable to set COM port settings\n");
     printf("*COM port settings set\n");

     lLastError = serial.SetMask(CSerial::EEventBreak |
                                               CSerial::EEventCTS   |
                                               CSerial::EEventDSR   |
                                               CSerial::EEventError |
                                               CSerial::EEventRing  |
                                               CSerial::EEventRLSD  |
                                               CSerial::EEventRecv);

     if (lLastError != ERROR_SUCCESS) printf("*Unable to set COM port event mask\n");
     else printf("*COM port event mask set\n");

     // Use 'non-blocking' reads, because we don't know how many bytes
     // will be received. This is normally the most convenient mode
     // (and also the default mode for reading data).
     lLastError = serial.SetupReadTimeouts(CSerial::EReadTimeoutNonblocking);

     if (lLastError != ERROR_SUCCESS) printf("*Unable to set COM-port read timeout\n");
     else printf("*COM port read timeout set\n");

     bool fContinue = true;

     // Read serial port
     do {

           // Wait for an event
           lLastError = serial.WaitEvent();
           if (lLastError != ERROR_SUCCESS) printf("*Unable to wait for a COM-port event\n");

           // Save event
           const CSerial::EEvent eEvent = serial.GetEventType();

           // Handle break event
           if (eEvent & CSerial::EEventBreak) printf("*BREAK received\n");

           // Handle CTS event
           if (eEvent & CSerial::EEventCTS) printf("*Clear to send %s\n", serial.GetCTS()?"on":"off");

           // Handle DSR event
           if (eEvent & CSerial::EEventDSR) printf("*Data set ready %s\n", serial.GetDSR()?"on":"off");

           // Handle error event
           if (eEvent & CSerial::EEventError)
           {
                 printf("*ERROR: ");
                 switch (serial.GetError())
                 {
                       case CSerial::EErrorBreak:            printf("Break condition");                  break;
                       case CSerial::EErrorFrame:            printf("Framing error");                  break;
                       case CSerial::EErrorIOE:            printf("IO device error");                  break;
                       case CSerial::EErrorMode:            printf("Unsupported mode");                  break;
                       case CSerial::EErrorOverrun:      printf("Buffer overrun");                  break;
                       case CSerial::EErrorRxOver:            printf("Input buffer overflow");      break;
                       case CSerial::EErrorParity:            printf("Input parity error");            break;
                       case CSerial::EErrorTxFull:            printf("Output buffer full");            break;
                       default:                                    printf("Unknown");                              break;
                 }
                 printf("\n");
           }

           // Handle ring event
           if (eEvent & CSerial::EEventRing) printf("*RING\n");

           // Handle RLSD/CD event
           if (eEvent & CSerial::EEventRLSD) printf("*RLSD/CD %s\n", serial.GetRLSD()?"on":"off");

           // Handle data receive event
           if (eEvent & CSerial::EEventRecv)
           {
                 // Read data, until there is nothing left
                 DWORD dwBytesRead = 0;
                 //char szBuffer[101];
                 char szBuffer[1];

                 do
                 {
                       // Read data from the COM-port
                       lLastError = serial.Read(szBuffer,sizeof(szBuffer),&dwBytesRead);
                       //lLastError = serial.Read(szBuffer,sizeof(szBuffer)-1,&dwBytesRead);
                       if (lLastError != ERROR_SUCCESS) printf("*Unable to read from COM-port\n");

                       if (dwBytesRead > 0)
                       {
                             // Finalize the data, so it is a valid string
                             //szBuffer[dwBytesRead] = '\0';

                             // Display the data
                             //printf("%s", szBuffer);
                             printf("%02x", szBuffer[0]);

                             // Check if EOF (CTRL+'[') has been specified
                             //if (strchr(szBuffer,EOF_Char)) fContinue = false;

                       }
                 }
               while (dwBytesRead == sizeof(szBuffer));
                 //while (dwBytesRead == sizeof(szBuffer)-1);

           }

           i++;
     }
     while(i<10);
     //while (fContinue);

     // Close the port again
   serial.Close();

     // Wait
     scanf("%d", &i);

     return 0;
}