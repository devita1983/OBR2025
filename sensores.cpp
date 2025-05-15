#include "config.h"
#include "sensores.h"
#include <Arduino.h>

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

/************************************
 * Sensores de Linha e Ultrassônico *
 ************************************/

void configurarSensores() {
  // Configura sensores de linha
  pinMode(SENSOR_ESQUERDO, INPUT);
  pinMode(SENSOR_DIREITO, INPUT);
  
  // Configura sensor ultrassônico
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

int lerSensorEsquerdo() {
  return analogRead(SENSOR_ESQUERDO);
}

int lerSensorDireito() {
  return analogRead(SENSOR_DIREITO);
}

unsigned int lerDistanciaObstaculo() {
  return sonar.ping_cm();
}

/*********************
 * Sensor de Cor *
 *********************/

void configurarSensorCor() {
  pinMode(SENSOR_COR_S0, OUTPUT);
  pinMode(SENSOR_COR_S1, OUTPUT);
  pinMode(SENSOR_COR_S2, OUTPUT);
  pinMode(SENSOR_COR_S3, OUTPUT);
  pinMode(SENSOR_COR_OUT, INPUT);
  
  // Configuração para escala de 20%
  digitalWrite(SENSOR_COR_S0, HIGH);
  digitalWrite(SENSOR_COR_S1, LOW);
}

RGB lerCor() {
  RGB cor;
  
  // Ler componente vermelho (filtro R)
  digitalWrite(SENSOR_COR_S2, LOW);
  digitalWrite(SENSOR_COR_S3, LOW);
  cor.r = pulseIn(SENSOR_COR_OUT, LOW);
  
  // Ler componente verde (filtro G)
  digitalWrite(SENSOR_COR_S2, HIGH);
  digitalWrite(SENSOR_COR_S3, HIGH);
  cor.g = pulseIn(SENSOR_COR_OUT, LOW);
  
  // Ler componente azul (filtro B)
  digitalWrite(SENSOR_COR_S2, LOW);
  digitalWrite(SENSOR_COR_S3, HIGH);
  cor.b = pulseIn(SENSOR_COR_OUT, LOW);
  
  return cor;
}

bool detectarVerdeEsquerda() {
  RGB cor = lerCor();
  
  return (cor.r >= VERDE_MIN_R && cor.r <= VERDE_MAX_R &&
          cor.g >= VERDE_MIN_G && cor.g <= VERDE_MAX_G &&
          cor.b >= VERDE_MIN_B && cor.b <= VERDE_MAX_B);
}

void calibrarSensorCor() {
  Serial.begin(9600);
  while(!Serial); // Para Arduino Leonardo/Micro
  
  Serial.println("Coloque o sensor sobre o verde e pressione qualquer tecla");
  while(!Serial.available());
  Serial.read(); // Limpa o buffer
  
  RGB verde = lerCor();
  // Atualiza os valores de calibração (você pode querer armazenar em EEPROM)
  // VERDE_MIN_R = verde.r - 20;
  // VERDE_MAX_R = verde.r + 20;
  // ... (e assim por diante para outros valores)
  
  Serial.println("Calibração concluída:");
  Serial.print("Verde R: "); Serial.println(verde.r);
  Serial.print("Verde G: "); Serial.println(verde.g);
  Serial.print("Verde B: "); Serial.println(verde.b);
}