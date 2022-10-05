#include<Servo.h>
Servo s;
void setup()
{
  Serial.begin(9600);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(2,INPUT);
  s.attach(3);
}
void loop()
{
  int a=digitalRead(2);
  double b=analogRead(A0);
  double c=(((b/1024)*5)-0.5)*100;
  s.write(0);
  digitalWrite(13,LOW);
  if(a)                           
  {
    Serial.println("Human Arrived,door open ");
    tone(12,100);
    delay(200);
    noTone(12);
    if(c>37)                       
    {
      digitalWrite(13,HIGH);      
      delay(1000);
      tone(12,1000);
      delay(50);
      noTone(12);
      Serial.print("The Body temperature is :");
      Serial.println(c);
      Serial.println("WARNING : Body temperature is higher than normal body temperature!");
      Serial.println("So,You are not allowed!!!");
      s.write(0);
    }
    else
    {
      digitalWrite(13,LOW);
      Serial.print("The Body temperature is :");
      Serial.println(c);
      Serial.println("Normal body temperature .So, Door is opening");
      for(int i=0;i<180;i++)        //Door opening
      {
        s.write(i);
        delay(10);
      }
    }
    delay(1000);
  }
}
    
   

  