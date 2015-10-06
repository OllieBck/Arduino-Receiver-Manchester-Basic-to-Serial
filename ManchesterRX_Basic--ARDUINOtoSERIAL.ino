
#include <Manchester.h>

/*

  Manchester Receiver example
  
  In this example receiver will receive one 16 bit number per transmittion

  try different speeds using this constants, your maximum possible speed will 
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
#define LED_PIN 7

uint8_t moo = 1;

void setup() {
  pinMode(LED_PIN, OUTPUT);  
  Serial.begin(9600);
  man.setupReceive(RX_PIN, MAN_1200);
  man.beginReceive();
}

void loop() {
  if (man.receiveComplete()) {
    uint16_t m = man.getMessage();
    man.beginReceive(); //start listening for next message right after you retrieve the message
    moo = ++moo % 2;
    digitalWrite(LED_PIN, HIGH);
    Serial.println(1);
    delay(1000);
    
  }

  else {
    digitalWrite(LED_PIN, LOW);
    Serial.println(0);
    delay(33);
  }
}


