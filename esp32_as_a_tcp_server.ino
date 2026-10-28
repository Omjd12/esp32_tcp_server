#include <WiFi.h>

const char* ssid = "narzo 50A";
const char* password = "123456789";

  WiFiServer server(1234);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.println(WiFi.status());
    delay(500);
  }

  server.begin();

  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:
  WiFiClient client = server.available();

  if (client) {
    while (client.connected()) {
      client.println("hello from esp32");
      Serial.println("client live");
      delay(1000);
    }
  }
  else{
    Serial.println("client disconnected");
    delay(10000);
  }
}
