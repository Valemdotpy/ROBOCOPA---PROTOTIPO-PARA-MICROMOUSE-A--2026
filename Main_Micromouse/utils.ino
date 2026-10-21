typedef enum
{
  SIN_RESPONDER,
  CONTINUAR,
  FINALIZADO,
}QUESTION;
bool comprobar_finalizacion();

bool comprobar_finalizacion()
{
  QUESTION pregunta = SIN_RESPONDER;
  while(pregunta==0);
  pregunta = 1;
  if(pregunta==1) return CONTINUAR;
  if(pregunta==2) return FINALIZADO;
}
const uint8_t trigPin = 9;
const uint8_t echoPin = 10;

long duration;
int  distance;

void dist_med_cm()
{
   digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,  HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration  = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2;
  
}
