#include <Manchester.h>
/*
  Manchester Transmitter example
  In this example transmitter will send one 16 bit number
  per transmission.
  Try different speeds using these constants, your maximum
  possible speed will depend on various factors like transmitter
  type, distance, microcontroller speed, ...
  MAN_300 0
  MAN_600 1
  MAN_1200 2
  MAN_2400 3
  MAN_4800 4
  MAN_9600 5
  MAN_19200 6
  MAN_38400 7
*/
  #define TX_PIN 0  //pin where your transmitter is connected
  uint8_t key_array[8] = {5,5,5,5,5,5,5,5};
  //uint16_t transmit_data1 = 0x04;
  //uint16_t transmit_data2 = 222;
  void setup() {
  man.setupTransmit(TX_PIN, MAN_1200);
  DDRB |= (1<<DDB1);
} 
  void loop() {
  PORTB |= (1<<PIN1);
  //man.workAround1MhzTinyCore();
  //man.transmit(transmit_data1);
  man.transmitArray(8,key_array);
  
  PORTB &= ~(1<<PIN1);
  delay(300);
}
