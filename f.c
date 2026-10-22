#pragma config WDTE=OFF 
#include <xc.h>
#include "xc8_config.h"
#define _XTAL_FREQ 4E6
#define s1 RB0
#define s2 RB1


void configuracion();
void principal();

uint8_t secini();
uint8_t sec1();
uint8_t sec2();
uint8_t sec3();



void main(void) 
{
    configuracion();
    principal();
    
    return;
}

void configuracion()
{
    ANSEL=0;
    ANSELH=0;
    TRISB=0B00000011;
    
    LCD lcd={&PORTD,2,3,4,5,6,7};
    lcd_init(lcd);
}

void principal()
{
    uint8_t estados=0;
    
    while(1)
    {
        switch(estados)
        {
            case 0:
                estados=secini();
                break;
            case 1:
                estados=sec1();
                break;
            case 2:
                estados=sec2();
                break;
            case 3:
                estados=sec3();
                break;
                
                      
        }
        
    }
}

uint8_t secini()
{
  uint8_t estado_actual=0;
  lcd_out(0,0,"Personas en sala");
  lcd_out(1,0,"esperando usuario");
  lcd_out(2,0,"s1=0, s2=0");
  if(s1==1 && s2==0) estado_actual=1;
 
  return estado_actual;
}

uint8_t sec1()
{
    uint8_t estado_actual=1;
    lcd_out(1,0,"Detectado s1!    ");
    lcd_out(2,0,"s1=1, s2=0");
    if(s1==0 && s2==0) estado_actual=2;
    return estado_actual;
}

uint8_t sec2()
{
    uint8_t estado_actual=2;
    lcd_out(1,0,"Entre s1 y s2 ");
    lcd_out(2,0,"s1=0, s2=0");
    
    if(s1==0 && s2==1) estado_actual=3;
    return estado_actual;
  
}
char aux[10];

uint8_t sec3()
{
    uint8_t estado_actual=3;
    
    
    static uint8_t personas=0;
    
    lcd_out(1,0,"ingreso persona ");
    lcd_out(2,0,"s1=0, s2=1");
    
    sprintf(aux,"Contadas: %d",personas);
    lcd_out(3,0,aux);
    
    if(s1==0 && s2==0) 
    {
        personas++;
        estado_actual=0;
        lcd_cmd(_LCD_CLEAR);
    }
    return estado_actual;
    
    
}