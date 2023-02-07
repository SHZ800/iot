#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "iphone";
const char* password = "123Abc:&";
String whatwefound ="off";

void setup(){
  Serial.begin(9600); //SO WE CAN PRINT ON THIS PC
  WiFi.begin(ssid, password); //THIS CONNECTS TO HOTSPOT
while (WiFi.status() != WL_CONNECTED) {
  delay(500);
  WiFi.begin(ssid, password);
  Serial.println("still trying to connect to wifi");
               }
  Serial.println("Now connected to wifi");
  Serial.println(WiFi.localIP()); //JUST TO PRINT YOUR IP ADRESS
}

void loop(){
  String thedegree = checktemp();
  if (AyomidePleaseCheck("http://127.0.0.1:80/homefan?temp="+thedegree)=="on"){
    digitalWrite(D7,HIGH);

    
  }
  else{
    digitalWrite(D7,LOW);
  }
}

String AyomidePleaseCheck(String weblink){
  WiFiClient wifiClient;
  HTTPClient http;
  http.begin(wifiClient,weblink);
  if (http.GET()>0){
    String wefound = http.getString();
    
  }
  else{
    Serial.println("maga, your link dey whine me. ERROR");
  }
  http.end();
  return whatwefound;
}
String checktemp(){
  return ("25");
}
