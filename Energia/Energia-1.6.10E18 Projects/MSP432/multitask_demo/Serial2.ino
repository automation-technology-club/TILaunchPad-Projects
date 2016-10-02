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
  Serial.print(ping1);
  Serial.println(" cm");
 Serial.print("Ping 2: ");
  Serial.print(ping2);
  Serial.println(" cm");
  Serial.print("Ping 3: ");
  Serial.print(ping3);
  Serial.println(" cm");
  delay(500);
}
