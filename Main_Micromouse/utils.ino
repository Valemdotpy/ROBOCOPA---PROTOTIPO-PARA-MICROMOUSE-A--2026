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