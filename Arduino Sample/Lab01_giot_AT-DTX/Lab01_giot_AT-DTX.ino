//#include <SoftwareSerial.h>
#include <CustomSoftwareSerial.h> //daniel modify

//SoftwareSerial LoRaUART(10, 11); //device TX connect to D10, device RX connect to D11
CustomSoftwareSerial LoRaUART(9, 10); //device TX connect to D10, device RX connect to D11
char frame[8];

void setup()
{
  Serial.begin(9600);
  while (!Serial)
  {
  }
  Serial.println("Serial Ready");
  //
  //LoRaUART.begin(9600);
  LoRaUART.begin(9600,CSERIAL_8E1);
  frame[0] = 0xA5;
  frame[1] = 0x03;
  frame[2] = 0x00; frame[3] = 0x00;
  frame[4] = 0x00; frame[5] = 0x01;
  frame[6] = 0x1D; frame[7] = 0x2C;
  //LoRaUART.print(frame);
}

void loop()
{
  Serial.println("run");
  LoRaUART.write(frame);
  delay(500);
  if (LoRaUART.available()) {
    Serial.write(LoRaUART.read());
  }
  delay(3000);
}
