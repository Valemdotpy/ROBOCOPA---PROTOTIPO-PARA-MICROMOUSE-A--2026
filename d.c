int const leds[] = { 2, 3, 4, 5, 6, 7, 8, 9};
int const ledscant = 8;

void setup()
{
  int i;
  for (i = 0; i <8 ; i++)
  {
    pinMode(leds[i], OUTPUT);
  }
  pinMode(11, INPUT);
  pinMode(12, INPUT);
  pinMode(13, INPUT);
}

void loop()
{
  int i = 0;
  for (int i = 0; i < ledscant; i++)
            {
              digitalWrite(leds[i], LOW);
            }
  while (digitalRead(11) == HIGH)
  {
    for (i = 0; i <= ledscant; i++)
    {
      digitalWrite(leds[i], HIGH);
      delay(2000);
    }
    if (i>=8)
      {
        for (int i = 0; i < ledscant; i++)
        {
          digitalWrite(leds[i], LOW);
        }
      }
  }
  
 while (digitalRead(12) == HIGH)
  {
    for (int i = 0; i < ledscant; i++)
    {
      digitalWrite(leds[i], LOW);
    }
    delay(3000);
    for (int i = 0; i < 4; i++)
    {
      digitalWrite(leds[i], HIGH);
    }
    delay(3000);
     for (int i = 4; i < 8; i++)
    {
      digitalWrite(leds[i], HIGH);
    }
    delay(3000);
     for (int i = 0; i < ledscant; i++)
    {
      digitalWrite(leds[i], HIGH);
    }
  if (i==8)
      {
        for (int i = 0; i < ledscant; i++)
        {
          digitalWrite(leds[i], LOW);
        }
        
      }
  }

  
       while (digitalRead(13) == HIGH)
          {
         for (int i = 0; i < ledscant; i++)
            {
              digitalWrite(leds[i], HIGH);
            }
          }
          
          
  
  
}