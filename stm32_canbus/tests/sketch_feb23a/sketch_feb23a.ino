#include <SPI.h>
#include <mcp_can.h>

#define CAN_CS_Pin 10
MCP_CAN CAN(CAN_CS_Pin);

void setup() {
  Serial.begin(115200);
  while (!Serial);

  if (CAN_OK == CAN.begin(MCP_STM32, CAN_50KBPS, MCP_8MHZ)) {
    Serial.println("CAN Initialized!");
  } else {
    Serial.println("CAN Initialization failed!");
  }
}

void loop() {
  // Envoi d'un message CAN
  unsigned long int canId = 0x0F6;
  byte buf[] = {0x8E, 0x87, 0x32, 0xFA, 0x26, 0x8E, 0xBE, 0x86};
  byte len = sizeof(buf)/sizeof(buf[0]);
  CAN.sendMsgBuf(canId, 0, len, buf);
  
  Serial.println("Message sent!");
  
  delay(1000);
}
