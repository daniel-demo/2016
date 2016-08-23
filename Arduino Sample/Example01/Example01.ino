#include <SoftwareSerial.h>

/*
set arduino pin 10 = RX & pin 11 = TX for LoRa module
*/
SoftwareSerial LoRaUART(10, 11);

/*
# 土壤濕度
# Example code for the moisture sensor
# Connect the sensor to the A0(Analog 0) pin on the Arduino board
# the sensor value description:
# 0~300 dry soil
# 300~700 humid soil
# 700~950 in water
*/
int moistureValue = analogRead(A0);

/*
buffer for sending data
*/
char send_buf[64];

void setup()
{
  //init serial for serial monitor
  Serial.begin(9600);
  while(!Serial)
  {
  }
  Serial.println("\r\nArduino LoRa Sample");

#if 1
  //init serial for LoRa module
  LoRaUART.begin(9600);
  LoRaUART.println("AT");
  while(!LoRaUART.available())
  {
  }
  Serial.println("LoRa Ready");
#endif
}

void loop()
{
  moistureValue = analogRead(A0);
  Serial.print("Moisture Value = 0x");
  Serial.println(moistureValue, HEX);
  byte data_h = (byte)((moistureValue>>8) & 0x00FF);
  byte data_l = (byte)(moistureValue & 0x00FF);
  Serial.print("data_h = 0x");
  Serial.println(data_h, HEX);
  Serial.print("data_l = 0x");
  Serial.println(data_l, HEX);
#if 1
  //LoRaUART.println("AT+DTX=6,\"abcdef\"");
  sprintf(send_buf, "AT+DTX=4,%02X%02X", data_h, data_l);
  LoRaUART.println(send_buf);
  Serial.println("send data:");
  Serial.println(send_buf);
  Serial.println("");
#endif
  delay(10000);
}

