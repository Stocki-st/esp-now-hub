#include <ETH.h>
#include <WebServer.h>

WebServer server(80);

void handleRoot() {
  server.send(200, "text/html", "<h1>hello</h1>");
}

void setup() {
  Serial.begin(115200);

  ETH.begin();
  
  while (ETH.connected() == 0) {
    delay(1000);
    Serial.println("Establishing ethernet connection...");
  }
  
  Serial.println("Ethernet connected!");
  Serial.print("IP: ");
  Serial.println(ETH.localIP());

  server.on("/", handleRoot);

  server.begin();
  Serial.println("HTTP-Server started");
}

void loop() {
  server.handleClient();
}
