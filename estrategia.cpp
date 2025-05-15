
#include "config.h"
#include "motores.h"
#include "sensores.h"
#include "estrategia.h"
#include <Arduino.h>

void executarEstrategia() {
  unsigned int distancia = lerDistanciaObstaculo();
  
  if (distancia > 0 && distancia < DISTANCIA_OBSTACULO) {
    desviarObstaculo();
  } else {
    seguirLinha();
  }
}

void seguirLinha() {
  int valorEsquerdo = lerSensorEsquerdo();
  int valorDireito = lerSensorDireito();
  
  if (valorEsquerdo > LIMIAR && valorDireito > LIMIAR) {
    moverFrente();
  }
  else if (valorEsquerdo > LIMIAR) {
    virarEsquerda();
  }
  else if (valorDireito > LIMIAR) {
    virarDireita();
  }
  else {
    procurarLinha();
  }
}

void desviarObstaculo() {
  pararMotores();
  delay(1000);
  // Implemente aqui sua estratégia de desvio
}