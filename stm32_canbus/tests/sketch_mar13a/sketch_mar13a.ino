#include "eXoCAN.h"

int id, fltIdx;
uint8_t rxbytes[16];
eXoCAN can;


void setup() {
  delay(3000);
  Serial.begin(115200);
  Serial.println(F("\n=== Arduino CAN BUS demo ==="));Serial.flush();
  
  // put your setup code here, to run once:
  can.begin(STD_ID_LEN, BR125K, PORTA_11_12_XCVR); // 11b IDs, 125k bit rate, no transceiver chip, portA pins 11,12
  //can.filterMask16Init(0, 0, 0x7ff, 0, 0);          // filter bank 0, filter 0: don't pass any, flt 1: pass all msgs
}

void loop() {
  // put your main code here, to run repeatedly:
  if (can.receive( id, fltIdx, rxbytes) > -1) {
    
    // poll for rx
    Serial.println(F("\nCAN message received !"));Serial.flush();
  }

  delay(250);
}
