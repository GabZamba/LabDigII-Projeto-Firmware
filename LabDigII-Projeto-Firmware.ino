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

#define DEBUG 0

static String cube_distance;
static String distance;
static String angle;

static String data;

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
        
        //Serial.print("Attempting MQTT connection...");
        
        // Create a random client ID
        String clientId = user;
        clientId += String(random(0xffff), HEX);
        
        // Attempt to connect
        if (client.connect(clientId.c_str(), user.c_str(), passwd.c_str())) {
        
        //Serial.println("connected");
        // Once connected, publish an announcement...
        client.publish((user+"/homehello").c_str(), "hello world");

        client.subscribe((user+"/virtual_cube").c_str());
        
        } else {
        
        //Serial.print("failed, rc=");
        //Serial.print(client.state());
        //Serial.println(" try again in 5 seconds");
        
        // Wait 5 seconds before retrying
        delay(5000);
        
        }
    }
}

void callback(char* topic, byte* payload, unsigned int length) {

    #if DEBUG == 1
    Serial.print("Message arrived [");
    Serial.print(topic);
    Serial.print("] ");
    for (int i = 0; i < length; i++) {
        Serial.print((char)payload[i]);
    }
    Serial.println();
    #endif

    // Allocate the correct amount of memory for the payload copy
    byte* p = (byte*)malloc(length);
    // Copy the payload to the new buffer
    memcpy(p,payload,length);

    if (strcmp(topic, (user+"/virtual_cube").c_str()) == 0) {

        int value = String((char*)p).toInt();

        value = map(value, 0, 100, 9, 440);

        String value_str = String(value);

        while(value_str.length() < 3) {
            value_str = "0" + value_str;
        }

        Serial.write((value_str + "#").c_str());
    }

    // Free the memory
    free(p);
}


void setup() {

    Serial.begin(9600, SERIAL_7E2);   // inicia a comunicação serial com o computador a 115200 bauds                                      

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

    if (Serial.available()) {

        // cube_distance = Serial.readStringUntil('.');
        // angle = Serial.readStringUntil(',');
        // distance = Serial.readStringUntil(';');

        //Serial.println(cube_distance);
        //Serial.println(distance);
        //Serial.println(angle);

        // client.publish((user+"/cube_distance").c_str(), cube_distance.c_str());
        // client.publish((user+"/angle").c_str(), angle.c_str());
        // client.publish((user+"/distance").c_str(), distance.c_str());

        data = Serial.readStringUntil(';');
        // Serial.println(data);

        if (data.length() == 11) {
            client.publish((user+"/all").c_str(), data.c_str());
        }
    }

    unsigned long now = millis();
    if (now - lastMsg > 2000) {
        lastMsg = now;
        ++value;
        snprintf (msg, MSG_BUFFER_SIZE, "hello world #%ld", value);
        //Serial.print("Publish message: ");
        //Serial.println(msg);
        client.publish((user+"/homehello").c_str(), msg);
    }

    //delay(100);
}
