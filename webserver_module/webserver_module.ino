#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <Wire.h>

#include "web_page.h"


const char* ssid = "ESP8266";
const char* password = "12345678";

IPAddress local_ip(192, 168, 1, 1);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

ESP8266WebServer server(80);

enum COMMAND : uint8_t {
  FORWARD = 0x00,
  BACKWARD = 0x01,
  TURN_RIGHT = 0x02,
  TURN_LEFT = 0x03,
  BRAKE = 0x04,
  NONE = 0x05
};

volatile COMMAND command_to_send = COMMAND::NONE;

void setup() {
  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  delay(100);

  server.on("/", handle_root);
  server.on("/forward", handle_forward);
  server.on("/backward", handle_backward);
  server.on("/turn_left", handle_turn_left);
  server.on("/turn_right", handle_turn_right);
  server.on("/brake", handle_brake);
  server.onNotFound(handle_NotFound);

  server.begin();

  Wire.begin(0xFE);
  Wire.onRequest(I2C_onRequest);
}

void loop() {
  server.handleClient();
}

void I2C_onRequest() {
  Wire.write(command_to_send);
  command_to_send = COMMAND::NONE;
}

void handle_root() {
  server.send(200, "text/html", web_page_content);
}

void handle_forward() {
  command_to_send = COMMAND::FORWARD;
}

void handle_backward() {
  command_to_send = COMMAND::BACKWARD;
}

void handle_turn_left() {
  command_to_send = COMMAND::TURN_LEFT;
}

void handle_turn_right() {
  command_to_send = COMMAND::TURN_RIGHT;
}

void handle_brake() {
  command_to_send = COMMAND::BRAKE;
}

void handle_NotFound() {
  server.send(404, "text/plain", "Not found");
}