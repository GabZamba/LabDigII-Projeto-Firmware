/**
 * @file Fliperama-ESP8266.ino
 * 
 * @author Pedro Henrique Martins de Santi <pedrodesanti@usp.br>
 * 
 * @brief Main ESP8266 code
 * 
 * @date 2022-03-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <SoftwareSerial.h>

#include "config.h"

static String cube_distance;
static String distance;
static String angle;

String user = "grupo2-bancadaA3";
String passwd = "digi#@2A3";

const char* ssid = "WiFi - 40 reais/hora";
const char* password = "SenhaSecreta";
const char* mqtt_server = "labdigi.wiseful.com.br";

WiFiClient espClient;
PubSubClient client(espClient);

unsigned long lastMsg = 0;
#define MSG_BUFFER_SIZE (50)
char msg[MSG_BUFFER_SIZE];
int value = 0;

// SoftwareSerial mySerial = SoftwareSerial(RX_PIN, TX_PIN);

void setup_wifi() {
    delay(10);
    // We start by connecting to a WiFi network
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    randomSeed(micros());

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}

void reconnect() {
    // Loop until we're reconnected
    while (!client.connected()) {
        
        Serial.print("Attempting MQTT connection...");
        
        // Create a random client ID
        String clientId = user;
        clientId += String(random(0xffff), HEX);
        
        // Attempt to connect
        if (client.connect(clientId.c_str(), user.c_str(), passwd.c_str())) {
        
        Serial.println("connected");
        // Once connected, publish an announcement...
        client.publish((user+"/homehello").c_str(), "hello world");

        // client.subscribe((user+"/ledhome").c_str());

        // client.subscribe((user+"/S0").c_str());
        // client.subscribe((user+"/S1").c_str());
        // client.subscribe((user+"/S2").c_str());
        // client.subscribe((user+"/S3").c_str());
        
        } else {
        
        Serial.print("failed, rc=");
        Serial.print(client.state());
        Serial.println(" try again in 5 seconds");
        
        // Wait 5 seconds before retrying
        delay(5000);
        
        }
    }
}

void callback(char* topic, byte* payload, unsigned int length) {
    Serial.print("Message arrived [");
    Serial.print(topic);
    Serial.print("] ");
    for (int i = 0; i < length; i++) {
        Serial.print((char)payload[i]);
    }
    Serial.println();

    // Checks every led topic, update state if it matches
    // for (int i = 0; i <= 3; i++) {
    //     if (strcmp(topic, leds[i].get_topic()) == 0) {
    //         if ((char)payload[0] == '1') {
    //             leds[i].set_state(true);
    //         }
    //         else {
    //             leds[i].set_state(false);
    //         }
    //     }
    // }


void setup() {


    Serial.begin(115200, SERIAL_7E2);   // inicia a comunicação serial com o computador a 115200 bauds                                      

    setup_wifi();
    client.setServer(mqtt_server, 80);
    client.setCallback(callback);
}

void loop() {
    // Checks if client is connected
    if (!client.connected()) {
        reconnect();
    }
    client.loop();

    // Serial.println(mySerial.available());
    if (Serial.available()>0) {

        cube_distance = Serial.readStringUntil('.');
        distance = Serial.readStringUntil(',');
        angle = Serial.readStringUntil(';');

        Serial.println(cube_distance);
        Serial.println(distance);
        Serial.println(angle);

        client.publish((user+"/cube_distance").c_str(), cube_distance.c_str());
        client.publish((user+"/distance").c_str(), distance.c_str());
        client.publish((user+"/angle").c_str(), angle.c_str());
    }

    unsigned long now = millis();
    if (now - lastMsg > 2000) {
        lastMsg = now;
        ++value;
        snprintf (msg, MSG_BUFFER_SIZE, "hello world #%ld", value);
        Serial.print("Publish message: ");
        Serial.println(msg);
        client.publish((user+"/homehello").c_str(), msg);
    }

    delay(100);
}
