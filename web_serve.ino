#include <WiFi.h>

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

    Serial.println("New Client");

    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println();

    client.println("<h1>Hello from ESP32!</h1>");

    client.stop();
  }
}
