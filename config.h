#ifndef CONFIG_H
#define CONFIG_H

/************************
 * DEFINIÇÕES DE PINOS *
 ************************/

// Sensores de linha infravermelhos
#define SENSOR_ESQUERDO A0
#define SENSOR_DIREITO A1

// Sensor ultrassônico
#define TRIGGER_PIN 12
#define ECHO_PIN 11
#define MAX_DISTANCE 200  // em cm

// Motores
#define MOTOR_ESQUERDO_FRENTE 5
#define MOTOR_ESQUERDO_TRAS 6
#define MOTOR_DIREITO_FRENTE 9
#define MOTOR_DIREITO_TRAS 10

// Sensor de cor TCS230/320
#define SENSOR_COR_S0 2
#define SENSOR_COR_S1 3
#define SENSOR_COR_S2 4
#define SENSOR_COR_S3 7
#define SENSOR_COR_OUT 8

/**************************
 * PARÂMETROS DE CONTROLE *
 **************************/

// Seguidor de linha
#define LIMIAR 500          // Valor limite para detectar linha preta
#define TEMPO_BUSCA_LINHA 200 // ms para procurar linha quando perdida

// Obstáculos
#define DISTANCIA_OBSTACULO 15 // cm

// Velocidades
#define VELOCIDADE_NORMAL 150  // PWM (0-255)
#define VELOCIDADE_CURVA 200   // PWM para curvas
#define VELOCIDADE_RE 100      // PWM para ré

// Detecção de cores (valores devem ser calibrados)
#define VERDE_MIN_R 0
#define VERDE_MAX_R 100
#define VERDE_MIN_G 150
#define VERDE_MAX_G 255
#define VERDE_MIN_B 0
#define VERDE_MAX_B 100

// Curvas
#define TEMPO_CURVA_90 800     // ms para curva de 90 graus

#endif