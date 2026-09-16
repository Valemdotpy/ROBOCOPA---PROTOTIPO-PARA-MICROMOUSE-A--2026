typedef enum{
  apagado,
  en_espera,
  amarillo,
  verde,
  rojo
}ejemplo_estados;

typedef struct
{
  ejemplo_estados estado;
  char logs_string[20];
  bool on_off;
}LED_emision_1;

ejemplo_estados maquina(LED_emision_1 objeto_actual);//no olvidar el prototipo, el compilador jode todo cuando hay structs y enums

ejemplo_estados maquina(LED_emision_1 objeto_actual)//led emision 1 es el tipo de variable (struct)
{                                                     //objeto actual es el nombre de la nueva variable
//por que esta dentro de los parametros? para que se pueda relacionar con una variable de otro codigo, es decir cuando llamas
//la funcion se puede poner dentro de los parametros el estado actual de la funcion
  switch (objeto_actual.estado) //objeto_actual es la variable que creamos, el punto indica que variables 
                                //se van a usar y estado es la variable ENUM en la que se puede escribir los estados
    {
      case apagado:
        
        objeto_actual.estado=en_espera; //cambia el estado del objeto a en_espera

        delay(200);
        break;

      case en_espera:
        
        objeto_actual.estado=verde;

        delay(200);
        break;
      case verde:
        
        objeto_actual.estado=apagado;

        delay(200);
        break;
      default:
        // statements
        break;
    }
  return objeto_actual.estado; //retorna el estado actual del objeto
}
