#include <SharpIR.h>
#include <MPU9250.h>
#define model 20150

SharpIR SharpIR_front(A0, model);  //crea el objeto sensor
SharpIR SharpIR_left(A1, model);
SharpIR SharpIR_right(A2, model);

typedef enum {
  E_FINAL_LABERINTO,
  E_ORIENTATION_SCAN,
  E_OMNI_IR_SCAN,
  E_RECON_EEPROM,
  E_SAVE_EEPROM,
  E_CLASSIFY_NXT_MOVE,
  E_END_STATE_MACHINE,
} ESTADOS_STATIC_SCAN;

ESTADOS_STATIC_SCAN final_laberinto();
ESTADOS_STATIC_SCAN orientation_scan();
ESTADOS_STATIC_SCAN omni_ir_scan();
ESTADOS_STATIC_SCAN recon_eeprom();
ESTADOS_STATIC_SCAN save_eeprom();
ESTADOS_STATIC_SCAN classify_nxt_move();
ESTADOS_STATIC_SCAN end_state_machine();
void init_scan_estatico();
static ESTADOS_STATIC_SCAN estado_actual_SC = E_ORIENTATION_SCAN;
static ESTADOS_STATIC_SCAN estado_aux_SC = E_ORIENTATION_SCAN;

void init_scan_estatico() {
  switch (estado_actual_SC)
  case E_FINAL_LABERINTO:
    estado_actual_SC = final_laberinto();
  break;
  case E_ORIENTATION_SCAN:
    estado_actual_SC = orientation_scan();
    break;
  case E_OMNI_IR_SCAN:
    estado_actual_SC = omni_ir_scan();
    break;
  case E_RECON_EEPROM:
    estado_actual_SC = recon_eeprom();
    break;
  case E_SAVE_EEPROM:
    estado_actual_SC = save_eeprom();
    break;
  case E_CLASSIFY_NXT_MOVE:
    estado_actual_SC = classify_nxt_move();
    break;
  case E_END_STATE_MACHINE:
    estado_actual_SC = end_state_machine();
    break;
  default:
    estado_actual_SC = final_laberinto();
    break;
}

bool comprobar_finalizacion() {
  QUESTION pregunta = SIN_RESPONDER;
  while (pregunta == 0);
  pregunta = 1;
  if (pregunta == 1) return CONTINUAR;
  if (pregunta == 2) return FINALIZADO;
}
ESTADOS_STATIC_SCAN final_laberinto()
{

}
ESTADOS_STATIC_SCAN orientation_scan()
{

}
ESTADOS_STATIC_SCAN omni_ir_scan()
{

}
ESTADOS_STATIC_SCAN recon_eeprom()
{

}
ESTADOS_STATIC_SCAN save_eeprom()
{

}
ESTADOS_STATIC_SCAN classify_nxt_move()
{

}
ESTADOS_STATIC_SCAN end_state_machine()
{
  
}