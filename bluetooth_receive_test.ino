String receivedText = "";

void setup() {
  Serial1.begin(9600); //rx1 and tx1 = pins 0 and 1 on Teensy LC
  delay(200);
}

void loop() {
   if (Serial.available()) Serial1.write(Serial.read());
  while(Serial1.available() > 0) { // While there is more to be read, keep reading.
    receivedText += (char)Serial1.read();
    delay(10);  
  }

  if(receivedText != "") Serial.println(receivedText);
  receivedText = "";
}
