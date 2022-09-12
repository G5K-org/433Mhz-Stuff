#include <Manchester.h>

/*

Manchester Receiver example

  In this example receiver will receive one 16 bit number per transmittion

Try different speeds using this constants, your maximum possible speed will 

  depend on various factors like transmitter type, distance, microcontroller speed, ...

  MAN_300 0
  MAN_600 1
  MAN_1200 2
  MAN_2400 3
  MAN_4800 4
  MAN_9600 5
  MAN_19200 6
  MAN_38400 7

*/

#define RX_PIN 4

uint8_t receivedarray[8];


void setup() {
  
  Serial.begin(9600);
  man.setupReceive(RX_PIN, MAN_1200);
  man.beginReceiveArray(8,receivedarray);
}

void loop() {
 
   
  if (man.receiveComplete()) {
    uint16_t m = man.getMessage();
    for(int i = 0; i <= 7;i++)
    Serial.print(receivedarray[i]);
    Serial.println("");
    
    man.beginReceiveArray(8,receivedarray); //start listening for next message right after you retrieve the message
  }
}