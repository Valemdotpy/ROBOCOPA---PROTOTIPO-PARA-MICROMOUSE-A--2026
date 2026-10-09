#include <Wire.h>
#include <Arduino.h>
#include <L293D.h>

#define MOTOR_A      16   // motor pin a
#define MOTOR_B      15   // motor pin b
#define MOTOR_ENABLE 14   // Enable (also PWM pin)
/*
 * 
0 0 0 Girar derecha
0 0 1 Girar derecha 
0 1 0 Girar derecha
0 1 1 Girar derecha
1 0 0 Avanzar
1 0 1 Avanzar
1 1 0 Girar izquierda
1 1 1 Media vuelta
*/
enum ModoRobot {
  RUMBO_RECTO,
  SIGUIENDO_PARED
};
L293D motor(MOTOR_A, MOTOR_B, MOTOR_ENABLE);

void setup() {
  // Inicializar la comunicación serial
  Serial.begin(9600);


  
  // Configurar los pines de los sensores como entradas
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  
   // begin --> true false, enables disables PWM
    motor.begin(true);
    // Speed -100%...0..100%
   // motor.SetMotorSpeed(50); la wea de la potencia de los motores 
}

void loop() {
  // Leer el estado digital de cada sensor
  // high objeto xd y low no objeto :0
  int estzq = digitalRead(sensorIzquierdo);
  int estCen = digitalRead(sensorCentro);
  int estDer = digitalRead(sensorDerecho);

  // Mostrar los valores en el Monitor Serial
  Serial.print("Izq: ");
  Serial.print(estIzq);
  Serial.print(" | Cen: ");
  Serial.print(estCen);
  Serial.print(" | Der: ");
  Serial.println(estDer);

  // Lógica básica de navegación para el laberinto
  if (estIzq && estDer== LOW && estCen==HIGH) {
    // Obstáculo al Pasillo: adelante
    Serial.println("PASILLO, continue derecho");
    
  } else if (estIzq && estDer && estCen==HIGH) {
    // CAMINO SIN SALIDA: VOLVER ATRAS
    Serial.println("CAMINO SIN SAL  IDA");
  } else if (estDer == LOW) {
    // Obstáculo a la derecha
    Serial.println("Pared a la derecha.");
  } else if (estDer == LOW) {
    // Obstáculo a la derecha
    Serial.println("Pared a la derecha.");
  } 

  delay(100); // Pequeña pausa para estabilizar lecturas
}
