
void setupTemperature() {
}

void loopTemperature() {
  
  chk = DHT11.read(DHT11_PIN);
tempc = DHT11.temperature;
tempf = DHT11.temperature*(9/5)+32;
humidity = DHT11.humidity;

delay(6000);

}
