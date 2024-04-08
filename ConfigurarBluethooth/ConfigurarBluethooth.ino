/*
int led = 13;

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(38400);    //Es necesario a esta velocidad para entrar al modo de configuración del BlueThooth
  Serial.print("AT+NAME=Robbocock\r\n");
  Serial.print("AT+ROLe=0\r\n");  // = escalvo 1 Maestro
  Serial.print("AT+PSWD=7777\r\n");
  Serial.print("AT+RESET\r\n");    // Es neceario reiniciar el modula para que tome los valores

}

void loop() {
  digitalWrite(led, LOW);
  delay(5000);
  digitalWrite(led, HIGH);
  delay(5000);
}
*/

#include <SoftwareSerial.h>

//SoftwareSerial mySerial(2, 3); // RX, TX
SoftwareSerial mySerial(7, 8); // RX, TX

void setup() {
  // put your setup code here, to run once:
  mySerial.begin(9600);
  Serial.begin(9600);

  sendCommand("AT");
  sendCommand("AT+ROLE0");
  sendCommand("AT+UUID0xFF00");
  sendCommand("AT+CHAR0xFF01");
  sendCommand("AT+NAMERobbocock007");
  //sendCommand("AT+PSWD7777");

}

void sendCommand(const char * command){
  Serial.print("Command send :");
  Serial.println(command);
  mySerial.println(command);
  //wait some time
  delay(100);
  
  char reply[100];
  int i = 0;
  while (mySerial.available()) {
    reply[i] = mySerial.read();
    i += 1;
  }
  //end the string
  reply[i] = '\0';
  Serial.print(reply);
  Serial.println("Reply successful");
}

void loop() {
if (Serial.available())
  {
    char dato=Serial.read();
    Serial.print("Dato recibido: ");
    Serial.println(dato);
  }
}
