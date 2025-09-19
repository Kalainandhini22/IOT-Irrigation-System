#include <Adafruit_Sensor.h>

#define BLYNK_TEMPLATE_ID "TMPL3XKCEX8KI"
#define BLYNK_TEMPLATE_NAME "irrigation"
#define BLYNK_AUTH_TOKEN "tpTgfD9KSPySMk8uoA6hxTxMqG77Zpc5"

#define BLYNK_PRINT Serial
 

 
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

 
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = BLYNK_AUTH_TOKEN;
 
// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "iotlab";
char pass[] = "password";
 
#define DHTPIN D2          // D3
 
// Uncomment whatever type you're using!
#define DHTTYPE DHT11     // DHT 11
//#define DHTTYPE DHT22   // DHT 22, AM2302, AM2321
//#define DHTTYPE DHT21   // DHT 21, AM2301
 
DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;
 WidgetLCD lcd(V1);
// This function sends Arduino's up time every second to Virtual Pin (5).
// In the app, Widget's reading frequency should be set to PUSH. This means
// that you define how often to send data to Blynk App.
void sendSensor()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit
 
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V5, t);
  Blynk.virtualWrite(V6, h);

  Serial.println("TEMPERATURE=");
  Serial.print(t);

  Serial.println("HUMIDITY=");
  Serial.print(h);
if(t > 34){
   // Blynk.email("shameer50@gmail.com", "Alert", "Temperature over 28C!");
    Blynk.logEvent("temp_alert","Temp above 34 degree");
       lcd.print(0, 0, "Over temp   ");  
    lcd.print(0, 1, " Alert             ");  
     delay(2000); 
     lcd.clear();
    
  }

}

 
//int pirValue; // Place to store read PIR Value
void setup()
{
  // Debug console
  Serial.begin(9600);
  pinMode(D8, OUTPUT);
  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 8442);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8442);
 
  dht.begin();
 
  // Setup a function to be called every second
  timer.setInterval(1000L, sendSensor);
}


 
void loop()
{
  Blynk.run();
  timer.run();
  
   lcd.print(0, 0, "Irregation soil  ");  
    lcd.print(0, 1, " Mointoring S/M             ");  
     delay(2000); 
     lcd.clear();
    vol();
   
}







void vol()
{
   unsigned int value = 0;

value = analogRead(A0);
 
  Serial.println(value);
   Blynk.virtualWrite(V7, value);

 digitalWrite(D4,HIGH);

    lcd.print(0, 0, "irregation soil           ");  
    lcd.print(0, 1, "Monitoring-IoT  ");  
     delay(2000); 
     lcd.clear();
     
        delay(2000); 
     lcd.clear();
    
    
       
 
}