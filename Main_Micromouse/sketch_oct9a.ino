#include <SharpIR.h>
#include <MPU9250.h>
#include "STATIC_SCAN_FUNCS.ino"




// ir: the pin where your sensor is attached, A0 por ejemplo
// model: an int that determines your sensor:  1080 for GP2Y0A21Y
//                                            20150 for GP2Y0A02Y
//                                            (working distance range according to the datasheets)



MPU9250 mpu; //crea el objeto de giroscopio



void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
    Wire.begin();
    delay(2000);

    if (!mpu.setup(0x68)) {  // change to your own address
        while (1) {
            Serial.println("MPU connection failed");
            delay(5000);
        }
    }
}

void loop() {
    

  static unsigned long pepe1=millis();  // toma el tiempo justo cuando inicia el loop, es necesario para que funcione la libreria
  int dis=SharpIR_front.distance();  // esta funcion retorna la distancia medida (la guarda en dis)
  
  if (mpu.update()) {
        static uint32_t prev_ms = millis();
        if (millis() > prev_ms + 25) {
            
            prev_ms = millis();
        }
    }//este if actualiza los datos del mpu cada milisegundo
  /*funciones para obtener estos datos
  mpu.getRoll();//rotacion de la nariz sin moverla de lado a lado ni arriba abajo 
  mpu.getPitch();//nariz olfateando, moviendose hacia arriba y abajo
  mpu.getYaw();//nariz moviendo lado a lado //usar este para saber si el robot gira sobre su eje
  */

}




/*
  Serial.println(pepe2); 
  Serial.print("Mean distance: ");  // returns it to the serial monitor
  Serial.println(dis);
  
  unsigned long pepe2=millis()-pepe1;  // the following gives you the time taken to get the measurement
  Serial.print("Time taken (ms): ");
  */