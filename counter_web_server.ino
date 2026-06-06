#include <WiFi.h>
int counter = 0;
const char* ssid = "CU_N8d6";
const char* password = "fx9xw4xm";

WiFiServer server(80);

void setup() {

  Serial.begin(115200);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("Connected!");

  Serial.println(WiFi.localIP());

  server.begin();

  Serial.println("Web Server Started");
}

void loop() {

  WiFiClient client = server.available();

  if (client) {
    counter++;
    Serial.println("New Client");

    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("Connection: close");
    client.println();

    client.println("<!DOCTYPE html>");
    client.println("<html>");
    client.println("<body>");
    client.println("<h1>Count = ");
    client.println(counter);
    client.println("<h1>");
    client.println("<p>My first ESP32 website</p>");
    client.println("</body>");
    client.println("</html>");

    delay(10);
    client.stop();
}
}