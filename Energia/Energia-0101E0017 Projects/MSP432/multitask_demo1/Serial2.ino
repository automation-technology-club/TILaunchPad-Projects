void setup2()
{
  //Serial.begin(9600);
  delay(100);
Serial.println(message);
}

void loop2()
{
  Serial.print("Current Count: ");
  Serial.println(count);
  Serial.print("Ping 1: ");
  if (ping1 == -1) {
        Serial.println("Out of Range"); } else {
                  Serial.print(ping1);
                  Serial.println(" cm"); }
                  
 Serial.print("Ping 2: ");
 if (ping2 == -1) { 
       Serial.println("Out of Range"); } else {
           Serial.print(ping2);
           Serial.println(" cm"); }
           
  Serial.print("Ping 3: ");
  if (ping3 == -1) {
          Serial.println("Out of Range"); } else {
            Serial.print(ping3);
            Serial.println(" cm"); }
  
  switch (chk) {
        case DHTLIB_OK: 
            Serial.println("OK"); 
            break;
        case DHTLIB_ERROR_CHECKSUM: 
            Serial.println("Checksum error"); 
            break;
        case DHTLIB_ERROR_TIMEOUT: 
            Serial.println("Time out error"); 
            break;
        default: 
            Serial.println("Unknown error"); 
            break;
    }
    
    Serial.print("Humidity (%): ");
    Serial.println(humidity);
    Serial.print("Temperature (C): ");
    Serial.println(tempc);
    Serial.print("Temperature (F): ");
    Serial.println(tempf);
    
  
  delay(500);
}
