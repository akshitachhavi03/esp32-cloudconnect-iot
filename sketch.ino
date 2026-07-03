#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "Wokwi-GUEST";
const char* password = "";

void setup() {
  Serial.begin(115200);

  Serial.println("Connecting to WiFi...");

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi Connected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  HTTPClient http;

  http.begin("http://worldtimeapi.org/api/ip");

  int httpResponseCode = http.GET();

  Serial.print("HTTP Response Code: ");
  Serial.println(httpResponseCode);

  http.end();
}

void loop() {
}