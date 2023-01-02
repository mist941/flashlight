#include <Arduino.h>

short int red_status = 0;
short int yelow_status = 0;
short int green_status = 0;
short int counter = 0;

void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(7, OUTPUT);
  red_status = 1;
  digitalWrite(13, HIGH);
}

void loop() {
  if (red_status == 1)
  {
    if (counter == 10)
    {
      counter = 0;
      red_status = 2;
      digitalWrite(13, LOW);
    }
    delay(1000);
    counter +=1;
  }

  if (red_status == 2)
  {
    if (counter == 3)
    {
      counter = 0;
      red_status = 0;
      digitalWrite(13, LOW);
      delay(500);
      digitalWrite(12, HIGH);
      yelow_status = 1;
    }else{
      digitalWrite(13, HIGH);
      delay(500);
      digitalWrite(13, LOW);
      delay(500);
      counter +=1;
    }
  }
  
  if (yelow_status == 1)
  {
    if (counter == 2)
    {
      counter = 0;
      yelow_status = 0;
      digitalWrite(12, LOW);
      delay(500);
      digitalWrite(7, HIGH);
    }
    delay(1000);
    counter +=1;
  }
}