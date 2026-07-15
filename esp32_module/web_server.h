#pragma once

#include <WiFi.h>
#include <WebServer.h>
#include "movement_instruction_enum.h"
#include "web_page.h"

volatile MovementInstruction command_to_send = MovementInstruction::NONE;

const char* ssid = "ESP32";
const char* password = "12345678";

IPAddress local_ip(192, 168, 1, 1);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

WebServer server(80);



void request_handle_web_server() {
  server.handleClient();
}

void handle_root() {
  server.send(200, "text/html", web_page_content);
}

void handle_forward() {
  command_to_send = MovementInstruction::FORWARD;
  server.send(200);
}

void handle_backward() {
  command_to_send = MovementInstruction::BACKWARD;
  server.send(200);
}

void handle_turn_left() {
  command_to_send = MovementInstruction::TURN_LEFT;
  server.send(200);
}

void handle_turn_right() {
  command_to_send = MovementInstruction::TURN_RIGHT;
  server.send(200);
}

void handle_brake() {
  command_to_send = MovementInstruction::BRAKE;
  server.send(200);
}

void handle_NotFound() {
  server.send(404, "text/plain", "Not found");
}

void init_web_server() {

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
}