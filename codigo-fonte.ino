#include <WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>

// Definições de pinos
#define LED_BUILTIN 2   // LED onboard

// Configurações Wi-Fi
const char* ssid = "Carlos HC";
const char* password = "969141242";

// Configurações MQTT
const char* mqtt_server = "192.168.15.93";
const int mqtt_port = 1883;
const char* mqtt_user = "lince";
const char* mqtt_password = "linceglobal";
const char* mqtt_topic = "sensor/control";

// Identificadores
const char* ID = "561187";
const char* moduleID = "SM_ESP32";

// Objetos
WiFiClient espClient;
PubSubClient client(espClient);
JsonDocument doc;
char buffer[256];

// Variáveis
float temperaturaLocal;
float umidadeLocal;

void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Conectando a ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi conectado");
  Serial.println("IP: ");
  Serial.println(WiFi.localIP());
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Conectando ao MQTT...");
    if (client.connect(moduleID, mqtt_user, mqtt_password)) {
      Serial.println("conectado");
    } else {
      Serial.print("falhou, rc=");
      Serial.print(client.state());
      Serial.println(" tentando novamente em 5 segundos");
      delay(5000);
    }
  }
}

// Simulação de temperatura (entre 20°C e 38°C)
float simularTemperatura() {
  return random(2000, 3800) / 100.0;
}

// Simulação de umidade (entre 30% e 90%)
float simularUmidade() {
  return random(3000, 9000) / 100.0;
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);  
  Serial.begin(115200);
  
  setup_wifi();
  
  client.setServer(mqtt_server, mqtt_port);
  }

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  // Leitura dos sensores
  temperaturaLocal = simularTemperatura();
  umidadeLocal = simularUmidade();

  // Limpa o documento JSON
  doc.clear();

  // Monta o JSON
  doc["ID"] = ID;
  doc["Sensor"] = moduleID;
  doc["IP"] = WiFi.localIP().toString();
  doc["MAC"] = WiFi.macAddress();

  if (!isnan(temperaturaLocal) && !isnan(umidadeLocal)) {
    doc["Temperatura"] = temperaturaLocal;
    doc["Umidade"] = umidadeLocal;
  } else {
    doc["Temperatura"] = "Erro";
    doc["Umidade"] = "Erro";
  }

  // Serializa o JSON
  serializeJson(doc, buffer);
  
  // Publica no MQTT
  client.publish(mqtt_topic, buffer);
  
  // Feedback visual
  digitalWrite(LED_BUILTIN, HIGH);
  delay(100);
  digitalWrite(LED_BUILTIN, LOW);

  Serial.println(buffer);
  delay(3000);
} 