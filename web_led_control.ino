#include <WiFi.h>

const char* ssid = "CU_N8d6";
const char* password = "fx9xw4xm";
int ledPin = 5;
WiFiServer server(80);

void setup(){
  Serial.begin(115200);
  pinMode(ledPin,OUTPUT);
  WiFi.begin(ssid,password);

  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("Connected!");
  Serial.println(WiFi.localIP());
  server.begin();
  Serial.println("Web Server Started"); 
}

void loop(){
  WiFiClient client = server.available();

  if(client){
    Serial.println("New Client");
    String request = client.readStringUntil('\r');
    Serial.println(request);

    if (request.indexOf("/ON") >= 0) {
      digitalWrite(ledPin, HIGH);
    }

    if (request.indexOf("/OFF") >= 0) {
      digitalWrite(ledPin, LOW);
    }

    client.println("HTTP/1.1 200 OK");
    client.println("Content-type: text/html");
    client.println("Connection: close");
    client.println();

    client.println("<!DOCTYPE html>");
    client.println("<html>");
    client.println("<body>");

    client.println("<h1>Ning's ESP32 IoT Project</h1>");
    client.println("<p>Trinity College Dublin</p>");
    client.println("<p>Computer Engineering Student</p>");
    client.println("<p>Week 3 Day 2 - Web LED Control</p>");
    client.println("<hr>");
    client.println("<h2>LED Control Panel</h2>");
    client.println("<a href=\"/ON\">Turn ON LED</a>");
    client.println("<br><br>");
    client.println("<a href=\"/OFF\">Turn OFF LED</a>");
    client.println("<br><br>");
    client.println("<p>ESP32 Web Server Running</p>");
    client.println("</body>");
    client.println("</html>");
    delay(10);

    client.stop();
  }
}