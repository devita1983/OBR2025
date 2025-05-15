
// FALAE MOLECADA, DEIXARAM VCS NA MÃO? TA VENDO COMO FAZ FALTA UM PROFISSIONAL GABARITADO? KKKK ZOERA! 

#include "config.h"
#include "motores.h"
#include "sensores.h"
#include "estrategia.h"

void setup() {
  // Inicializa todos os sensores
  configurarSensores();
  configurarSensorCor();
  
  // Inicializa motores
  configurarMotores();
  
  // Inicia parado (regras OBR)
  pararMotores();
  
  // Aguarda 2 segundos ou até botão ser pressionado
  delay(2000);
  
  // Calibração opcional (remover na competição)
  // calibrarSensorCor();
}

void loop() {
  executarEstrategia();
}